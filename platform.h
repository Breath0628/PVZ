#pragma once
#include "camera.h"
#include "animation.h"


class Platform
{
public:

	struct CollisionShape
	{
		float y, left, right;
	};

	Platform()=default;
	~Platform()= default;
public:
	CollisionShape shape;
	IMAGE* img = nullptr;
	POINT render_pos = { 0 };

	void on_draw(const Camera& camera)const
	{
		puimage_alpha(camera, render_pos, img);
	}

private:

};

