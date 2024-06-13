#pragma once
#include "vector2.h"
#include <graphics.h>
#include <functional>
#include "player_id.h"
#include "camera.h"



class Bullet
{
public:
	Bullet()=default;
	~Bullet()=default;

	void set_callback(std::function<void()> callback) {
		//���ûص�����
		this->callback = callback;
	}
	virtual void on_collide() {
		//��ײִ�лص�
		if (callback)callback();
	}

	virtual bool check_collision(const Vector2<float>& pos, const Vector2<float>& size) {
		//�ӵ����ĵ������������ײ���
		return this->pos.x + this->size.x / 2 >= pos.x 
			&& this->pos.x + this->size.x / 2 <= pos.x + size.x
			&& this->pos.y + this->size.y / 2 >= pos.y
			&& this->pos.y + this->size.y <= pos.y + size.y;

	}		
	virtual void on_update(int delta) {

	}
	virtual void on_draw(const Camera& camera) const{

	}
	virtual bool check_exceed_screen() {
		//����ӵ���������
		return (pos.x + size.x <= 0 || pos.x >= getwidth()) || (pos.y >= getheight() || pos.y + size.y <= 0);

	}


public:
	PlayerID target_id;//�ӵ�Ҫ��ײ��Ŀ��id
	Vector2<float> size;//�ߴ�
	Vector2<float> pos;//�ӵ�λ��
	Vector2<float> velcity;//�ӵ��ٶ�
	int damage;//�ӵ�����
	bool valid = true;//�ӵ���Ч
	bool can_remove = false;//�����Ƴ�
	std::function<void()> callback;//�ӵ���ײ��ص�����

};

