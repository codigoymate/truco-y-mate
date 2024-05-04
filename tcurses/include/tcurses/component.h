/**
 * @file component.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Contiene la definición de la clase Component, que representa un componente gráfico.
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <memory>
#include <list>

namespace TCurses {

class Application;
class Border;

/**
 * @brief La clase Component representa un componente básico de la interfaz de usuario.
 *        Puede ser un contenedor para otros componentes o un elemento visual en sí mismo.
 */
class Component {
public:

	/**
	 * @brief Enumeradores para alineación en general.
	 * 
	 */
	enum VAlign {VA_TOP, VA_CENTER, VA_BOTTOM};
	enum HAlign {HA_LEFT, HA_CENTER, HA_RIGHT};

	/**
	 * @brief Enumerador para el tipo de distribución.
	 * 
	 */
	enum Layout {LY_ABSOLUTE, LY_VERTICAL, LY_HORIZONTAL};

	/**
	 * @brief Constructor predeterminado de Component.
	 */
	Component();

	/**
	 * @brief Constructor de Component que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Component(const short x, const short y);

	/**
	 * @brief Constructor de Component que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del componente.
	 * @param h La altura inicial del componente.
	 */
	Component(const short x, const short y, const short w, const short h);

	/**
	 * @brief Ejecuta éste método al ser agregado a éste a un padre.
	 * Al igual que init de Application se utiliza para iniciar los componentes hijos.
	 * 
	 */
	virtual void init() {}

	/**
	 * @brief Obtiene la coordenada x del componente.
	 * @return La coordenada x del componente.
	 */
	const short getX() const { return x; }

	/**
	 * @brief Establece la coordenada x del componente.
	 * @param x La nueva coordenada x del componente.
	 */
	void setX(const short x) { this->x = x; }

	/**
	 * @brief Obtiene la coordenada y del componente.
	 * @return La coordenada y del componente.
	 */
	const short getY() const { return y; }

	/**
	 * @brief Establece la coordenada y del componente.
	 * @param y La nueva coordenada y del componente.
	 */
	void setY(const short y) { this->y = y; }

	/**
	 * @brief Obtiene el ancho del componente.
	 * @return El ancho del componente.
	 */
	const short getW() const { return w; }

	/**
	 * @brief Establece el ancho del componente.
	 * @param w El nuevo ancho del componente.
	 */
	void setW(const short w) { this->w = w; }

	/**
	 * @brief Obtiene la altura del componente.
	 * @return La altura del componente.
	 */
	const short getH() const { return h; }

	/**
	 * @brief Establece la altura del componente.
	 * @param h La nueva altura del componente.
	 */
	void setH(const short h) { this->h = h; }

	/**
	 * @brief Establece la posición del componente.
	 * @param x La nueva coordenada x del componente.
	 * @param y La nueva coordenada y del componente.
	 */
	void setPos(const short x, const short y) { this->x = x; this->y = y;}

	/**
	 * @brief Establece el tamaño del componente.
	 * @param w El nuevo ancho del componente.
	 * @param h La nueva altura del componente.
	 */
	void setSize(const short w, const short h) { this->h = h; this->w = w;}

	/**
	 * @brief Devuelve la coordenada x sumada con la del componente padre.
	 * 
	 * @return const short La coordenada x absoluta.
	 */
	const short getAbsX() const;

	/**
	 * @brief Devuelve la coordenada y sumada con la del componente padre.
	 * 
	 * @return const short La coordenada y absoluta.
	 */
	const short getAbsY() const;

	/**
	 * @brief Obtiene el componente padre.
	 * @return Un puntero al componente padre.
	 */
	const Component *getParent() { return parent; }

	/**
	 * @brief Obtiene la lista de hijos del componente.
	 * @return Una lista de punteros a los componentes hijos.
	 */
	const std::list<std::shared_ptr<Component>> getChildren() { return children; }

	/**
	 * @brief Establece el diseño del componente.
	 * @param layout El diseño a establecer para el componente.
	 */
	void setLayout(const Layout layout) { this->layout = layout; }

	/**
	 * @brief Obtiene el diseño actual del componente.
	 * @return El diseño actual del componente.
	 */
	const Layout getLayout() { return layout; }

