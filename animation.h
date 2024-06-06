#pragma once
#include "atlas.h"
#include "utli.h"
#include <graphics.h>

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	void reset() {
		//重置
		timer = 0;
		idx_frame = 0;
	}
	void set_atlas(Atlas* new_atlas) {
		reset();
		atlas = new_atlas;
	}
	void set_loop(bool flag) {
		is_loop = flag;
	}
	void set_interval(int ms) {
		interval = ms;
	}
	int get_idx_frame() {
		return idx_frame;
	}
	IMAGE* get_frame() {
		return atlas->get_image(idx_frame);
	}

	bool check_finished() {
		//检查图集是否播放完毕
		if (is_loop)return false;
		return(idx_frame == atlas->get_size() - 1);//帧索引是否到底图集尾部
	}

	void on_update(int delta) {
		//帧更新函数
		timer += delta;
		if (timer >= interval) {
			timer = 0;
			idx_frame++;
			if (idx_frame >= atlas->get_size());
			{
				idx_frame = is_loop ? 0 : atlas->get_size() - 1;
			}
		}
	}
	void on_draw(int x,int y)const {
		//渲染
		puimage_alpha(x, y, atlas->get_image(idx_frame));
	}
private:
	int timer = 0;//计时器
	int interval = 0;//帧间隔
	int idx_frame = 0;//帧索引
	bool is_loop = true; //是否循环
	Atlas* atlas = nullptr;
};