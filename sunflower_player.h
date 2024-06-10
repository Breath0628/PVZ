#pragma once

#include "player.h"
#include <iostream>

class SunflowerPlayer : public Player
{
public:
	SunflowerPlayer() = default;
	~SunflowerPlayer() = default;

	void on_update(int delta) {
		std::cout << "SunflowerPlayer update" << std::endl;
	}
private:

};


