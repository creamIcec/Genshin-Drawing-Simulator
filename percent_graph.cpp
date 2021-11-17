#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <graphics.h>

using namespace std;

int guess(int s, bool st);
void draw(int times, double perc, int width, int height) {
	putpixel(times * width / 180, (height-(perc * height)), RED);
}
int main() {
	int total = 0;
	int sum = 0;
	int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	int width = 720, height = 450;
	long double percent = 0;
	srand((unsigned)time(NULL));
	initgraph(width, height, 0);
	cout << "输入想中UP的次数:" << endl;
	while (1) {
		cin >> peach;
		if (!cin >> peach && peach == 0) {
			cout << "请输入正整数" << endl;
			peach = 0;
			cin.sync();
		} else {
			break;
		}
	}
	for (; trial <= 180; trial++) {
		for (long int times = 0; times < 100000; times++) {
			int favor = 0;
			int big = dian;
			int smal = dian;
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
		percent = 1.0 * (sum / 1000);
		cout<<trial<<" "<<percent/100<<endl;
		draw(trial,percent/100,width,height);
	}
	cin.sync();
	cin.get();
	cin.get();
	return 0;
}
int guess(int s, bool st) {
	long long ra = (double)rand() / RAND_MAX * 1000;
	//cout<<ra<<endl;
	//cout<<s<<" "<<st<<endl;
	if (s > 73) {
		if (s == 90) {
			if (st == true) {
				return 2;
			} else if (ra >= 1 && ra <= (500)) {
				return 2;
			} else {
				return 1;
			}
		} else if (ra >= 1 && (ra <= (6 + (s - 73) * 60))) {
			if (st == true) {
				return 2;
			} else if (ra >= 1 && ra <= ((6 + (s - 73) * 60) / 2)) {
				return 2;
			} else {
				return 1;
			}
		} else {
			return 3;
		}
	} else {
		if (ra >= 1 && ra <= 6) {
			if (st == true) {
				return 2;
			} else if (ra >= 1 && ra <= 3) {
				return 2;
			} else {
				return 1;
			}
		} else {
			return 3;
		}
	}
}
