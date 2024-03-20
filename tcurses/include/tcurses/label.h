/**
 * @file label.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente Label de la interfaz de usiario. Contiene texto modificable para
 * ser mostrado.
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <tcurses/component.h>

#include <string>

namespace TCurses {

/**
 * @brief Componente básico de texto. Es estático pero se puede restablecer.
 * 
 */
class Label : public Component {
public:
	/**
	 * @brief Constructor predeterminado de Label.
	 * 
	 */
	Label();

	/**
	 * @brief Constructor de Label que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Label(const short x, const short y);

	/**
	 * @brief Constructor de Label que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del componente.
	 * @param h La altura inicial del componente.
	 */
	Label(const short x, const short y, const short w, const short h);

	/**
	 * @brief Constructor de Label que establece el texto inicial.
	 * @param text El texto inicial del Label.
	 */
	Label(const std::string text);

	/**
	 * @brief Constructor de Label que establece el texto inicial y la posición.
	 * @param text El texto inicial del Label.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Label(const std::string text, const short x, const short y);

	/**
	 * @brief Constructor de Label que establece el texto inicial, la posición y el tamaño.
	 * @param text El texto inicial del Label.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del componente.
	 * @param h La altura inicial del componente.
	 */
	Label(const std::string text, const short x, const short y, const short w, const short h);

	/**
	 * @brief Establece el texto del Label.
	 * 
	 * @param text texto del Label.
	 */
	void setText(const std::string text) { this->text = text; }

	/**
	 * @brief Devuelve el texto del Label.
	 * 
	 * @return std::string texto del Label.
	 */
	std::string getText() const { return text; }

	/**
	 * @brief Dibuja el Label.
	 * 
	 */
	void draw() const override;

private:

	/**
	 * @brief Texto del Label;
	 * 
	 */
	std::string text{};
};

}
