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
#include <tcurses/wrap.h>

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
	virtual void draw() override;

	/**
	 * @brief Obtiene el alineamiento horizontal del texto dentro del Label.
	 * @return El alineamiento horizontal del texto.
	 */
	const HAlign getHTextAlign() const { return hTextAlign; }

	/**
	 * @brief Establece el alineamiento horizontal del texto dentro del Label.
	 * @param align El alineamiento horizontal del texto a establecer.
	 */
	void setHTextAlign(const HAlign align) { hTextAlign = align; }

	/**
	 * @brief Obtiene el alineamiento vertical del texto dentro del Label.
	 * @return El alineamiento vertical del texto.
	 */
	const VAlign getVTextAlign() const { return vTextAlign; }

	/**
	 * @brief Establece el alineamiento vertical del texto dentro del Label.
	 * @param align El alineamiento vertical del texto a establecer.
	 */
	void setVTextAlign(const VAlign align) { vTextAlign = align; }

	/**
	 * @brief Establece el alineamiento del texto dentro del Label.
	 * @param hAlign El alineamiento horizontal del texto a establecer.
	 * @param vAlign El alineamiento vertical del texto a establecer.
	 */
	void setTextAlign(const HAlign hAlign, const VAlign vAlign) {
		hTextAlign = hAlign;
		vTextAlign = vAlign;
	}

	/**
	 * @brief Devuelve el color de texto.
	 * 
	 * @return const short color de texto.
	 */
	const short getTextPair() const { return textPair; }

	/**
	 * @brief Establece el color de texto del componente.
	 * 
	 * @param color nuevo color de texto.
	 */
	void setTextPair(const short pair) { textPair = pair; }

	/**
	 * @brief Devuelve el wrap del texto.
	 */
	const Wrap getWrap() const { return wrap; }

	/**
	 * @brief Establece el wrap del texto.
	 * 
	 * @param wrap wrap del texto.
	 */
	void setWrap(const Wrap wrap) { this->wrap = wrap; }
protected:

	/**
	 * @brief Texto del Label;
	 * 
	 */
	std::string text{};

	Wrap wrap{}; /**Wrapping del texto. */

	/**
	 * @brief Alineación de texto.
	 * 
	 */
	HAlign hTextAlign{};
	VAlign vTextAlign{};

	short textPair{}; /**< Color de texto. */
};

}
