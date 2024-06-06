#pragma once
#include <graphics.h>

inline void flip_image(IMAGE* src,IMAGE* dst){
	//ͼƬ��ת
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(src);
	for (size_t y = 0;y< h;y++) {
		for (size_t x = 0; x < w; x++)
		{
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - x - 1); //��ԴͼƬ��ĳ���ػ�ȡ�䷭ת���Ӧ������ֵ
			dst_buffer[idx_dst] = src_buffer[idx_src]; 
		}
	}
}

void flip_altas(Atlas& src, Atlas& dst) {
	//��ͼ���õ���תͼ��
	dst.clear();
	for (size_t i = 0; i < src.get_size(); i++)
	{
		IMAGE img_flpipped;
		flip_image(src.get_image(i), &img_flpipped);
		dst.add_image(img_flpipped);
	}
}

void load_game_resources() {


}