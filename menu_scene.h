#pragma once

#include "scene.h"
#include <iostream>
#include "scene_manager.h"
#include "animation.h"

using namespace std;

extern SceneManager* scene_manager;

extern Atlas atlas_peashooter_run_right;

class MenuScene:public Scene
{
public:
	MenuScene() =default;
	~MenuScene() =default;

	void on_enter() {
		//cout << "Enter Main Menu" << endl;
		animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		animation_peashooter_run_right.set_interval(75);
		animation_peashooter_run_right.set_loop(true);
	}
	void on_update(int delta){
		//cout << "Main Menu is running!" << endl;
		animation_peashooter_run_right.on_update(delta);
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
	Animation animation_peashooter_run_right;
};