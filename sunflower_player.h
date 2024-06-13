#pragma once

#include "player.h"
#include <iostream>
#include "sunflower_player.h"
#include "sun_bullet.h"

extern Atlas atlas_sunflower_idle_left;                // ���տ��������Ĭ�϶���ͼ��
extern Atlas atlas_sunflower_idle_right;               // ���տ������ҵ�Ĭ�϶���ͼ��
extern Atlas atlas_sunflower_run_left;                 // ���տ���������ܲ�����ͼ��
extern Atlas atlas_sunflower_run_right;                // ���տ������ҵ��ܲ�����ͼ��
extern Atlas atlas_sunflower_attack_ex_left;             // ���տ�������Ĺ�������ͼ��
extern Atlas atlas_sunflower_attack_ex_right;            // ���տ������ҵĹ�������ͼ��
extern Atlas atlas_sun_text;                           // ���ա� �ı�����ͼ��
extern Player* player_1P;
extern Player* player_2P;

class SunflowerPlayer : public Player
{
public:
	SunflowerPlayer() {
		//Ϊ�����趨ͼ��
		animation_idle_left.set_atlas(&atlas_sunflower_idle_left);
		animation_idle_right.set_atlas(&atlas_sunflower_idle_right);
		animation_run_left.set_atlas(&atlas_sunflower_run_left);
		animation_run_right.set_atlas(&atlas_sunflower_run_right);
		animation_attack_ex_left.set_atlas(&atlas_sunflower_attack_ex_left);
		animation_attack_ex_right.set_atlas(&atlas_sunflower_attack_ex_right);
		animation_sun_text.set_atlas(&atlas_sun_text);
		//���ö���֡���
		animation_idle_left.set_interval(75);
		animation_idle_right.set_interval(75);
		animation_run_left.set_interval(75);
		animation_run_right.set_interval(75);
		animation_attack_ex_left.set_interval(100);
		animation_attack_ex_right.set_interval(100);
		animation_sun_text.set_interval(100);
		//���β���
		animation_attack_ex_left.set_loop(0);
		animation_attack_ex_right.set_loop(0);
		animation_sun_text.set_loop(0);
		//����������Ϻ�ص�����
		animation_attack_ex_left.set_callback([&]() {
			is_attacking_ex = 0;
			is_sun_text_visible = 0;
			});
		animation_attack_ex_right.set_callback([&]() {
			is_attacking_ex = 0;
			is_sun_text_visible = 0;
			});

		attack_cd = 250;
	};
	~SunflowerPlayer() = default;

	void on_update(int delta) {
		Player::on_update(delta);
		if (is_sun_text_visible)
		{
			animation_sun_text.on_update(delta);
		}
		
	}
	void on_draw(const Camera& camera) {
		Player::on_draw(camera);
		if (is_sun_text_visible)
		{//�ı���Ⱦλ��
			Vector2<float> text_pos;
			IMAGE* frame = animation_sun_text.get_frame();
			text_pos = {
			pos.x - (size.x - frame->getwidth()) / 2,
			pos.y - frame->getheight()
			};
			animation_sun_text.on_draw(camera, (int)text_pos.x, (int)text_pos.y);
		}

	}
	void on_attack() {//��ͨ����
		Bullet* bullet = new SunBullet();
		//�չ�ը������λ��
		Vector2<float> bullet_pos;
		const Vector2<float>& bullet_size = bullet->size;
		bullet_pos.x = pos.x + (size.x - bullet_size.x) / 2;
		bullet_pos.y = pos.y;
		bullet->pos = bullet_pos;
		//��ʼ�ٶȼ̳н�ɫ�����г��ٶ�
		bullet->velcity.x += is_facing_right ? velocity.x +0.5f :-velocity.x-0.5f;
		bullet->velcity.y += velocity.y-0.8f;
		bullet->target_id = id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1;
		bullet->set_callback([&]() {mp += 35;});
		bullet_list.push_back(bullet);
	};
	void on_attack_ex(//��ɫ����
	) {
		is_attacking_ex = 1;
		is_sun_text_visible = 1;
		animation_sun_text.reset();
		is_facing_right ? animation_attack_ex_right.reset() : animation_attack_ex_left.reset();

		Bullet* bullet = new SunBulletEX();
		Player* target_player = id == PlayerID::P1 ? player_1P: player_2P;
		//�����ӵ�λ���ٶ�
		Vector2<float> bullet_pos, bullet_velocity;
		const Vector2<float> bullet_size = bullet->size;
		const Vector2<float> target_size = target_player->size;
		const Vector2<float> target_pos = target_player->pos;
		bullet_pos = {
			target_pos.x+(target_size.x-bullet_size.x)/2,-size.y
		};
		bullet_velocity = {0,speed_sun_ex};
		bullet->pos = bullet_pos;
		bullet->velcity = bullet_velocity;

		bullet->target_id = id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1;//�����ӵ�Ŀ��
		bullet->set_callback([&]() {mp += 50;});
		bullet_list.push_back(bullet);
		mciSendString(_T("play sun_text from 0"), NULL, 0, NULL);

	};
private:
	Animation animation_sun_text;//ͷ������
	bool is_sun_text_visible = 0;
	const float speed_sun_ex = 0.15f;//����ը���ٶ�
	const Vector2<float> velocity_sun = { 0.25f,-0.5f };//��ͨը���ٶ�
};


