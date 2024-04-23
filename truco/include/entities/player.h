/**
 * @file player.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Contiene la declaración de la clase Player.
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <array>

#include <memory>

namespace truco {

class Card;
class Behavior;

/**
 * @brief La clase Player representa un jugador en el Truco.
 */
class Player {
public:
	
	/**
	 * @brief Contructor de Player.
	 * 
	 * @param behavior Comportamiento del jugador.
	 */
	Player(std::shared_ptr<Behavior> behavior);

	/**
	 * @brief Construye un nuevo objeto Player con el nombre dado.
	 * 
	 * @param behavior Comportamiento del jugador.
	 * @param name Nombre del jugador.
	 */
	Player(std::shared_ptr<Behavior> behavior, const std::string name);

	/**
	 * @brief Devuelve el nombre del jugador.
	 */
	const std::string getName() const { return name; }

	/**
	 * @brief Obtiene la carta en el índice especificado de la mano del jugador.
	 * 
	 * @param i El índice de la carta.
	 * @return Un puntero a la carta.
	 */
	Card *getHand(const unsigned i) const { return hand[i]; }

	/**
	 * @brief Establece la carta en el índice especificado en la mano del jugador.
	 * 
	 * @param i El índice de la carta.
	 * @param card Un puntero a la carta que se va a establecer.
	 */
	void setHand(const unsigned i, Card *card) { hand[i] = card; }

	/**
	 * @brief Obtiene la carta en el índice especificado de las cartas jugadas por el jugador.
	 * 
	 * @param i El índice de la carta.
	 * @return Un puntero a la carta.
	 */
	Card *getPlayed(const unsigned i) const { return played[i]; }

	/**
	 * @brief Establece la carta en el índice especificado en las cartas jugadas por el jugador.
	 * 
	 * @param i El índice de la carta.
	 * @param card Un puntero a la carta que se va a establecer.
	 */
	void setPlayed(const unsigned i, Card *card) { played[i] = card; }

	/**
	 * @brief Devuelve el género del jugador.
	 * 
	 * @return true cuando es femenino.
	 * @return false cuando es masculino.
	 */
	const bool isShe() const { return she; }

	/**
	 * @brief Establece el género del jugador.
	 * 
	 * @param she Verdadero cuando es femenino.
	 */
	void setShe(const bool she) { this->she = she; }

	/**
	 * @brief El jugador juega una carta.
	 * 
	 * @param n El número de carta que tiene en la mano.
	 */
	void playCard(const unsigned n);

	/**
	 * @brief Realiza la jugada. Depende el comportamiento.
	 * 
	 */
	void play();

private:
	std::string name; //*< El nombre del jugador. */
	std::shared_ptr<Behavior> behavior; //*< Comportamiento del jugador. */
	bool she{}; //*< Verdadero cuando el jugador es mujer */
	std::array<Card *, 3> hand; //*< Un array que representa la mano del jugador. */
	std::array<Card *, 3> played; //*< Un array que representa las cartas jugadas por el jugador. */
};

} // namespa e truco
