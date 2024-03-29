/**
 * @file menu.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente Menu de la interfaz de usiario. Contiene colección de items para
 * ser seleccionados.
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/component.h>
#include <tcurses/input_event.h>

namespace TCurses {

class Menu: public Component, public InputListener {
public:
	/**
	 * @brief Constructor predeterminado de Menu.
	 */
	Menu();

	/**
	 * @brief Constructor de Menu que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Menu(const short x, const short y);

	/**
	 * @brief Constructor de Menu que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del menu.
	 * @param h La altura inicial del menu.
	 */
	Menu(const short x, const short y, const short w, const short h);

	/**
	 * @brief Dibuja el menu.
	 * 
	 */
	void draw() override;

	/**
	 * @brief Escucha el teclado.
	 * 
	 * @param key tecla de entrada.
	 */
	void keyPressed(int key) override;

	/**
	 * @brief Actualiza el estado de los items;
	 * 
	 */
	void updateItems();

	/**
	 * @brief Override de addChild: actualiza los items después de agregar un item.
	 * 
	 * @param child componente a agregar.
	 */
	void addChild(std::shared_ptr<Component> child) override {
		Component::addChild(child);
		updateItems();
	}

	/**
	 * @brief Override de removeChild: actualiza los items después de quitar un item.
	 * 
	 * @param child componente a quitar.
	 */
	void removeChild(std::shared_ptr<Component> child) override {
		Component::removeChild(child);
		updateItems();
	}

private:
	int itemIndex{}; /**< El item seleccionado.*/

};

}
