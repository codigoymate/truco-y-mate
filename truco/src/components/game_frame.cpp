/**
 * @file gameframe.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de GameFrame.h
 * @date 2024-04-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <components/game_frame.h>
#include <components/start_frame.h>

#include <truco_colors.h>

#include <components/big_card_component.h>
#include <truco.h>
#include <entities/player.h>
#include <entities/behavior.h>
#include <entities/step_manager.h>
#include <components/player_frame.h>
#include <components/score_frame.h>
#include <utils/random.h>

#include <ncurses.h>

#include <cstdlib>

namespace truco {

/**
 * @brief Constructor de GameFrame.
 * 
 * @param playerCount Cantidad de jugadores para configurar el partido.
 */
GameFrame::GameFrame(const unsigned playerCount) : TCurses::Frame() {
	// Crea los jugadores
	for (unsigned i = 0; i < playerCount; i ++) {
		if (!i) {
			players.push_back(std::make_shared<Player>(i, std::make_shared<Human>(this), std::getenv("USER")));
		} else players.push_back(std::make_shared<Player>(i, std::make_shared<IA>(this)));
		
		playerFrames.push_back(std::make_shared<PlayerFrame>(players[i]->getName()));
	}

	// Crea el administrador de turnos.
	stepManager = std::make_shared<StepManager>(this);

}

/**
 * @brief Al inicia el Frame.
 * 
 */
void GameFrame::init() {
	this->setLayout(TCurses::Component::LY_VERTICAL);

	// Título
	auto title = std::make_shared<TCurses::Label>("Truco Argentino");
	title->setMaxH(1);
	title->setTextPair(TITLE_PAIR);
	title->setBGPair(TITLE_PAIR);
	title->setHTextAlign(TCurses::Component::HA_CENTER);
	title->setAttributes(A_BOLD);
	addChild(title);

	// Frame del centro ***************************
	mainFrame = std::make_shared<TCurses::Frame>();
	mainFrame->setLayout(TCurses::Component::LY_HORIZONTAL);
	addChild(mainFrame);

	// Frame de la mesa
	mainFrame->addChild(this->layoutTable());

	// Frame de Información y cartas de la mano
	auto frame = std::make_shared<Frame>();
	frame->setLayout(TCurses::Component::LY_VERTICAL);
	frame->setMaxW(30);
	mainFrame->addChild(frame);

	// Agrega un expansor
	frame->addChild(std::make_shared<TCurses::Frame>());

	// Label de información
	infoLabel = std::make_shared<TCurses::Label>();
	infoLabel->setMaxH(3);
	infoLabel->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	frame->addChild(infoLabel);

	// Cartas de la mano del jugador 1
	auto frame2 = std::make_shared<TCurses::Frame>();
	frame2->setLayout(TCurses::Component::LY_HORIZONTAL);
	frame->addChild(frame2);
	for (unsigned i = 0; i < 3; i ++) {
		hand[i] = std::make_shared<BigCardComponent>();
		hand[i]->setVAlign(Component::VA_BOTTOM);
		frame2->addChild(hand[i]);
	}

	// Frame del puntaje y el menu
	frame = std::make_shared<Frame>();
	frame->setLayout(TCurses::Component::LY_VERTICAL);
	frame->setMinW(20); frame->setMaxW(20);
	mainFrame->addChild(frame);

	// Puntaje
	scoreFrame = std::make_shared<ScoreFrame>(this);
	frame->addChild(scoreFrame);

	// Agrega un expansor
	frame->addChild(std::make_shared<TCurses::Frame>());

	// Menu del juego
	menu = std::make_shared<TCurses::Menu>();
	//menu->setMinW(15); menu->setMaxW(15);
	frame->addChild(menu);

	playCardItem[0] = std::make_shared<TCurses::MenuItem>("Carta 1",
					std::bind(&GameFrame::playCard1Action, this));
	playCardItem[1] = std::make_shared<TCurses::MenuItem>("Carta 2",
					std::bind(&GameFrame::playCard2Action, this));
	playCardItem[2] = std::make_shared<TCurses::MenuItem>("Carta 3",
					std::bind(&GameFrame::playCard3Action, this));
	trucoMenuItem = std::make_shared<TCurses::MenuItem>("Truco");
	envidoMenuItem = std::make_shared<TCurses::MenuItem>("Envido");
	quitMenuItem = std::make_shared<TCurses::MenuItem>("Salir", std::bind(&GameFrame::quitItemAction, this));

	// ********************************************

	// Status
	auto status = std::make_shared<TCurses::Label>();
	status->setLayout(TCurses::Component::LY_HORIZONTAL);
	status->setMaxH(1);
	addChild(status);

	// Status - Label jugador actual
	currentPlayerLabel = std::make_shared<TCurses::Label>();
	currentPlayerLabel->setTextPair(TITLE_PAIR);
	currentPlayerLabel->setBGPair(TITLE_PAIR);
	currentPlayerLabel->setAttributes(A_BOLD);
	status->addChild(currentPlayerLabel);

	stepManager->nextRound();
}

