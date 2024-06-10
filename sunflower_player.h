#pragma once

#include "player.h"
#include <iostream>

extern Atlas atlas_sunflower_idle_left;                // ���տ��������Ĭ�϶���ͼ��
extern Atlas atlas_sunflower_idle_right;               // ���տ������ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_sunflower_run_left;                 // ���տ���������ܲ�����ͼ��
extern Atlas atlas_sunflower_run_right;                // ���տ������ҵ��ܲ�����ͼ��

class SunflowerPlayer : public Player
{
public:
	SunflowerPlayer() {
		//Ϊ�����趨ͼ��
		animation_idle_left.set_atlas(&atlas_sunflower_idle_left);
		animation_idle_right.set_atlas(&atlas_sunflower_idle_right);
		animation_run_left.set_atlas(&atlas_sunflower_run_left);
		animation_run_right.set_atlas(&atlas_sunflower_run_right);
		//���ö���֡���
		animation_idle_left.set_interval(75);
		animation_idle_right.set_interval(75);
		animation_run_left.set_interval(75);
		animation_run_right.set_interval(75);
	
	};
	~SunflowerPlayer() = default;

	void on_update(int delta) {
		Player::on_update(delta);
		//std::cout << "SunflowerPlayer update" << std::endl;
	}
private:

};


