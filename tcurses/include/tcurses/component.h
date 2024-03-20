/**
 * @file component.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Contiene la definición de la clase Component, que representa un componente gráfico.
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <memory>
#include <list>

namespace TCurses {

/**
 * @brief La clase Component representa un componente básico de la interfaz de usuario.
 *        Puede ser un contenedor para otros componentes o un elemento visual en sí mismo.
 */
class Component {
public:

	/**
	 * @brief Enumeradores para alineación en general.
	 * 
	 */
	enum VAlign {VA_TOP, VA_CENTER, VA_BOTTOM};
	enum HAlign {HA_LEFT, HA_CENTER, HA_RIGHT};

	/**
	 * @brief Constructor predeterminado de Component.
	 */
	Component();

	/**
	 * @brief Constructor de Component que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Component(const short x, const short y);

	/**
	 * @brief Constructor de Component que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del componente.
	 * @param h La altura inicial del componente.
	 */
	Component(const short x, const short y, const short w, const short h);

	/**
	 * @brief Obtiene la coordenada x del componente.
	 * @return La coordenada x del componente.
	 */
	const short getX() const { return x; }

	/**
	 * @brief Establece la coordenada x del componente.
	 * @param x La nueva coordenada x del componente.
	 */
	void setX(const short x) { this->x = x; }

	/**
	 * @brief Obtiene la coordenada y del componente.
	 * @return La coordenada y del componente.
	 */
	const short getY() const { return y; }

	/**
	 * @brief Establece la coordenada y del componente.
	 * @param y La nueva coordenada y del componente.
	 */
	void setY(const short y) { this->y = y; }

	/**
	 * @brief Obtiene el ancho del componente.
	 * @return El ancho del componente.
	 */
	const short getW() const { return w; }

	/**
	 * @brief Establece el ancho del componente.
	 * @param w El nuevo ancho del componente.
	 */
	void setW(const short w) { this->w = w; }

	/**
	 * @brief Obtiene la altura del componente.
	 * @return La altura del componente.
	 */
	const short getH() const { return h; }

	/**
	 * @brief Establece la altura del componente.
	 * @param h La nueva altura del componente.
	 */
	void setH(const short h) { this->h = h; }

	/**
	 * @brief Establece la posición del componente.
	 * @param x La nueva coordenada x del componente.
	 * @param y La nueva coordenada y del componente.
	 */
	void setPos(const short x, const short y) { this->x = x; this->y = y;}

	/**
	 * @brief Establece el tamaño del componente.
	 * @param w El nuevo ancho del componente.
	 * @param h La nueva altura del componente.
	 */
	void setSize(const short w, const short h) { this->h = h; this->w = w;}

	/**
	 * @brief Devuelve la coordenada x sumada con la del componente padre.
	 * 
	 * @return const short La coordenada x absoluta.
	 */
	const short getAbsX() const;

	/**
	 * @brief Devuelve la coordenada y sumada con la del componente padre.
	 * 
	 * @return const short La coordenada y absoluta.
	 */
	const short getAbsY() const;

	/**
	 * @brief Obtiene el componente padre.
	 * @return Un puntero al componente padre.
	 */
	const Component *getParent() { return parent; }

	/**
	 * @brief Obtiene la lista de hijos del componente.
	 * @return Una lista de punteros a los componentes hijos.
	 */
	const std::list<std::shared_ptr<Component>> getChildren() { return children; }

	/**
	 * @brief Agrega un componente hijo.
	 * @param child Un puntero compartido al componente hijo a agregar.
	 */
	void addChild(std::shared_ptr<Component> child);

protected:

	/**
	 * @brief Virtual para dibujar el componente
	 * 
	 */
	virtual void draw() = 0;

	/**
	 * @brief Ejecuta draw() y luego dibuja los hijos.
	 * 
	 */
	void internalDraw();

private:

	short x, y, w, h; /**< Coordenadas x, y y dimensiones del componente */
	Component *parent; /**< Puntero al componente padre */
	std::list<std::shared_ptr<Component>> children; /**< Lista de punteros a los componentes hijos */
};

} // namespace TCurses