/**
 * @brief Devuelve el nombre del equipo dependiendo de la cantidad de jugadores
 * y los géneros.
 * Si son dos jugadores, devuelve el nombre del jugador objetivo.
 * Si son mas de dos, devuelve (Nosotros, Ellos, Nosotras, Ellas) dependiendo
 * de los géneros.
 * 
 * @param team Equipo objetivo.
 * @return const std::string nombre del equipo.
 */
const std::string GameFrame::getTeamName(const unsigned team) const {
	if (players.size() == 2) {
		return players[team]->getName();
	}

	// Determina genero de los jugadores
	std::string name0 = "Nosotras", name1 = "Ellas";
	for (unsigned i = 0; i < players.size(); i ++) {
		if (i % 2) {
			if (!players[i]->isShe()) name1 = "Ellos";
		} else {
			if (!players[i]->isShe()) name0 = "Nosotros";
		}
	}

	return team ? name1 : name0;
}

/**
 * @brief Actualiza la lógica del GameFrame.
 * 
 */
void GameFrame::update() {
	if (stepManager->isHalt()) return;
	stepManager->currentPlayer()->play();
}

/**
 * @brief Actualiza el menú.
 * 
 */
void GameFrame::updateMenu() {
	// TODO: Confugra el menu
	menu->removeChildren();

	if (stepManager->currentPlayer()->getID() == 0) {
		// Cartas
		for (unsigned i = 0; i < 3; i ++)
			if (stepManager->currentPlayer()->getHand(i))
				menu->addChild(playCardItem[i]);
	}

	/*menu->addChild(trucoMenuItem);
	menu->addChild(envidoMenuItem);*/
	menu->addChild(quitMenuItem);
	menu->setMinH(menu->getChildren().size());
	menu->setMaxH(menu->getChildren().size());
	///////
}

/**
 * @brief Actualiza los componentes.
 * 
 */
void GameFrame::updateComponents() {

	// Las cartas de la mano del jugador 1
	for (unsigned i = 0; i < 3; i ++) {
		hand[i]->setCard(players[0]->getHand(i));
	}

	// Las carta jugadas de todos los jugadores.
	for (unsigned p = 0; p < players.size(); p ++) {
		for (unsigned c = 0; c < 3; c ++) {
			playerFrames[p]->setCard(c, players[p]->getPlayed(c));
		}
	}
}

/**
 * @brief Al elegir Carta 1 en el menú.
 * 
 */
void GameFrame::playCard1Action() {
	humanPlayCard(0);
}

/**
 * @brief Al elegir Carta 2 en el menú.
 * 
 */
void GameFrame::playCard2Action() {
	humanPlayCard(1);
}

/**
 * @brief Al elegir Carta 3 en el menú.
 * 
 */
void GameFrame::playCard3Action() {
	humanPlayCard(2);
}

/**
 * @brief Llamado por el menú para jugar una carta.
 * 
 * @param c La carta a jugar.
 */
void GameFrame::humanPlayCard(const unsigned c) {
	if (stepManager->currentPlayer()->getHand(c)) {
		stepManager->currentPlayer()->playCard(c);

		// Baja la bandera para cuando le toque la próxima vez.
		std::static_pointer_cast<Human>(stepManager->currentPlayer()->getBehavior())->playing = false;

		stepManager->step();
		updateComponents();
		updateMenu();
	}
}

/**
 * @brief Al elegir salir en el menú.
 * 
 */
void GameFrame::quitItemAction() {
	application->getScreen()->removeChildren();
	application->getScreen()->addChild(std::make_shared<StartFrame>());
}

/**
 * @brief Distribuye los jugadores en la mensa.
 * 
 * @return std::shared_ptr<Frame> Frame de la mesa con los jugadores distribuidos.
 */
std::shared_ptr<TCurses::Frame> GameFrame::layoutTable() {
	auto tableFrame = std::make_shared<TCurses::Frame>();
	tableFrame->setLayout(TCurses::Component::LY_VERTICAL);

	switch (players.size()) {
	case 2:
		playerFrames[1]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[1]);

		tableFrame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[0]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[0]);
		break;
	
	case 4: {
		playerFrames[2]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[2]);

		auto frame = std::make_shared<TCurses::Frame>();
		tableFrame->addChild(frame);
		frame->setLayout(TCurses::Component::LY_HORIZONTAL);

		playerFrames[1]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[1]);

		frame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[3]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[3]);

		playerFrames[0]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[0]);
		} break;

	case 6: {
		playerFrames[3]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[3]);

		auto frame = std::make_shared<TCurses::Frame>();
		tableFrame->addChild(frame);
		frame->setLayout(TCurses::Component::LY_HORIZONTAL);

		playerFrames[2]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[2]);

		frame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[4]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[4]);

		frame = std::make_shared<TCurses::Frame>();
		tableFrame->addChild(frame);
		frame->setLayout(TCurses::Component::LY_HORIZONTAL);

		playerFrames[1]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[1]);

		frame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[5]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[5]);

		playerFrames[0]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[0]);
		} break;
	}

	return tableFrame;
}

/**
 * @brief Establece el texto del label de información.
 * 
 * @param text Texto de información.
 */
void GameFrame::setInfoText(const std::string text) {
	this->infoLabel->setText(text);
}

}
