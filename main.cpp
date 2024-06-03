#include <graphics.h>
#include <iostream>

int main() {
	ExMessage msg;
	const int FPS = 60;
	
	initgraph(1280, 720);
	
	BeginBatchDraw();

	while (true)
	{
		DWORD frame_start_time = GetTickCount();

		while (peekmessage(&msg))
		{

		}
		cleardevice();

		FlushBatchDraw();
		DWORD frame_end_time = GetTickCount();
		DWORD frame_delta_time = frame_end_time - frame_start_time;
		if (frame_delta_time < 1000 / FPS) {
			Sleep(1000/FPS-frame_delta_time);
		}
	}
	EndBatchDraw();
	return 0;

}