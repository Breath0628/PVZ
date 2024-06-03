#pragma once
#include "scene.h"
#include <iostream>
#include "scene_manager.h"
using namespace std;

extern SceneManager* scene_manager;

class SelectorScene :public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void on_enter() {
		cout << "Enter Selector Scene" << endl;
	}
	void on_update() {
		cout << "Selector Scene is running!" << endl;
	}
	void on_draw() {
		outtextxy(10, 10, _T("Selector Scene"));
	}
	void on_input(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN) {
			scene_manager->switch_to(SceneManager::SceneType::Game);
		}
	};
	void on_exit() {
		cout << "Selector Scene Exit!" << endl;
	}

private:

};