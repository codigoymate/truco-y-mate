/**
 * @file deck.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Módulo que representa un mazo de Truco y sus cartas.
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <array>
#include <iostream>

namespace truco {

/**
 * @brief Representa una carta española.
 * 
 */
class Card {
public:
	enum CardType { ORO, COPAS, ESPADAS, BASTOS };

	/**
	 * @brief Constructor de Card por defecto.
	 * 
	 */
	Card() = default;

	/**
	 * @brief Constructor de Card.
	 * 
	 * @param id Identificador de la carta.
	 * @param value Valor de la carta 1 .. 12.
	 * @param type El palo de la carta (ORO, COPAS, ESPADAS, BASTOS).
	 * @param weight El peso de la carta en el Truco.
	 */
	Card(const int id, const int value, const CardType type, const int weight) :
			id(id), value(value), type(type), weight(weight) {}
	
	/**
	 * @brief Devuelve el ID de la carta.
	 */
	const int getId() const { return this->id; }

	/**
	 * @brief Devuelve el Valor de la carta.
	 */
	const int getValue() const { return this->value; }

	/**
	 * @brief Devuelve el palo de la carta.
	 */
	const CardType getType() const { return this->type; }

	/**
	 * @brief Devuelve el Peso de la carta.
	 */
	const int getWeight() const { return this->weight; }

	/**
	 * @brief Sobrecarga del operador <<.
	 * 
	 * @param os canal de salida.
	 * @param card carta a mostrar.
	 * @return std::ostream& devuelve canal de salida con la carta.
	 */
	friend std::ostream &operator<<(std::ostream &os, const Card &card);

	const std::string str() const;

private:
	int id; /**< Identificador de la carta. */
	int value; /**< Valor de la carta 1 .. 12 */
	CardType type; /**< Palo de la carta. */
	int weight; /**< Peso de la carta en el Truco. (ej. mas bajos son los 4, el mas alto el 1 de E) */
};

/**
 * @brief Representa un mazo de cartas de truco. Son 40 y no tiene los 8 y los 9
 * 	ni los comodines.
 * 
 */
class Deck {
public:
	/**
	 * @brief Constructor de Deck.
	 * 
	 */
	Deck();

	/**
	 * @brief Sobrecarga del operador [] para obtener la carta por índice.
	 * 
	 * @param index índice de la carta.
	 * @return const Card& La carta del índice.
	 */
	Card &operator[](const int index) { return cards[index]; }

	/**
	 * @brief Mezcla el mazo.
	 * 
	 */
	void merge();

private:
	std::array<Card, 41> cards;

	/**
	 * @brief Intercambia dos cartas según sus posiciones.
	 * 
	 * @param c1 posición de la carta 1.
	 * @param c2 posición de la carta 2.
	 */
	void swap(int c1, int c2);
};

} // namespace truco
