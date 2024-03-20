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
 * @brief Añade un componente hijo al componente actual.
 * @param child El componente hijo a añadir.
 */
void Component::addChild(std::shared_ptr<Component> child) {
	this->children.push_back(child);
	child->parent = this;
}

/**
 * @brief Ejecuta draw() y luego dibuja los hijos.
 * 
 */
void Component::internalDraw() const {
	draw();
	for (auto &c : children) {
		c->internalDraw();
	}
}

} // namespace TCurses
