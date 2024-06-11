#pragma once

#include "bullet.h"
#include "animation.h"

extern Atlas atlas_sun;
extern Atlas atlas_sun_explode;
extern Camera main_camera;

class SunBullet :public Bullet
{
public:

	SunBullet() {
		size = { 96 ,96 };
		damage = 20;
		//���ö���
		animation_idle.set_atlas(&atlas_sun);
		animation_idle.set_interval(50);

		animation_explode.set_atlas(&atlas_sun_explode);
		animation_explode.set_interval(50);
		animation_explode.set_loop(0);
		animation_explode.set_callback([&]() {can_remove = 1;});

		//���붯��֡ͼƫ����
		IMAGE* frame_idle = animation_idle.get_frame();
		IMAGE* frame_explode= animation_explode.get_frame();
		explode_render_offset = { (frame_idle->getwidth() - frame_explode->getwidth()) / 2,
									(frame_idle->getheight() - frame_explode->getheight()) / 2
		};


	};
	~SunBullet() = default;

	void on_collide() {
		Bullet::on_collide();
		main_camera.shake(5, 250);//���������
		//̫������ը��Ч
		mciSendString(_T("play sun_explode from 0"), NULL, 0, NULL);
	
	}
	void on_update(int delta) {
		if (valid)//��Ч���ƶ�
		{
			velcity.y += G*delta;
			pos += velcity * (float)delta;

		}
		
		if (!valid) animation_explode.on_update(delta);//��Ч�ӵ��������鶯��
		else
		{
			animation_idle.on_update(delta);
		}
		if (check_exceed_screen())can_remove = 1;

	}
	void on_draw(const Camera& camera) const {
		//�����ӵ�״̬������Ⱦ
		if (valid) {
			animation_idle.on_draw(camera, int(pos.x), int(pos.y));
		}
		else
		{
			animation_explode.on_draw(camera, (int)(pos.x+explode_render_offset.x),
				(int)(pos.y+explode_render_offset.y));
		}
	}
private:
	Animation animation_idle;//�չ��ӵ�Ĭ����˸����
	Animation animation_explode;//�չ��ӵ���ը����
	Vector2<float> explode_render_offset;//��ը������Ⱦƫ��
	const float G=0.003f;
};

