#pragma once
#include <graphics.h>
class Scene
{
public:

	Scene()=default;
	~Scene()=default;

	virtual void on_enter() {}; //进入场景
	virtual void on_update() {};//数据处理
	virtual void on_draw() {};//渲染
	virtual void on_input(const ExMessage& msg) {};//输入处理
	virtual void exit() {};//场景退出

private:


};