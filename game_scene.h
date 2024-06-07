#pragma once
#include "scene.h"
#include "scene_manager.h"
#include <iostream>
using namespace std;

extern SceneManager* scene_manager;

class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() {
		cout << "Enter Game Scene" << endl;
	}
	void on_update(int delta) {
		cout << "GameScene is running!" << endl;
	}
	void on_draw() {
		outtextxy(10, 10, _T("Game Scene Draw"));
	}
	void on_input(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN) {
			scene_manager->switch_to(SceneManager::SceneType::Menu);
		}
		
	};
	void on_exit() {
		cout << "Game Scene Exit!" << endl;
	}

private:

};