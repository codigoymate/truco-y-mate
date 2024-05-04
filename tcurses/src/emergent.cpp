#include <tcurses/emergent.h>

#include <tcurses/application.h>
#include <tcurses/screen.h>
#include <tcurses/utilities.h>
#include <tcurses/border.h>
#include <tcurses/colors.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Constructor de Emergent. El componente aparecerá centrado en la pantalla.
 * 
 * @param w ancho del Emergent.
 * @param h alto del Emergent.
 */
Emergent::Emergent(const short w, const short h) : Emergent(0, 0, w, h) {
	centered = true;
}

/**
 * @brief Constructor de Emergent.
 * 
 * @param x Coordenada x del Emergent.
 * @param y Coordenada y del Emergent.
 * @param w ancho del Emergent.
 * @param h alto del Emergent.
 */
Emergent::Emergent(const short x, const short y, const short w, const short h) :
	Component(x, y, w, h) {
	setBGPair(EMERGENT_BG_PAIR);
	setBorderPair(EMERGENT_BORDER_PAIR);
	setBorder(std::make_shared<LinedBorder>(1));
}

/**
 * @brief Dibuja el emergent.
 * 
 */
void Emergent::draw() {
	if (centered) {
		setX(application->getScreen()->getW() / 2 - getW() / 2);
		setY(application->getScreen()->getH() / 2 - getH() / 2);
	}

	// Dibuja el rectángulo de fondo
	if (!isBGTransparent()) {
		attron(COLOR_PAIR(getBGPair()));
		drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
		attroff(COLOR_PAIR(getBGPair()));
	}

	// Dibuja el borde
	attron(COLOR_PAIR(getBorderPair()));
	getBorder()->draw();
	attroff(COLOR_PAIR(getBorderPair()));
}

/**
 * @brief Dibuja todos los componentes del Emergent.
 * 
 */
void Emergent::drawAll() {
	internalDraw();
}

/**
 * @brief Actualiza todos los componentes del Emergent.
 * 
 */
void Emergent::updateAll() {
	internalUpdate();
}

/**
 * @brief Elimina el Emergent de Application y devuelve el foco a los
 * elementos anteriores.
 * 
 */
void Emergent::dispose() {
	// Elimina el Emergent de la cola.
	application->disposeEmergent();
}
	
} // namespace TCurses

