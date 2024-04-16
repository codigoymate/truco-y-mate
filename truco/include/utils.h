/**
 * @file utils.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Definición de algunas utilidades.
 * @date 2024-04-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>

namespace truco {

/**
 * @brief Elige y devuelve un nombre masculino aleatoriamente.
 * 
 * @return const std::string el nombre elegido.
 */
const std::string randomizeMaleName();

/**
 * @brief Elige y devuelve un nombre femenino aleatoriamente.
 * 
 * @return const std::string el nombre elegido.
 */
const std::string randomizeFemaleName();

} // namespace truco
