#pragma once
#include "camera.h"
#include <graphics.h>

class Player
{
public:
	Player();
	~Player();
	virtual void on_update(int delta) {

	}
	virtual void on_draw(const Camera& camera) {

	}
	void on_input(const ExMessage &msg) {

	}

private:

};

Player::Player()
{
}

Player::~Player()
{
}