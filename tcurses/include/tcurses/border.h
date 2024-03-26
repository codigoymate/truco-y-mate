/**
 * @file border.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Archivo de cabecera que contiene las definiciones de clases para los bordes en la biblioteca TCurses.
 * @date 2024-03-24
 * 
 * Este archivo define las clases Border, EmptyBorder y LinedBorder utilizadas para representar diferentes tipos de bordes alrededor de un componente en la biblioteca TCurses.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <memory>

namespace TCurses {

class Component;

/**
 * @brief La clase Border es una clase base abstracta que define la interfaz para los diferentes tipos de bordes.
 */
class Border {
public:
	/**
	 * @brief Constructor predeterminado de Border.
	 */
	Border() : Border(0) {}

	/**
	 * @brief Constructor de Border que establece la posición del borde.
	 * @param pos La posición del borde.
	 */
	Border(const short pos) { this->pos = pos; }

	/**
	 * @brief Función virtual pura para dibujar el borde.
	 */
	virtual void draw() const = 0;

	/**
	 * @brief Establece el componente asociado al borde.
	 * @param comp Un puntero al componente asociado al borde.
	 */
	void setComponent(Component *comp) { this->comp = comp; }

protected:
	Component *comp; /**< Puntero al componente asociado al borde. */
	short pos;       /**< Posición del borde. */
};

/**
 * @brief La clase EmptyBorder representa un borde vacío sin contenido.
 */
class EmptyBorder: public Border {
public:
	/**
	 * @brief Constructor predeterminado de EmptyBorder.
	 */
	EmptyBorder() : Border() {}

	/**
	 * @brief Constructor de EmptyBorder que establece la posición del borde.
	 * @param pos La posición del borde.
	 */
	EmptyBorder(const short pos) : Border(pos) {}

	/**
	 * @brief Función para dibujar el borde. No realiza ninguna operación ya que el borde está vacío.
	 */
	void draw() const override {}
};

/**
 * @brief La clase LinedBorder representa un borde formado por líneas.
 */
class LinedBorder: public Border {
public:
	/**
	 * @brief Constructor predeterminado de LinedBorder.
	 */
	LinedBorder() : Border() {}

	/**
	 * @brief Constructor de LinedBorder que establece la posición del borde.
	 * @param pos La posición del borde.
	 */
	LinedBorder(const short pos) : Border(pos) {}

	/**
	 * @brief Función para dibujar el borde. Dibuja un borde formado por líneas.
	 */
	void draw() const override;
};

} // namespace TCurses
