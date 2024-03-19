#pragma once

#include <memory>
#include <list>

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

	const Component *getParent() { return parent; }

	const std::list<std::shared_ptr<Component>> getChildren() { return children; }

	void addChild(std::shared_ptr<Component> child);

private:
	short x, y, w, h;
	Component *parent;
	std::list<std::shared_ptr<Component>> children;
};

}
