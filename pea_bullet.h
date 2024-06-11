#pragma once
#include "bullet.h"
#include "animation.h"

extern IMAGE img_pea;
extern Atlas atlas_pea_break;

class PeaBullet:public Bullet
{
public:

	PeaBullet() {
		size = { 64 ,64 };
		damage = 10;
		//�������鶯��
		animation_break.set_atlas(&atlas_pea_break);
		animation_break.set_interval(100);
		animation_break.set_loop(0);
		animation_break.set_callback([&]() {can_remove = 1;});
	};
	~PeaBullet()=default;

	void on_collide() {
		Bullet::on_collide();
		//��������㶹�ӵ�������Ч
		switch (rand()%3)
		{
		case 0:
			mciSendString(_T("play pea_break_1 from 0"), NULL,0,NULL);
			break;
		case 1:
			mciSendString(_T("play pea_break_2 from 0"), NULL, 0, NULL);
			break;
		case 2:
			mciSendString(_T("play pea_break_3 from 0"), NULL, 0, NULL);
			break;
		default:
			break;
		}
	}
	void on_update(int delta) {
		pos += velcity * (float)delta;
		if (!valid) animation_break.on_update(delta);//��Ч�ӵ��������鶯��
		if (check_exceed_screen())can_remove = 1;

	}
	void on_draw(const Camera& camera) const {
		//�����ӵ�״̬������Ⱦ
		if (valid) puimage_alpha(camera, (int)pos.x,(int)pos.y ,&img_pea);
		else
		{
			animation_break.on_draw(camera, (int)pos.x, (int)pos.y);
		}
	}
private:
	Animation animation_break;//�㶹�ӵ����Ѷ���

};

