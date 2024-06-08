#pragma once
#include "vector2.h"

class  Camera
{
public:
	 Camera()=default;
	~ Camera() = default;

	const Vector2<float>& getPos() const{
		return position;
	}

	void reset() {
		position.x = 0;
		position.y = 0;
	}

	void on_update(int delta) {
		const Vector2 <float> speed = { -0.35f, 0 };
		position += speed * float(delta);
	}

private:
	Vector2<float> position;
};
