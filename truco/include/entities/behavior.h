/**
 * @file behavior.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Define un comportamiento para un jugador.
 * @date 2024-04-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

namespace truco {

class GameFrame;

/**
 * @brief Comportamiento de un jugador. A partir del comportamiento abstracto
 * se define al humano y a las diferentes IAs.
 * 
 */
class Behavior {
public:
	/**
	 * @brief Constructor de Behavior.
	 * 
	 * @param gameFrame Frame principal.
	 */
	Behavior(GameFrame *gameFrame);

	/**
	 * @brief Realiza la acción de jugar.
	 * 
	 */
	virtual void play() = 0;

protected:
	GameFrame *gameFrame;
};

/**
 * @brief Define el comportamiento humano para un jugador.
 * 
 */
class Human : public Behavior {
public:
	/**
	 * @brief Constructor del comportamiento Human.
	 * 
	 * @param gameFrame Frame principal.
	 */
	Human(GameFrame *gameFrame);

	/**
	 * @brief Realiza la acción de jugar.
	 * 
	 */
	void play() override;
};

/**
 * @brief Define el comportamiento máquina para un jugador.
 * 
 */
class IA: public Behavior {
public:
	/**
	 * @brief Constructor del comportamiento IA.
	 * 
	 * @param gameFrame Frame principal.
	 */
	IA(GameFrame *gameFrame);

	/**
	 * @brief Realiza la acción de jugar.
	 * 
	 */
	void play() override;
};

} // namespace truco
