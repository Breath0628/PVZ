#pragma once
#include "scene.h"
#include <graphics.h>

extern Scene* menu_scene;
extern Scene* game_scene;
extern Scene* selector_scene;

class SceneManager {

public:
	enum class SceneType
	{
		Menu,
		Game,
		Selector
	};

	SceneManager() =default;
	~SceneManager() = default;

	void set_current_scene(Scene* scene) {
		current_scene = scene;
		current_scene->on_enter();
	}

	void switch_to(SceneType type) {
		current_scene->exit();
		switch (type)
		{
		case SceneManager::SceneType::Menu:
			current_scene = menu_scene;
			break;
		case SceneManager::SceneType::Game:
			current_scene = game_scene;
			break;
		case SceneType::Selector:
			current_scene = selector_scene;
			break;
		default:
			break;
		}
		current_scene->on_enter();
	}

	void on_input(const ExMessage &msg) {
		current_scene->on_input(msg);
	}

	void on_update() {
		current_scene->on_update();
	}

	void on_draw() {
		current_scene->on_draw();
	}


private:
	Scene* current_scene;
};