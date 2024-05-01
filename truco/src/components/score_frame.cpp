/**
 * @file score_frame.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de score_frame.h
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <components/score_frame.h>

#include <components/game_frame.h>
#include <entities/player.h>

namespace truco {

/**
 * @brief Al iniciar el componente.
 * 
 */
void ScoreFrame::init() {
	//setMinW(15); setMaxW(15);
	setMinH(2); setMaxH(2);

	setLayout(TCurses::Component::LY_VERTICAL);

	auto frame1 = std::make_shared<TCurses::Frame>();
	frame1->setLayout(TCurses::Component::LY_HORIZONTAL);
	addChild(frame1);

	auto frame2 = std::make_shared<TCurses::Frame>();
	frame2->setLayout(TCurses::Component::LY_HORIZONTAL);
	addChild(frame2);
	
	auto label = std::make_shared<TCurses::Label>(gameFrame->getTeamName(0));
	label->setHTextAlign(TCurses::Component::HA_CENTER);
	frame1->addChild(label);

	label = std::make_shared<TCurses::Label>(gameFrame->getTeamName(1));
	label->setHTextAlign(TCurses::Component::HA_CENTER);
	frame1->addChild(label);

	for (unsigned i = 0; i < 2; i ++) {
		scoreLabel[i] = std::make_shared<TCurses::Label>("0");
		scoreLabel[i]->setHTextAlign(TCurses::Component::HA_CENTER);
		frame2->addChild(scoreLabel[i]);
	}
}

/**
 * @brief Agrega puntos a al total indicando el equipo.
 * 
 * @param team Equipo a agregar puntos.
 * @param score Puntos a agregar.
 */
void ScoreFrame::setScore(const unsigned team, const unsigned score) {
	this->score[team] += score;
	this->scoreLabel[team]->setText(std::to_string(score));
}

/**
 * @brief Devuelve el total de puntos de un equipo.
 * 
 * @param team Equipo objetivo.
 * @return unsigned Total de puntos del equipo.
 */
unsigned ScoreFrame::getScore(const unsigned team) const {
	return score[team];
}
	
} // namespace truco
