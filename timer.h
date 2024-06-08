#pragma once
#include <functional>

class Timer
{
public:
	Timer()=default;
	~Timer() = default;

	void restart() {
		pass_time = 0;
		shotted = 0;
	}
	void set_wait_time(int val) {
		wait_time = val;
	}
	void set_one_shot(bool flag) {
		one_shot = flag;
	}
	void set_callback(std::function<void()> callback){
		this->callback = callback;
	}
	void pause() {
		paused = 1;
	}
	void resume() {
		paused = 0;

	}
	void on_update(int delta){
		if (paused) return;
		pass_time += delta;
		if (pass_time>=wait_time)
		{
			if ((!one_shot || (one_shot && !shotted)) && callback) 
			//�������δ�����δ��������ѭ�����������лص����� ��ִ��
			{ 
				callback();
			}
			shotted = 1;
			pass_time = 0;
		}
	}

private:
	int pass_time = 0;//�ѹ�ʱ��
	int wait_time = 0;//�ȴ�ʱ��
	bool paused = 0;//�Ƿ���ͣ
	bool shotted = 0;//�Ƿ��Ѵ���
	bool one_shot = 0;//�Ƿ񵥴δ���
	std::function<void()>callback;//��ʱ�������󴥷��Ļص�����
};
