#pragma once
#include "camera.h"
#include <graphics.h>
#include "vector2.h"
#include "platform.h"
#include "bullet.h"
#include "player_id.h"
extern std::vector<Bullet*>bullet_list;//�ӵ�����  
extern std::vector<Platform> platform_list; //ƽ̨����
extern Camera main_camera;


class Player
{
public:
	Player() { 
		current_animation = &animation_idle_right;
		//������ʱ������
		timer_attack.set_wait_time(attack_cd);
		timer_attack.set_one_shot(1);
		timer_attack.set_callback([&]() {
			can_attck = 1;
			});
	
	};
	~Player();
	
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
		timer_attack.on_update(delta);
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
		}

		//���ݰ�����id��ֵ
		switch (id)
		{
		case PlayerID::P1:
			switch (msg.vkcode)
			{
			case 65://A
				is_left_key_down = isDown;
				break;
			case 68://D
				is_right_key_down= isDown;
				break;
			case 0x57://W
				if (isDown)
				{
					jump();
				}
				break;
			case 0x46://F��ͨ����
				if (can_attck) {
					on_attack();
					can_attck=0;
					timer_attack.restart();
				}
				break;
			case 0x47://G�����⹥��
				if (mp >= 100) {
					on_attack_ex();
					mp =0;
				}
				break;
			default:
				break;
			}
			break;
		case PlayerID::P2:
			switch (msg.vkcode)
			{
			case VK_LEFT://<-
				is_left_key_down = isDown;
				break;
			case VK_RIGHT://->
				is_right_key_down = isDown;
				break;
			case VK_UP:
				if (isDown)
				{
					jump();
				}
				break;
			case VK_OEM_PERIOD://.��ͨ����
				if (can_attck) {
					on_attack();
					can_attck = 0;
					timer_attack.restart();
				}
				break;
			case VK_OEM_2:// ?�����⹥��
				if (mp >= 100) {
					on_attack_ex();
					mp = 0;
				}
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
		if (is_attacking_ex)return;//���⹥�����ƶ�
		//����
		pos.x += dis;
	}
	virtual void move_collide(float delta) {
		velocity.y += G * delta;//�����ٶ��ۼ�
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
	virtual void jump() {
		//��Ծ
		if (velocity.y==0.0&&!is_attacking_ex)
		{
			velocity.y += jump_speed;
		}
		
	};

	virtual void on_attack() {//��ͨ����


	};
	virtual void on_attack_ex(//��ɫ����
	) {};
	

public:
	PlayerID id; //���id
	Vector2<float> pos;//���λ��
	Vector2<float> size = {96,96};//��Ҵ�С

	bool can_attck = true;//�Ƿ���Թ���
	int attack_cd;//�������
	Timer timer_attack;//������ȴ��ʱ��
	bool is_attacking_ex=0;//�Ƿ��ڽ������⹥��

	int mp = 0;//����
	int hp = 100;//����

	//��λ�Ƿ񱻰��� -->�ж��ƶ� 
	bool is_left_key_down=0;
	bool is_right_key_down = 0;
	bool is_facing_right = 1;//����
	const float speed=0.5f;//�ܶ��ٶ�
	const float jump_speed = -1.2f;//��Ծ�ٶ�
	const float G = 0.00320f;//�����ٶ�
	Vector2<float> velocity;//��ɫʸ���ٶ�

	Animation* current_animation;//��ǰҪ���ŵĶ���
	Animation animation_idle_left; //��Ҷ���
	Animation animation_idle_right;
	Animation animation_run_left;
	Animation animation_run_right;
	Animation animation_attack_ex_left;//�������⹥������
	Animation animation_attack_ex_right;

};


Player::~Player()
{
}