#pragma once
#include "camera.h"
#include <graphics.h>
#include "vector2.h"
#include "platform.h"

extern std::vector<Platform> platform_list; //ƽ̨����
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
			float dis = direction *speed * delta;//�����ƶ�����
			run(dis);
		}
		else
		{
			//��ֹ
			current_animation = is_facing_right ? &animation_idle_right : &animation_idle_left;
		}
		move_collide(delta);
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

	virtual void run(float dis) {
		//����
		pos.x += dis;
	}
	virtual void move_collide(float delta) {
		velocity.y=G * delta;//�����ٶ��ۼ�
		pos += velocity * (float)delta;
		
		//ƽ̨������ײ���
		if (velocity.y>0)
		{
			for (const Platform& platform:platform_list)
			{
				const Platform::CollisionShape& shape = platform.shape;
				bool is_collide_x = (
					max(pos.x + size.x, shape.right) - min(pos.x, shape.left)//ˮƽ��ײ���
					<= size.x + (shape.right - shape.left)
					);
				bool is_collide_y = (shape.y >= pos.y && shape.y<pos.y + size.y);//��ֱ��ײ���
				
				if (is_collide_x&& is_collide_y)
				{ 
					float delta_pos_y = velocity.y * delta;
					float last_foot_pos_y = pos.y + size.y - delta_pos_y;//��һ֡�Ų��߶�
					if (last_foot_pos_y<=shape.y)// ��һ֡�Ų���ƽ̨�Ϸ�
					{
						pos.y = shape.y - size.y;//����ɫ�Ų�λ��������ƽ̨��
						velocity.y = 0;//��ˮƽ�ٶ�����
						break;
					}
				}
			}
		}
	}

public:
	PlayerID id; //���id
	Vector2<float> pos;//���λ��
	Vector2<float> size = {96,96};//��Ҵ�С
	//��λ�Ƿ񱻰��� -->�ж��ƶ� 
	bool is_left_key_down=0;
	bool is_right_key_down = 0;
	bool is_facing_right = 1;//����
	const float speed=0.5f;//�ܶ��ٶ�
	const float G = 0.0320f;//�����ٶ�
	Vector2<float> velocity;//��ɫʸ���ٶ�

	Animation* current_animation;//��ǰҪ���ŵĶ���
	Animation animation_idle_left; //��Ҷ���
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;

};


Player::~Player()
{
}