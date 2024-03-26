/**
 * @file border.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief 
 * @date 2024-03-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <memory>

namespace TCurses {

class Component;

class Border {
public:
	Border() : Border(0) {}
	Border(const short pos) { this->pos = pos; }

	virtual void draw() const = 0;

	void setComponent(Component *comp) { this->comp = comp; }

protected:
	Component *comp;
	short pos;
};

class EmptyBorder: public Border {
public:
	EmptyBorder() : Border() {}
	EmptyBorder(const short pos) : Border(pos) {}

	void draw() const override {}
};

class LinedBorder: public Border {
public:
	LinedBorder() : Border() {}
	LinedBorder(const short pos) : Border(pos) {}
	
	void draw() const override;
};

}
