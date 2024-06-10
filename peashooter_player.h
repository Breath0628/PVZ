#pragma once
#include "player.h"
#include <iostream>
#include "animation.h"

extern Atlas atlas_peashooter_idle_left;               // �����ֳ������Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_idle_right;              // �����ֳ����ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_peashooter_run_left;                // �����ֳ�������ܲ�����ͼ��
extern Atlas atlas_peashooter_run_right;               // �����ֳ����ҵ��ܲ�����ͼ��

class PeashooterPlayer: public Player 
{
public:
	PeashooterPlayer() {
		//Ϊ�����趨ͼ��
		 animation_idle_left.set_atlas(&atlas_peashooter_idle_left); 
		 animation_idle_right.set_atlas(&atlas_peashooter_idle_right);
		 animation_run_left.set_atlas(&atlas_peashooter_run_left);
		 animation_run_right.set_atlas(&atlas_peashooter_run_right);
		 //���ö���֡���
		 animation_idle_left.set_interval(75);
		 animation_idle_right.set_interval(75);
		 animation_run_left.set_interval(75);
		 animation_run_right.set_interval(75);
	};
	~PeashooterPlayer()= default;

	void on_update(int delta){
		Player::on_update(delta);//���ø��෽��
	//	std::cout << "PeashooterPlayer update" << std::endl;
	}
private:

};


