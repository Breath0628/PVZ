#pragma once

#include "scene.h"
#include <iostream>
using namespace std;

class MenuScene:public Scene
{
public:
	MenuScene() =default;
	~MenuScene() =default;

	void on_enter() {
		cout << "Enter Main Menu" << endl;
	}
	void on_update(){
		cout << "Main Menu is running!" << endl;
	}
	void on_draw(){
		outtextxy(10, 10, _T("Main Menu"));
	}
	void on_input(const ExMessage &msg) {};
	void on_exit(){
		cout << "Main Menu Exit!" << endl;
	}

private:

};