	/**
	 * @brief Agrega un componente hijo.
	 * @param child Un puntero compartido al componente hijo a agregar.
	 */
	virtual void addChild(std::shared_ptr<Component> child);

	/**
	 * @brief Elminina un componente hijo por referencia.
	 * @param child Componente hijo.
	 */
	virtual void removeChild(std::shared_ptr<Component> child);

	/**
	 * @brief Elimina la totalidad de los hijos.
	 * 
	 */
	void removeChildren();

	/**
	 * @brief Obtiene el ancho mínimo del componente.
	 * @return El ancho mínimo del componente.
	 */
	const short getMinW() const { return minW; }

	/**
	 * @brief Establece el ancho mínimo del componente.
	 * @param mw El ancho mínimo para el componente.
	 */
	void setMinW(const short mw) { this->minW = mw; }

	/**
	 * @brief Obtiene la altura mínima del componente.
	 * @return La altura mínima del componente.
	 */
	const short getMinH() const { return minH; }

	/**
	 * @brief Establece la altura mínima del componente.
	 * @param mh La altura mínima para el componente.
	 */
	void setMinH(const short mh) { this->minH = mh; }

	/**
	 * @brief Obtiene el ancho máximo del componente.
	 * @return El ancho máximo del componente.
	 */
	const short getMaxW() const { return maxW; }

	/**
	 * @brief Establece el ancho máximo del componente.
	 * @param mw El ancho máximo para el componente.
	 */
	void setMaxW(const short mw) { this->maxW = mw; }

	/**
	 * @brief Obtiene la altura máxima del componente.
	 * @return La altura máxima del componente.
	 */
	const short getMaxH() const { return maxH; }

	/**
	 * @brief Establece la altura máxima del componente.
	 * @param mh La altura máxima para el componente.
	 */
	void setMaxH(const short mh) { this->maxH = mh; }

	/**
	 * @brief Devuelve la alineación horizontal del componente.
	 * 
	 * @return const HAlign alineación horizontal del componente.
	 */
	const HAlign getHAlign() const { return hAlign; }

	/**
	 * @brief Establece la alineación horizontal de componente.
	 * Tiene efecto al aplicar BoxLayout vertical en el componente padre.
	 * 
	 * @param hAlign alineación horizontal de componente.
	 */
	void setHAlign(const HAlign hAlign) { this->hAlign = hAlign; }

	/**
	 * @brief Devuelve la alineación vertical del componente.
	 * 
	 * @return const VAlign alineación vertical del componente.
	 */
	const VAlign getVAlign() const { return vAlign; }

	/**
	 * @brief Establece la alineación vertical de componente.
	 * Tiene efecto al aplicar BoxLayout horizontal en el componente padre.
	 * 
	 * @param vAlign alineación vertical de componente.
	 */
	void setVAlign(const VAlign vAlign) { this->vAlign = vAlign; }

	/**
	 * @brief Establece la alineación de componente.
	 * Tiene efecto al aplicar BoxLayout en el componente padre.
	 * 
	 * @param hAlign alineación horizontal de componente.
	 * @param vAlign alineación vertical de componente.
	 */
	void setAlign(const HAlign hAlign, const VAlign vAlign) {
		this->hAlign = hAlign; this->vAlign = vAlign;
	}

	/**
	 * @brief Devuelve el color de fondo.
	 * 
	 * @return const short color de fondo.
	 */
	const short getBGPair() const { return bgPair; }

	/**
	 * @brief Establece el color de fondo del componente.
	 * 
	 * @param color nuevo color de fondo.
	 */
	void setBGPair(const short pair) { bgPair = pair; }

	/**
	 * @brief Devuelve el color de borde.
	 * 
	 * @return const short color de borde.
	 */
	const short getBorderPair() const { return borderPair; }

	/**
	 * @brief Establece el color de borde del componente.
	 * 
	 * @param color nuevo color de borde.
	 */
	void setBorderPair(const short pair) { borderPair = pair; }

	/**
	 * @brief Devuelve el borde.
	 * 
	 * @return std::shared_ptr<Border> el borde.
	 */
	std::shared_ptr<Border> getBorder() const { return border; }

