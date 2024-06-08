#pragma once
#include <graphics.h>
#include "camera.h"
class Scene
{
public:

	Scene()=default;
	~Scene()=default;

	virtual void on_enter() {}; //���볡��
	virtual void on_update(int delta) {};//���ݴ���
	virtual void on_draw(const Camera& camera) {};//��Ⱦ
	virtual void on_input(const ExMessage& msg) {};//���봦��
	virtual void exit() {};//�����˳�

private:


};