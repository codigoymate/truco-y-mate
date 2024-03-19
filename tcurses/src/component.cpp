#include <tcurses/component.h>

namespace TCurses {

Component::Component(const short x, const short y, const short w, const short h)
				: x(x), y(y), w(w), h(h) {	
	this->parent = nullptr;
}

Component::Component(const short x, const short y) : Component(x, y, 10, 1) {}

Component::Component() : Component(0, 0) {}

void Component::addChild(std::shared_ptr<Component> child) {
	this->children.push_back(child);
	child->parent = this;
}

}