	/**
	 * @brief Establece el borde.
	 * 
	 * @param border el borde.
	 */
	void setBorder(std::shared_ptr<Border> border);

	/**
	 * @brief Devuelve verdadero si está activado el fondo transparente. 
	 */
	const bool isBGTransparent() const { return bgTransparent; }

	/**
	 * @brief Establece el fondo transparente.
	 * 
	 * @param bgt verdadero para el fondo transparente. 
	 */
	void setBGTransparent(const bool bgt) { this->bgTransparent = bgt; }

	/**
	 * @brief Devuelve los atributos de caracter.
	 */
	const unsigned getAttributes() const { return attributes; }

	/**
	 * @brief Establece los atributos de caracter.
	 * 
	 * @param attr atributos de caracter.
	 */
	void setAttributes(const unsigned attr) { attributes = attr; } 

	/**
	 * @brief Devuelve la referencia de la applicación.
	 * 
	 * @return Application* puntero a Application.
	 */
	Application *getApplication() { return application; }

	/**
	 * @brief Establece la referencia a application.
	 * 
	 * @param application Referencia a Application.
	 */
	void setApplication(Application *application) { this->application = application; }

protected:

	Application *application; /**<Referencia a Application.*/

	/**
	 * @brief Virtual para actualizar la lógica del componente.
	 * 
	 */
	virtual void update() {}

	/**
	 * @brief Virtual para dibujar el componente
	 * 
	 */
	virtual void draw() = 0;

	/**
	 * @brief Ejecuta update() y luego los de los hijos.
	 * 
	 */
	void internalUpdate();

	/**
	 * @brief Ejecuta draw() y luego dibuja los hijos.
	 * 
	 */
	void internalDraw();

private:

	// Transformación:
	short x, y, w, h; /**< Coordenadas x, y y dimensiones del componente */
	
	// Hijos:
	Component *parent; /**< Puntero al componente padre */
	std::list<std::shared_ptr<Component>> children; /**< Lista de punteros a los componentes hijos */

	// Distribución
	short minW, minH, maxW, maxH; /**< Máximos y mínimos para Layout*/
	Layout layout{}; /**< Distribución de los hijos */
	HAlign hAlign{}; /**< Alineacion horizontal para el box vertical*/
	VAlign vAlign{}; /**< Alineacion vertical para el box horizontal*/

	// Colores y estilo:
	short bgPair{}; /**< Color de fondo del Componente genérico */
	short borderPair{}; /**< Color del borde del Componente genérico */
	unsigned attributes{}; /**< Atributos de caracter.*/
	std::shared_ptr<Border> border; /**< Borde del componente*/
	bool bgTransparent{}; /**< Fondo transparente.*/

	/**
	 * @brief Realiza los ajustes box layout.
	 * 
	 */
	void doBoxLayout();
	
	/**
	 * @brief Realiza los ajustes verticales box layout.
	 * 
	 */
	void doBoxVertical();

	/**
	 * @brief Realiza los ajustes horizontales box layout.
	 * 
	 */
	void doBoxHorizontal();

	/**
	 * @brief Devuelve la suma total de los altos de los componentes hijos.
	 * 
	 * @return const short la suma total de altos.
	 */
	const short getTotalHeightBox() const;

	/**
	 * @brief Devuelve la suma total de los anchos de los componentes hijos.
	 * 
	 * @return const short la suma total de anchos.
	 */
	const short getTotalWidthBox() const;

	/**
	 * @brief Suma 1 al componente mas chico (en alto).
	 * En el caso de que se haya llegado al máximo, lo deja como está.
	 * 
	 * @return true Si se pudo agregar 1 al mas chico.
	 * @return false Si no pudo agregar 1 a ningún componente.
	 */
	const bool addOneToSmallVBox() const;

	/**
	 * @brief Suma 1 al componente mas chico (en ancho).
	 * En el caso de que se haya llegado al máximo, lo deja como está.
	 * 
	 * @return true Si se pudo agregar 1 al mas chico.
	 * @return false Si no pudo agregar 1 a ningún componente.
	 */
	const bool addOneToSmallHBox() const;
};

} // namespace TCurses
