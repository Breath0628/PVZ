#pragma once

#include "scene.h"
#include <iostream>
#include "scene_manager.h"
#include "animation.h"
#include "camera.h"

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
		animation_peashooter_run_right.set_loop(1);
		
	}
	void on_update(int delta){
		//cout << "Main Menu is running!" << endl;
		camera.on_update(delta);
		animation_peashooter_run_right.on_update(delta);
	}
	void on_draw(){
		//outtextxy(10, 10, _T("Main Menu"));
		const Vector2<float>& pos_camera = camera.getPos();
		animation_peashooter_run_right.on_draw((int)(100-pos_camera.x), (int)(100- pos_camera.y));//由摄像机位置与世界位置得到窗口位置
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
	Camera camera;
};