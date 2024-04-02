/**
 * @file card_component.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Muestra una carta en formato grande.
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <tcurses/component.h>
#include <tcurses/art.h>

namespace truco {

class Card;

/**
 * @brief Componente que representa una carta en formato grande.
 * Si card es null, dibuja el espacio vacio.
 * si Card::value es 0, dibuja el lomo.
 * 
 */
class BigCardComponent: public TCurses::Component {
public:
	/**
	 * @brief Constructor por defecto de CardComponent.
	 * 
	 */
	BigCardComponent();

	/**
	 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
	 * 
	 * @param x Coordenada x del componente.
	 * @param y Coordenada y del componente.
	 */
	BigCardComponent(const short x, const short y);

	/**
	 * @brief Constructor del componente CardComponent. Con el puntero a la carta a mostrar.
	 * 
	 * @param card Puntero a la carta.
	 */
	BigCardComponent(Card *card);

	/**
	 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
	 * Y el puntero a la carta a mostrar.
	 * 
	 * @param card Puntero a la carta.
	 * @param x Coordenada x del componente.
	 * @param y Coordenada y del componente.
	 */
	BigCardComponent(Card *card, const short x, const short y);

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
	std::shared_ptr<TCurses::Art> art;
};

} // namespace truco
