#pragma once
#include "camera.h"
#include <graphics.h>
#include "vector2.h"

class Player
{
public:
	Player() { current_animation = &animation_idle_right; };
	~Player();
	
	enum class PlayerID//ʶ�����
	{
		P1,P2
	};
	
	virtual void on_update(int delta) {

		int direction = is_right_key_down - is_left_key_down;//����Ƿ��ƶ�

		if (direction != 0) {
			//�ƶ�
			is_facing_right = direction > 0;
			current_animation = is_facing_right ? &animation_run_right : &animation_run_left;
		}
		else
		{
			//��ֹ
			current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
		}
		current_animation->on_update(delta);
	}
	virtual void on_draw(const Camera& camera) {
		current_animation->on_draw(camera,(int)(pos.x), (int)(pos.y));//��Ⱦ��ǰ����
	}

	virtual void on_input(const ExMessage &msg) {
		//�жϰ������ɿ�
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

		//���ݰ�����id��ֵ
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
	PlayerID id; //���id
	Vector2<float> pos;//���λ��
	//��λ�Ƿ񱻰��� -->�ж��ƶ� 
	bool is_left_key_down=0;
	bool is_right_key_down = 0;
	bool is_facing_right = 1;//����
	Animation* current_animation;//��ǰҪ���ŵĶ���

	Animation animation_idle_left; //��Ҷ���
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;

};


Player::~Player()
{
}