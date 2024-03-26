/**
 * @file component.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de la clase Component.
 * @date 2024-03-19
 * 
 * Contiene la implementación de las funciones miembro de la clase Component.
 * La clase Component representa un componente gráfico y se encarga de gestionar su posición,
 * tamaño y relaciones jerárquicas con otros componentes.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tcurses/component.h>
#include <tcurses/border.h>

namespace TCurses {

/**
 * @brief Constructor de la clase Component con posición y tamaño inicial.
 * @param x La posición horizontal inicial del componente.
 * @param y La posición vertical inicial del componente.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
Component::Component(const short x, const short y, const short w, const short h)
	: x(x), y(y), w(w), h(h) {	
	this->parent = nullptr;
	this->minH = 1;
	this->minW = 1;
	this->maxH = 30000;
	this->maxW = 30000;

	border = std::make_shared<EmptyBorder>();
	border->setComponent(this);
}

/**
 * @brief Constructor de la clase Component con posición inicial.
 * @param x La posición horizontal inicial del componente.
 * @param y La posición vertical inicial del componente.
 */
Component::Component(const short x, const short y) : Component(x, y, 10, 1) {}

/**
 * @brief Constructor por defecto de la clase Component.
 */
Component::Component() : Component(0, 0) {}

/**
 * @brief Devuelve la coordenada x sumada con la del componente padre.
 * 
 * @return const short La coordenada x absoluta.
 */
const short Component::getAbsX() const {
	if (parent == nullptr) return x;
	else return parent->getAbsX() + x;
}

/**
 * @brief Devuelve la coordenada y sumada con la del componente padre.
 * 
 * @return const short La coordenada y absoluta.
 */
const short Component::getAbsY() const {
	if (parent == nullptr) return y;
	else return parent->getAbsY() + y;
}

/**
 * @brief Establece el borde.
 * 
 * @param border el borde.
 */
void Component::setBorder(std::shared_ptr<Border> border) {
	this->border = border;
	this->border->setComponent(this);
}

/**
 * @brief Añade un componente hijo al componente actual.
 * @param child El componente hijo a añadir.
 */
void Component::addChild(std::shared_ptr<Component> child) {
	this->children.push_back(child);
	child->application = this->application;
	child->parent = this;
}

/**
 * @brief Elminina un componente hijo por referencia.
 * @param child Componente hijo.
 */
void Component::removeChild(std::shared_ptr<Component> child) {
	children.remove_if([&](std::shared_ptr<Component> c) {
		return child == c;
	});
}

/**
 * @brief Ejecuta draw() y luego dibuja los hijos.
 * 
 */
void Component::internalDraw() {
	draw();

	if (layout != LY_ABSOLUTE) doBoxLayout();

	for (auto &c : children) {
		c->internalDraw();
	}
}

/**
 * @brief Realiza los ajustes box layout.
 * 
 */
void Component::doBoxLayout() {
	if (layout == LY_VERTICAL) doBoxVertical();
	else doBoxHorizontal();
}

/**
 * @brief Realiza los ajustes verticales box layout.
 * 
 */
void Component::doBoxVertical() {

	// Establece los anchos
	for (auto &c : children) {
		c->setW(w);
		if (c->getW() > c->getMaxW()) {
			c->setW(c->getMaxW());
		}
		if (c->getW() < c->getMinW()) {
			c->setW(c->getMinW());
		}
	
		// Alinea horizontalmente cada componente
		switch (c->getHAlign()) {
		case Component::HA_LEFT:
			c->setX(0);
			break;
		case Component::HA_RIGHT:
			c->setX(w - c->getW());
			break;
		case Component::HA_CENTER:
			c->setX(w / 2 - c->getW() / 2);
		}
	}

	// Establece los minimos
	for (auto &c : children) c->setH(c->getMinH());

	// Si ya es lo suficiente alto, continua.
	if (h > getTotalHeightBox()) {

		// Incrementa los H de los componentes de a uno 
		//    hasta completar el alto del padre.
		while (h > getTotalHeightBox()) {
			if (!addOneToSmallVBox()) break ;
		}
	}

	// Establece las Y
	short y = 0;
	for (auto &c : children) {
		c->setY(y); y += c->getH();
	}
 }

/**
 * @brief Realiza los ajustes horizontales box layout.
 * 
 */
void Component::doBoxHorizontal() {
	// Establece los altos
	for (auto &c : children) {
		c->setH(h);
		if (c->getH() > c->getMaxH()) {
			c->setH(c->getMaxH());
		}
		if (c->getH() < c->getMinH()) {
			c->setH(c->getMinH());
		}
		
		// Alinea verticalmente cada componente
		switch (c->getVAlign()) {
		case Component::VA_TOP:
			c->setY(0);
			break;
		case Component::VA_BOTTOM:
			c->setY(h - c->getH());
			break;
		case Component::VA_CENTER:
			c->setY(h / 2 - c->getH() / 2);
		}
	}

	// Establece los minimos
	for (auto &c : children) c->setW(c->getMinW());

	// Si ya es lo suficiente ancho, cancela.
	if (w > getTotalWidthBox()) {

		// Incrementa los W de los componentes de a uno 
		//    hasta completar el ancho del padre.
		while (w > getTotalWidthBox()) {
			if (!addOneToSmallHBox()) break ;
		}
	}

	// Establece las X
	short x = 0;
	for (auto &c : children) {
		c->setX(x); x += c->getW();
	}
}

/**
 * @brief Devuelve la suma total de los altos de los componentes hijos.
 * 
 * @return const short la suma total de altos.
 */
const short Component::getTotalHeightBox() const {
	short total = 0;
	for (auto &c : children) {
		total += c->getH();
	}
	return total;
}

/**
 * @brief Devuelve la suma total de los anchos de los componentes hijos.
 * 
 * @return const short la suma total de anchos.
 */
const short Component::getTotalWidthBox() const {
	short total = 0;
	for (auto &c : children) {
		total += c->getW();
	}
	return total;
}

/**
 * @brief Suma 1 al componente mas chico (en ancho).
 * En el caso de que se haya llegado al máximo, lo deja como está.
 * 
 * @return true Si se pudo agregar 1 al mas chico.
 * @return false Si no pudo agregar 1 a ningún componente.
 */
const bool Component::addOneToSmallHBox() const {
	std::shared_ptr<Component> small;
	short max = 20000;
	bool smallFound = false;

	for (auto &c : children) {
		if (c->getW() < max) {
			if (c->getW() == c->getMaxW()) continue;
			small = c; max = c->getW();
			smallFound = true;
		}
	}

	if (smallFound) small->setW(small->getW() + 1);

	return smallFound;
}

/**
 * @brief Suma 1 al componente mas chico (en alto).
 * En el caso de que se haya llegado al máximo, lo deja como está.
 * 
 * @return true Si se pudo agregar 1 al mas chico.
 * @return false Si no pudo agregar 1 a ningún componente.
 */
const bool Component::addOneToSmallVBox() const {
	std::shared_ptr<Component> small;
	short max = 20000;
	bool smallFound = false;

	for (auto &c : children) {
		if (c->getH() < max) {
			if (c->getH() == c->getMaxH()) continue;
			small = c; max = c->getH();
			smallFound = true;
		}
	}

	if (smallFound) small->setH(small->getH() + 1);

	return smallFound;
}

} // namespace TCurses
