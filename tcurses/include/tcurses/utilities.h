/**
 * @file utilities.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Funciones de utilidad para la biblioteca TCurses.
 * @date 2024-03-20
 * 
 * Este archivo contiene definiciones de funciones de utilidad para la biblioteca TCurses,
 * como la función `drawTextArea` que dibuja un área de texto con alineamiento horizontal y vertical.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <tcurses/component.h>

namespace TCurses {

/**
 * @brief Dibuja un área de texto con alineamiento horizontal y vertical.
 * @param text El texto a dibujar.
 * @param x1 La coordenada x del borde superior izquierdo del área.
 * @param y1 La coordenada y del borde superior izquierdo del área.
 * @param x2 La coordenada x del borde inferior derecho del área.
 * @param y2 La coordenada y del borde inferior derecho del área.
 * @param hAlign El alineamiento horizontal del texto dentro del área.
 * @param vAlign El alineamiento vertical del texto dentro del área.
 */
void drawTextArea(const std::string text,
                  const short x1, const short y1, const short x2, const short y2,
                  const Component::HAlign hAlign, const Component::VAlign vAlign);

/**
 * @brief Dibuja un rectángulo sólido con espacios.
 * 
 * @param x La coordenada x del borde superior izquierdo del rectángulo.
 * @param y La coordenada y del borde superior izquierdo del rectángulo.
 * @param w El ancho del rectángulo.
 * @param h El alto del rectángulo.
 */
void drawSolidRect(const short x, const short y, const short w, const short h);

} // namespace TCurses
