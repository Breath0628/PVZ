#pragma once
#include "player.h"
#include <iostream>
#include "animation.h"

extern Atlas atlas_peashooter_idle_left;               // 婉逗射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;              // 婉逗射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;                // 婉逗射手朝向左的跑步动画图集
extern Atlas atlas_peashooter_run_right;               // 婉逗射手朝向右的跑步动画图集

class PeashooterPlayer: public Player 
{
public:
	PeashooterPlayer() {
		//为动画设定图集
		 animation_idle_left.set_atlas(&atlas_peashooter_idle_left); 
		 animation_idle_right.set_atlas(&atlas_peashooter_idle_right);
		 animation_run_left.set_atlas(&atlas_peashooter_run_left);
		 animation_run_right.set_atlas(&atlas_peashooter_run_right);
		 //设置动画帧间隔
		 animation_idle_left.set_interval(75);
		 animation_idle_right.set_interval(75);
		 animation_run_left.set_interval(75);
		 animation_run_right.set_interval(75);
	};
	~PeashooterPlayer()= default;

	void on_update(int delta){
		Player::on_update(delta);//调用父类方法
	//	std::cout << "PeashooterPlayer update" << std::endl;
	}
private:

};


