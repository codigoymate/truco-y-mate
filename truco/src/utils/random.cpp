/**
 * @file random.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación del módulo Random.
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <utils/random.h>

#include <chrono>

namespace truco {

/**
 * @brief Inicializa el generador p-aleatorio.
 * 
 */
std::default_random_engine Random::generator(std::chrono::system_clock::now().time_since_epoch().count());

/**
 * @brief Devuelve un número entero p-aleatorio comprendido entre min y max.
 * 
 * @param min valor mínimo.
 * @param max valor máximo.
 * @return int el valor p-aleatorio.
 */
int Random::randInt(int min, int max) {
	std::uniform_int_distribution<int> dist(min, max);
	return dist(generator);
}

/**
 * @brief Devuelve un número double p-aleatorio comprendido entre min y max.
 * 
 * @param min valor mínimo.
 * @param max valor máximo.
 * @return double el valor p-aleatorio.
 */
double Random::randDouble(double min, double max) {
	std::uniform_real_distribution<double> dist(min, max);
	return dist(generator);
}

} // namespace truco
