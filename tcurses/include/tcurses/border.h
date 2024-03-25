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
	Border() = default;

	virtual void draw() const = 0;

	void setComponent(Component *comp) { this->comp = comp; }

protected:
	Component *comp;
};

class EmptyBorder: public Border {
public:
	EmptyBorder() = default;

	void draw() const override {}
};

class LinedBorder: public Border {
public:
	LinedBorder() = default;
	void draw() const override;
};

}
