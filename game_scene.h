#pragma once
#include "scene.h"
#include "scene_manager.h"
#include "camera.h"
#include "utli.h"

extern SceneManager* scene_manager;
extern Camera main_camera;
extern IMAGE img_sky;                                  // ���ͼƬ
extern IMAGE img_hills;                                // ɽ��ͼƬ
extern IMAGE img_platform_large;                       //����ƽ̨ͼƬ
extern IMAGE img_platform_small;                       //С��ƽ̨ͼƬ

class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void on_enter() {
		//����ͼ��λ
		pos_img_sky.x = (getwidth() - img_sky.getwidth()) / 2;
		pos_img_sky.y= (getheight() - img_sky.getheight()) / 2;

		pos_img_hills.x = (getwidth() - img_hills.getwidth()) / 2;
		pos_img_hills.y = (getheight() - img_hills.getheight()) / 2;

	}
	void on_update(int delta) {
	
	}
	void on_draw(const Camera& camera) {
		puimage_alpha(camera, pos_img_sky, &img_sky);
		puimage_alpha(camera, pos_img_hills, &img_hills);

	}
	void on_input(const ExMessage& msg) {
	

	};
	void on_exit() {
		
	}

private:
	POINT pos_img_sky = { 0 }; //���λ��
	POINT pos_img_hills = { 0 };//ɽ��λ��

};