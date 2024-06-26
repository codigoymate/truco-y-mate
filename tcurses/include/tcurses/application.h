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
#include <list>
#include <stack>

namespace TCurses {

class Screen;
class InputListener;
class Emergent;

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

	/**
	 * @brief Agrega un componente InputListener a los eventos de entrada.
	 * 
	 * @param listener Puntero compartido a componente InputListener.
	 */
	void addInputListener(std::shared_ptr<InputListener> listener);

	/**
	 * @brief Quita un componente InputListener de los eventos de entrada.
	 * 
	 * @param listener Puntero compartido a componente InputListener.
	 */
	void removeInputListener(std::shared_ptr<InputListener> listener);

	/**
	 * @brief Devuelve el objeto Screen de Application.
	 * 
	 * @return std::shared_ptr<Screen> Screen de application.
	 */
	std::shared_ptr<Screen> getScreen() { return screen; }

	/**
	 * @brief Finaliza la aplicación.
	 * 
	 */
	void quit() { running = false; }

	/**
	 * @brief Registra y muestra un Emergent.
	 * 
	 * @param e Emergent a mostrar.
	 */
	void showEmergent(std::shared_ptr<Emergent> e);

	/**
	 * @brief Elimina el último Emergent de Application.
	 * 
	 */
	void disposeEmergent();

protected:
	/**
	 * @brief Un puntero compartido al objeto Screen utilizado por la aplicación.
	 */
	std::shared_ptr<Screen> screen;

private:
	/**
	 * @brief Lista de componente que escuchan la entrada.
	 * 
	 */
	std::stack<std::list<std::shared_ptr<InputListener>>> inputListeners;

	std::list<std::shared_ptr<Emergent>> emergents;

	/**
	 * @brief Inicializa los colores utilizados por la aplicación.
	 *        Esta función configura la paleta de colores para la interfaz de la aplicación.
	 */
	void initColors();

	bool running; /**< Permanece en true mientras la aplicación esté corriendo.*/
};

} // namespace TCurses
