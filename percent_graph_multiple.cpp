#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <graphics.h>
#include <iomanip>
#include "drawing.h"
using namespace std;
using namespace draw;

int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	int width = 720, height = 450; //绘图窗口长宽
	bool output = false; //数值对显示状态
	double percent = 0;
	srand((unsigned)time(NULL));
	cout.setf(ios::fixed);
	initgraph(width, height, 0);
	setcaption("抽中概率曲线图像");
	setbkcolor(WHITE);
	setcolor(RED); //默认为红色
	/*cout << "输入想中UP的次数:" << endl;
	while (1) {
		cin >> peach;
		if (!cin) {
			cout << "请输入正整数" << endl;
			cin.clear();
			cin.sync();
		} else {
			break;
		}
	}*/
	cout << "是否显示数值对?" << endl;
	output = getData<bool>(output, 0);
	cin.sync();
	for (peach = 1; peach <= 3; peach++) {
		switch (peach) {
			case 1:
				setcolor(RED);
				cout << "当前输出:抽中1次及以上概率图像，颜色:红"<<endl;
				break;
			case 2:
				setcolor(GREEN);
				cout << "当前输出:抽中2次及以上概率图像，颜色:绿"<<endl;
				break;
			case 3:
				setcolor(BLUE);
				cout << "当前输出:抽中3次及以上概率图像，颜色:蓝"<<endl;
				break;
		}
		for (trial = 0; trial <= 180; trial++) {
			for (long times = 0; times < 100000; times++) {
				int favor = 0;
				unsigned int big = dian;
				unsigned int smal = dian;
				bool state = baodi;
				while (big <= dian + trial) {
					smal++;
					big++;
					//cout<<smal<<" "<<big<<endl;
					int res = guess(smal, state);
					//cout<<res<<endl;
					if (res == 2) {
						state = false;
						favor++;
						smal = 0;
					} else if (res == 1) {
						state = true;
						smal = 0;
					} //else continue;
				}
				if (favor >= peach) {
					sum++;
				}
				//cout << "抽中次数：" << favor << endl;
				total = total + favor;
			}
			percent = sum / 1000.0;
			//cout << total << endl;
			if (output == true) {
				cout << fixed << setprecision(3) << trial << " " << percent / 100.0 << endl;
			}
			circle(trial * width / 180, (height - (percent / 100.0 * height)), 3);
			delay_ms(0); //立即更新绘图窗口
			sum = 0;
			total = 0;
		}
	}
	cin.sync();
	cin.get();
	cin.get();
	return 0;
}
