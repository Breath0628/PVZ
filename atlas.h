#pragma once
#include <iostream>
#include <vector>
#include <graphics.h>
using namespace std;



class Atlas
{
public:

	Atlas() = default;
	~Atlas() = default;
	void load_from_file(LPCTSTR path_template, int num) {
		//���ļ�����ͼ��
		img_list.clear();
		img_list.resize(num);
		TCHAR path_file[256];
		for (int i = 0;i < num;i++) {
			_stprintf_s(path_file, path_template, i + 1); //ƴ��ͼƬ·��
			loadimage(&img_list[i], path_file);

		}
	}

	void clear() {
		img_list.clear();
	}

	int get_size() {
		return (int)img_list.size();
	}

	IMAGE* get_image(int idx) {
		//����ͼ����i��ͼƬ��ָ��
		if (idx < 0 || idx >= img_list.size()) return nullptr;
		return &img_list[idx];
	}

	void add_image(const IMAGE& img){
		//Ϊͼ�����ͼƬ
		img_list.push_back(img);
	}


	
private:
	vector<IMAGE> img_list;
};