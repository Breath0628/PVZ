#pragma once

#include "scene.h"
#include <iostream>
using namespace std;

class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() {
		cout << "Enter Game Scene" << endl;
	}
	void on_update() {
		cout << "GameScene is running!" << endl;
	}
	void on_draw() {
		outtextxy(10, 10, _T("Game Scene Draw"));
	}
	void on_input(const ExMessage& msg) {};
	void on_exit() {
		cout << "Game Scene Exit!" << endl;
	}

private:

};