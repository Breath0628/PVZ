#pragma once
#include <graphics.h>
class Scene
{
public:

	Scene()=default;
	~Scene()=default;

	virtual void on_enter() {}; //���볡��
	virtual void on_update() {};//���ݴ���
	virtual void on_draw() {};//��Ⱦ
	virtual void on_input(const ExMessage& msg) {};//���봦��
	virtual void exit() {};//�����˳�

private:


};