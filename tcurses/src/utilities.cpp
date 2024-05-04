#include <tcurses/utilities.h>

#include <vector>
#include <ncurses.h>

namespace TCurses {

/**
 * @brief Dibuja un área de texto con alineamiento horizontal y vertical.
 * @param text El texto a dibujar.
 * @param x1 La coordenada x del borde superior izquierdo del área.
 * @param y1 La coordenada y del borde superior izquierdo del área.
 * @param x2 La coordenada x del borde inferior derecho del área.
 * @param y2 La coordenada y del borde inferior derecho del área.
 * @param hAlign El alineamiento horizontal del texto dentro del área.
 * @param vAlign El alineamiento vertical del texto dentro del área.
 */
void drawTextArea(const std::string text,
                  const short x1, const short y1, const short x2, const short y2,
                  const Component::HAlign hAlign, const Component::VAlign vAlign,
				  const Label::Wrap wrap) {
	short w = x2 - x1, h = y2 - y1;

	// Guarda las lineas en un vector
	
	std::vector<std::string> lines;
	std::string str = "";
	for (int i = 0; i < text.size(); i ++) {
		int ch = text[i];

		switch (wrap) {
		case Label::WRAP_CHAR:
			if (str.size() >= w) {
				lines.push_back(str);
				str = std::string("");
			}
			break;

		case Label::WRAP_WORD:
			if (str.size() >= w) {
				// Busca el principio de la palabra actal
				auto pos = str.rfind(' ');
				if (pos != std::string::npos) { // si se encontró el espacio
					// agrega la línea sin la palabra a la lista.
					lines.push_back(str.substr(0, pos));
					// Ahora, str continua desde la palabra actual
					str = std::string(str.substr(pos));
				}
			}
			break;
		}

		if (ch == '\n') {
			lines.push_back(str);
			str = std::string("");
		} else {
			str += ch;
		}
	}
	lines.push_back(str);
	
	// Procesa las lineas

	// Procesa la alineación vertical
	short y;
	switch (vAlign) {
	case Component::VA_TOP:
		y = y1;
		break;
	case Component::VA_CENTER:
		y = (y1 + h / 2) - (lines.size() / 2);
		break;
	case Component::VA_BOTTOM:
		y = y2 - lines.size();
	}

	for (int l = 0; l < lines.size(); l ++) {

		if (y < y1) {
			y ++; continue;
		}

		if (y >= y2) return;

		// Procesa la alineación hor

		short x;
		switch (hAlign) {
		case Component::VA_TOP:
			x = x1;
			break;
		case Component::VA_CENTER:
			x = (x1 + w / 2) - (lines[l].size() / 2);
			break;
		case Component::VA_BOTTOM:
			x = x2 - lines[l].size();
		}

		for (int c = 0; c < lines[l].size(); c ++) {
			if (x < x1) {
				x ++; continue;
			}

			if (x >= x2) break;

			mvaddch(y, x, lines[l][c]);

			x ++;
		}

		y ++;
	}
}

/**
 * @brief Dibuja un rectángulo sólido con espacios.
 * 
 * @param x La coordenada x del borde superior izquierdo del rectángulo.
 * @param y La coordenada y del borde superior izquierdo del rectángulo.
 * @param w El ancho del rectángulo.
 * @param h El alto del rectángulo.
 */
void drawSolidRect(const short x, const short y, const short w, const short h) {
	for (short j = y; j < (y + h); j ++) {
		for (short i = x; i < (x + w); i ++) {
			mvaddch(j, i, ' ');
		}
	}
}

} // namespace TCurses
