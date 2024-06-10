#pragma once
#include "camera.h"
#include <graphics.h>
#include "vector2.h"
#include "platform.h"

extern std::vector<Platform> platform_list; //平台对象
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
			float dis = direction *speed * delta;//向右移动距离
			run(dis);
		}
		else
		{
			//静止
			current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
		}
		move_collide(delta);
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

	virtual void run(float dis) {
		//奔跑
		pos.x += dis;
	}
	virtual void move_collide(float delta) {
		velocity.y=G * delta;//重力速度累加
		pos += velocity * (float)delta;
		
		//平台单向碰撞检测
		if (velocity.y>0)
		{
			for (const Platform& platform:platform_list)
			{
				const Platform::CollisionShape& shape = platform.shape;
				bool is_collide_x = (
					max(pos.x + size.x, shape.right) - min(pos.x, shape.left)//水平碰撞检测
					<= size.x + (shape.right - shape.left)
					);
				bool is_collide_y = (shape.y >= pos.y && shape.y<pos.y + size.y);//竖直碰撞检测
				
				if (is_collide_x&& is_collide_y)
				{ 
					float delta_pos_y = velocity.y * delta;
					float last_foot_pos_y = pos.y + size.y - delta_pos_y;//上一帧脚部高度
					if (last_foot_pos_y<=shape.y)// 上一帧脚部在平台上方
					{
						pos.y = shape.y - size.y;//将角色脚部位置设置在平台处
						velocity.y = 0;//将水平速度置零
						break;
					}
				}
			}
		}
	}

public:
	PlayerID id; //玩家id
	Vector2<float> pos;//玩家位置
	Vector2<float> size = {96,96};//玩家大小
	//键位是否被按下 -->判断移动 
	bool is_left_key_down=0;
	bool is_right_key_down = 0;
	bool is_facing_right = 1;//面向
	const float speed=0.5f;//跑动速度
	const float G = 0.0320f;//重力速度
	Vector2<float> velocity;//角色矢量速度

	Animation* current_animation;//当前要播放的动画
	Animation animation_idle_left; //玩家动画
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;

};


Player::~Player()
{
}