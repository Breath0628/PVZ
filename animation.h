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
		//����
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
		//���ͼ���Ƿ񲥷����
		if (is_loop)return false;
		return(idx_frame == atlas->get_size() - 1);//֡�����Ƿ񵽵�ͼ��β��
	}

	void on_update(int delta) {
		//֡���º���
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
		//��Ⱦ
		puimage_alpha(x, y, atlas->get_image(idx_frame));
	}
private:
	int timer = 0;//��ʱ��
	int interval = 0;//֡���
	int idx_frame = 0;//֡����
	bool is_loop = true; //�Ƿ�ѭ��
	Atlas* atlas = nullptr;
};