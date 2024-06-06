#pragma once
#include <graphics.h>

inline void flip_image(IMAGE* src,IMAGE* dst){
	//图片翻转
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(src);
	for (size_t y = 0;y< h;y++) {
		for (size_t x = 0; x < w; x++)
		{
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - x - 1); //对源图片的某像素获取其翻转后对应的索引值
			dst_buffer[idx_dst] = src_buffer[idx_src]; 
		}
	}
}