/**
 * @file deck.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación del mazo de truco de 40 cartas.
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <entities/deck.h>
#include <utils/random.h>
#include <sstream>

#include <entities/player.h>

namespace truco {

/**
 * @brief Sobrecarga del operador <<.
 * 
 * @param os canal de salida.
 * @param card carta a mostrar.
 * @return std::ostream& devuelve canal de salida con la carta.
 */
std::ostream &operator<<(std::ostream &os, const Card &card) {
	switch (card.value) {
	case 1: os << "el ancho de "; break;
	case 10: os << "la sota de "; break;
	case 11: os << "el caballo de "; break;
	case 12: os << "el rey de "; break;
	default:
		os << "el " << card.value << " de ";
	}
	switch (card.type) {
	case Card::ORO: os << "oro"; break;
	case Card::COPAS: os << "copas"; break;
	case Card::ESPADAS: os << "espadas"; break;
	case Card::BASTOS: os << "bastos"; break;
	}

	return os;
}

/**
 * @brief Devuelve la definición de la carta.
 * 
 * @return const std::string string con la definición de la carta.
 */
const std::string Card::str() const {
	std::stringstream ss;
	ss << *this;
	return ss.str();
}

/**
 * @brief Constructor de Deck.
 * 
 */
Deck::Deck() {
	cards[20] = Card(20,  1, Card::ESPADAS, 13);
	cards[30] = Card(30,  1, Card::BASTOS, 12);

	cards[26] = Card(26,  7, Card::ESPADAS, 11);
	cards[ 6] = Card( 6,  7, Card::ORO, 10);

	cards[ 2] = Card( 2,  3, Card::ORO, 9);
	cards[12] = Card(12,  3, Card::COPAS, 9);
	cards[22] = Card(22,  3, Card::ESPADAS, 9);
	cards[32] = Card(32,  3, Card::BASTOS, 9);

	cards[ 1] = Card( 1,  2, Card::ORO, 8);
	cards[11] = Card(11,  2, Card::COPAS, 8);
	cards[21] = Card(21,  2, Card::ESPADAS, 8);
	cards[31] = Card(31,  2, Card::BASTOS, 8);

	cards[ 0] = Card( 0,  1, Card::ORO, 7);
	cards[10] = Card(10,  1, Card::COPAS, 7);

	cards[ 9] = Card( 9, 12, Card::ORO, 6);
	cards[19] = Card(19, 12, Card::COPAS, 6);
	cards[29] = Card(29, 12, Card::ESPADAS, 6);
	cards[39] = Card(39, 12, Card::BASTOS, 6);

	cards[ 8] = Card( 8, 11, Card::ORO, 5);
	cards[18] = Card(18, 11, Card::COPAS, 5);
	cards[28] = Card(28, 11, Card::ESPADAS, 5);
	cards[38] = Card(38, 11, Card::BASTOS, 5);

	cards[ 7] = Card( 7, 10, Card::ORO, 4);
	cards[17] = Card(17, 10, Card::COPAS, 4);
	cards[27] = Card(27, 10, Card::ESPADAS, 4);
	cards[37] = Card(37, 10, Card::BASTOS, 4);

	cards[16] = Card(16,  7, Card::COPAS, 3);
	cards[36] = Card(36,  7, Card::BASTOS, 3);

	cards[ 5] = Card( 5,  6, Card::ORO, 2);
	cards[15] = Card(15,  6, Card::COPAS, 2);
	cards[25] = Card(25,  6, Card::ESPADAS, 2);
	cards[35] = Card(35,  6, Card::BASTOS, 2);

	cards[ 4] = Card( 4,  5, Card::ORO, 1);
	cards[14] = Card(14,  5, Card::COPAS, 1);
	cards[24] = Card(24,  5, Card::ESPADAS, 1);
	cards[34] = Card(34,  5, Card::BASTOS, 1);

	cards[ 3] = Card( 3,  4, Card::ORO, 0);
	cards[13] = Card(13,  4, Card::COPAS, 0);
	cards[23] = Card(23,  4, Card::ESPADAS, 0);
	cards[33] = Card(33,  4, Card::BASTOS, 0);

	// Lomo
	cards[40] = Card(40, 0, Card::ORO, 0);
	
}

/**
 * @brief Mezcla el mazo.
 * 
 */
void Deck::merge() {
	for (unsigned i = 0; i < 40; i ++) {
		this->swap(i, Random::randInt(0, 39));
	}
}

/**
 * @brief Intercambia dos cartas según sus posiciones.
 * 
 * @param c1 posición de la carta 1.
 * @param c2 posición de la carta 2.
 */
void Deck::swap(int c1, int c2) {
	auto tmp = cards[c1];
	cards[c1] = cards[c2];
	cards[c2] = tmp;
}

/**
 * @brief Reparte 3 cartas a cada jugador.
 * 
 * @param players La lista de jugadores.
 */

void Deck::deliver(std::vector<std::shared_ptr<Player>> players) {
	unsigned index = 0;

	for (auto &p : players) {
		for (unsigned c = 0; c < 3; c ++) {
			p->setHand(c, &cards[index]);
			p->setPlayed(c, nullptr);
			index ++;
		}
	}
}

} // namespace truco
