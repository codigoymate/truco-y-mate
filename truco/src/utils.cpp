/**
 * @file utils.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de utils.h
 * @date 2024-04-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <utils.h>
#include <random.h>
#include <vector>

namespace truco {

/**
 * @brief Conjunto de nombres masculinos.
 * 
 */
const static std::vector<std::string> maleNames = {
	"Juan", "Carlos", "José", "Pablo", "Martín", "Alejandro", "Diego", "Lucas", "Fernando", "Gabriel", "Manuel", "Eduardo", "Agustín", "Nicolás", "Ignacio", "Federico", "Andrés", "Matías", "Facundo", "Germán", "Francisco", "Leandro", "Sebastián", "Marcos", "Emiliano", "Tomás", "Daniel", "Ramiro", "Gonzalo", "Juan Pablo", "Bruno", "Ariel", "Mauricio", "Hernán", "Leonardo", "Cristian", "Maximiliano", "Javier", "Ezequiel", "Roberto", "Raúl", "Osvaldo", "Adrián", "Claudio", "Darío", "Franco", "Facundo", "Mariano", "Alberto", "Sergio", "Julián", "Juan Manuel", "Juan José", "Eduardo", "Rafael", "Valentín", "Nicolás", "Ricardo", "Rodolfo", "Lucas", "Pedro", "Raúl", "Néstor", "Miguel Ángel", "Gonzalo", "Julio", "Marcelo", "Hernán", "Víctor", "Emilio", "Adrián", "Alberto", "Marcelo", "Ariel", "Rubén", "Luis", "Mario", "César", "Omar", "Juan Carlos", "Facundo", "Patricio", "Juan Cruz", "Diego", "Marcos", "Nicolás", "Fabricio", "Diego", "Juan Ignacio", "Esteban", "Federico", "Andrés", "Leandro", "Marcelo", "Gustavo", "Iván", "Hugo", "Leonardo", "Gastón", "José Luis"
};

/**
 * @brief Conjunto de nombres femeninos.
 * 
 */
const static std::vector<std::string> femaleNames = {
	"María", "Ana", "Gabriela", "Laura", "Carolina", "Lucía", "Valeria", "Sofía", "Natalia", "María José", "Florencia", "Patricia", "Silvia", "Romina", "Paula", "Cecilia", "Julieta", "Martina", "Marina", "Victoria", "Agustina", "Micaela", "Belén", "Macarena", "Milagros", "Josefina", "Daniela", "Lourdes", "Mercedes", "Débora", "Lorena", "Jimena", "Celeste", "Brenda", "Mariana", "Lorena", "Fernanda", "Marisol", "Agustina", "Noelia", "Roxana", "Julieta", "Camila", "Anabella", "Guadalupe", "Evangelina", "Miriam", "Gabriela", "Belén", "Pilar", "Vanesa", "Marina", "Verónica", "Daiana", "Estefanía", "Antonella", "Virginia", "Jazmín", "Marisa", "Brenda", "Micaela", "Dalila", "Catalina", "Gisela", "Candela", "Daniela", "Karen", "Juliana", "Cinthia", "Viviana", "Camila", "Lara", "Milena", "Rosario", "Mara", "Mariana", "Brenda", "Julieta", "Virginia", "Mayra", "Constanza", "Natalia", "Antonella", "Agustina", "Daiana", "Carla", "Yanina", "Carina", "Gabriela", "Anabella", "Lorena", "Ludmila", "Julieta", "Marina", "Rosana", "Nahir", "Mariana", "Ayelén", "Natalia", "Soledad"
};

/**
 * @brief Elige y devuelve un nombre masculino aleatoriamente.
 * 
 * @return const std::string el nombre elegido.
 */
const std::string randomizeMaleName() {
	return maleNames[Random::randInt(0, maleNames.size() - 1)];
}

/**
 * @brief Elige y devuelve un nombre femenino aleatoriamente.
 * 
 * @return const std::string el nombre elegido.
 */
const std::string randomizeFemaleName() {
	return femaleNames[Random::randInt(0, femaleNames.size() - 1)];
}

} // namespace truco
