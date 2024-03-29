/**
 * @file application.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Archivo de cabecera para la clase Application.
 *        Esta clase representa la lógica principal de la aplicación.
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <memory>

namespace TCurses {

class Screen;

/**
 * @brief La clase Application representa la lógica principal de la aplicación.
 */
class Application {
public:
	/**
	 * @brief Construye un nuevo objeto Application.
	 */
	Application();

	/**
	 * @brief Destruye el objeto Application.
	 */
	virtual ~Application() = default;

	/**
	 * @brief Inicializa la aplicación.
	 *        Esta función debe ser implementada por las clases derivadas.
	 */
	virtual void init() = 0;

	/**
	 * @brief Ejecuta la aplicación.
	 *        Esta función inicializa la aplicación y entra en el bucle principal.
	 */
	void run();

protected:
	/**
	 * @brief Un puntero compartido al objeto Screen utilizado por la aplicación.
	 */
	std::shared_ptr<Screen> screen;

private:
	/**
	 * @brief Inicializa los colores utilizados por la aplicación.
	 *        Esta función configura la paleta de colores para la interfaz de la aplicación.
	 */
	void initColors();
};

} // namespace TCurses
