#pragma once

namespace TCurses {

class Component {
public:
	Component();
	Component(const short x, const short y);
	Component(const short x, const short y, const short w, const short h);

	const short getX() const { return x; }
	void setX(const short x) { this->x = x; }

	const short getY() const { return y; }
	void setY(const short y) { this->y = y; }

	const short getW() const { return w; }
	void setW(const short w) { this->w = w; }

	const short getH() const { return h; }
	void setH(const short h) { this->h = h; }

	void setPos(const short x, const short y) { this->x = x; this->y = y;}
	void setSize(const short w, const short h) { this->h = h; this->w = w;}

private:
	short x, y, w, h;
};

}
