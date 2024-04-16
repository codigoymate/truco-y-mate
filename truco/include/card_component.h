/**
 * @file card_component.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Muestra una carta en formato pequeño.
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <tcurses/component.h>

namespace truco {

class Card;

/**
 * @brief Componente que representa una carta en formato pequeño.
 * Si card es null, dibuja el espacio vacio.
 * si Card::value es 0, dibuja el lomo.
 * 
 */
class CardComponent: public TCurses::Component {
public:
	/**
	 * @brief Constructor por defecto de CardComponent.
	 * 
	 */
	CardComponent();

	/**
	 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
	 * 
	 * @param x Coordenada x del componente.
	 * @param y Coordenada y del componente.
	 */
	CardComponent(const short x, const short y);

	/**
	 * @brief Constructor del componente CardComponent. Con el puntero a la carta a mostrar.
	 * 
	 * @param card Puntero a la carta.
	 */
	CardComponent(Card *card);

	/**
	 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
	 * Y el puntero a la carta a mostrar.
	 * 
	 * @param card Puntero a la carta.
	 * @param x Coordenada x del componente.
	 * @param y Coordenada y del componente.
	 */
	CardComponent(Card *card, const short x, const short y);

	/**
	 * @brief Establece la carta a mostrar.
	 * 
	 * @param card Puntero a la carta a mostrar.
	 */
	void setCard(Card *card);

	/**
	 * @brief Inicializa el CardComponent.
	 * 
	 */
	void init() override;

	/**
	 * @brief Dibuja el CardComponent.
	 * 
	 */
	void draw() override;

private:
	Card *card; /**< Puntero a la carta.*/
};

} // namespace truco
