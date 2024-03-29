/**
 * @file input_event.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Definición de la clase InputListener, para la entrada del teclado en componentes.
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

namespace TCurses {

/**
 * @brief Interfaz para escuchar eventos de entrada.
 */
class InputListener {
public:
    /**
     * @brief Método llamado cuando se presiona una tecla.
     * @param key La tecla que se ha presionado.
     */
    virtual void keyPressed(int key) = 0;
};

} // namespace TCurses
