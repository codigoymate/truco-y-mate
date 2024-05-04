/**
 * @file emergent.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Frame emergente que la aplicación enfoca las entradas, pero la 
 * pantalla se sigue dibujando.
 * @version 0.1
 * @date 2024-05-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <tcurses/component.h>

namespace TCurses {

/**
 * @brief Componente Emergent, la aplicación enfoca la entrada
 * en el mismo pero la pantalla y sus hijos se siguen dibujando. Se utiliza para crear diálogos modales.
 * 
 */
class Emergent: public Component {
public:
	/**
	 * @brief Constructor de Emergent. El componente aparecerá centrado en la pantalla.
	 * 
	 * @param w ancho del Emergent.
	 * @param h alto del Emergent.
	 */
	Emergent(const short w, const short h);

	/**
	 * @brief Constructor de Emergent.
	 * 
	 * @param x Coordenada x del Emergent.
	 * @param y Coordenada y del Emergent.
	 * @param w ancho del Emergent.
	 * @param h alto del Emergent.
	 */
	Emergent(const short x, const short y, const short w, const short h);

	/**
	 * @brief Dibuja el emergent.
	 * 
	 */
	void draw() override;

	/**
	 * @brief Dibuja todos los componentes del Emergent.
	 * 
	 */
	void drawAll();

	/**
	 * @brief Actualiza todos los componentes del Emergent.
	 * 
	 */
	void updateAll();

	/**
	 * @brief Elimina el Emergent de Application y devuelve el foco a los
	 * elementos anteriores.
	 * 
	 */
	void dispose();

protected:
	bool centered{};
};

} // namespace TCurses
