#pragma once
#include "camera.h"
#include <graphics.h>
#include "vector2.h"

class Player
{
public:
	Player() { current_animation = &animation_idle_right; };
	~Player();
	
	enum class PlayerID//识别玩家
	{
		P1,P2
	};
	
	virtual void on_update(int delta) {

		int direction = is_right_key_down - is_left_key_down;//玩家是否移动

		if (direction != 0) {
			//移动
			is_facing_right = direction > 0;
			current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
		}
		else
		{
			//静止
			current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
		}
		current_animation->on_update(delta);
	}
	virtual void on_draw(const Camera& camera) {
		current_animation->on_draw(camera,(int)(pos.x), (int)(pos.y));//渲染当前动画
	}

	virtual void on_input(const ExMessage &msg) {
		//判断按下与松开
		bool isDown = 0;
		switch (msg.message)
		{
		case WM_KEYDOWN:
			isDown = 1;
			break;
		case WM_KEYUP:
			isDown = 0;
			break;
		default:
			return;
		}

		//根据按键和id赋值
		switch (id)
		{
		case Player::PlayerID::P1:
			switch (msg.vkcode)
			{
			case 65://A
				is_left_key_down = isDown;
				break;
			case 68://D
				is_right_key_down= isDown;
				break;
			default:
				break;
			}
			break;
		case Player::PlayerID::P2:
			switch (msg.vkcode)
			{
			case VK_LEFT://<-
				is_left_key_down = isDown;
				break;
			case VK_RIGHT://->
				is_right_key_down = isDown;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	
	}


public:
	PlayerID id; //玩家id
	Vector2<float> pos;//玩家位置
	//键位是否被按下 -->判断移动 
	bool is_left_key_down=0;
	bool is_right_key_down = 0;
	bool is_facing_right = 1;//面向
	Animation* current_animation;//当前要播放的动画

	Animation animation_idle_left; //玩家动画
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;

};


Player::~Player()
{
}