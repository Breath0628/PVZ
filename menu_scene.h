#pragma once

#include "scene.h"
#include <iostream>
#include "scene_manager.h"

using namespace std;

extern SceneManager* scene_manager;

class MenuScene:public Scene
{
public:
	MenuScene() =default;
	~MenuScene() =default;

	void on_enter() {
		cout << "Enter Main Menu" << endl;
	}
	void on_update(){
		cout << "Main Menu is running!" << endl;
	}
	void on_draw(){
		outtextxy(10, 10, _T("Main Menu"));
	}
	void on_input(const ExMessage &msg) {
		if (msg.message == WM_KEYDOWN) {
			scene_manager->switch_to(SceneManager::SceneType::Selector);
		}
	};
	void on_exit(){
		cout << "Main Menu Exit!" << endl;
	}

private:

};