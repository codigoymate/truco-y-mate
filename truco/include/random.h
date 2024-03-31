/**
 * @file random.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Genera números p-aleatorios.
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <random>

namespace truco {

/**
 * @brief Clase para generar números p-aleatorios.
 * 
 */
class Random {
public:
	/**
	 * @brief Devuelve un número entero p-aleatorio comprendido entre min y max.
	 * 
	 * @param min valor mínimo.
	 * @param max valor máximo.
	 * @return int el valor p-aleatorio.
	 */
	static int randInt(int min, int max);

	/**
	 * @brief Devuelve un número double p-aleatorio comprendido entre min y max.
	 * 
	 * @param min valor mínimo.
	 * @param max valor máximo.
	 * @return double el valor p-aleatorio.
	 */
	static double randDouble(double min, double max);

private:
	static std::default_random_engine generator; /**< Genedador p-aleatorio.*/
};

} // namespace truco
