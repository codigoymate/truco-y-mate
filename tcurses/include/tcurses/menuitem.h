/**
 * @file menuitem.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Definición de la clase MenuItem, que representa un elemento de Menu.
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <tcurses/label.h>

namespace TCurses {

/**
 * @brief Representa un elemento de menú.
 */
class MenuItem: public Label {
public:

	/**
	 * @brief Constructor predeterminado de MenuItem.
	 */
	MenuItem();

	/**
	 * @brief Constructor de MenuItem que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	MenuItem(const short x, const short y);

	/**
	 * @brief Constructor de MenuItem que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del componente.
	 * @param h La altura inicial del componente.
	 */
	MenuItem(const short x, const short y, const short w, const short h);

	/**
	 * @brief Constructor de MenuItem que establece el texto inicial.
	 * @param text El texto inicial del MenuItem::MenuItem.
	 */
	MenuItem(const std::string text);

	/**
	 * @brief Constructor de MenuItem que establece el texto inicial y la posición.
	 * @param text El texto inicial del MenuItem.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	MenuItem(const std::string text, const short x, const short y);

	/**
	 * @brief Constructor de MenuItem que establece el texto inicial, la posición y el tamaño.
	 * @param text El texto inicial del MenuItem.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del componente.
	 * @param h La altura inicial del componente.
	 */
	MenuItem(const std::string text, const short x, const short y,
		const short w, const short h);

	/**
	 * @brief Devuelve el color de texto cuando el item está seleccionado.
	 * @return const short color de texto.
	 */
	const short getSelTextPair() const { return selTextPair; }

	/**
	 * @brief Establece el color de texto del componente cuando el item está seleccionado.
	 * @param color nuevo color de texto.
	 */
	void setSelTextPair(const short pair) { selTextPair = pair; }

	/**
	 * @brief Devuelve el color de fondo cuando el item está seleccionado.
	 * @return const short color de fondo.
	 */
	const short getSelBGPair() const { return selBGPair; }

	/**
	 * @brief Establece el color de fondo del componente cuando el item está seleccionado.
	 * @param color nuevo color de fondo.
	 */
	void setSelBGPair(const short pair) { selBGPair = pair; }

	/**
	 * @brief Devuelve el color de borde cuando el item está seleccionado.
	 * @return const short color de borde.
	 */
	const short getSelBorderPair() const { return selBorderPair; }

	/**
	 * @brief Establece el color de borde del componente cuando el item está seleccionado.
	 * @param color nuevo color de borde.
	 */
	void setSelBorderPair(const short pair) { selBorderPair = pair; }

	/**
	 * @brief Obtiene el estado de selección del elemento de menú.
	 * @return true si el elemento está seleccionado, false en caso contrario.
	 */
	const bool getSelected() const { return selected; }

	/**
	 * @brief Establece el estado de selección del elemento de menú.
	 * @param sel true para seleccionar el elemento, false para deseleccionarlo.
	 */
	void setSelected(const bool sel) { this->selected = sel; }

	/**
	 * @brief Dibuja el MenuItem.
	 */
	void draw() override;

private:
	short selTextPair; ///< Color de texto cuando el item está seleccionado.
	short selBGPair;   ///< Color de fondo cuando el item está seleccionado.
	short selBorderPair; ///< Color de borde cuando el item está seleccionado.
	bool selected{}; ///< Estado de selección del elemento de menú.
};

} // namespace TCurses
