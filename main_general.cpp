#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include "drawing.h"

//#define Randmod(x) rand()%x

using namespace std;
using namespace draw;
int main() {
	int total = 0;
	int sum = 0;
	unsigned int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	srand((unsigned)time(NULL));
	cout << "垫之前是小保底还是大保底? 1=小,0=大" << endl;
	baodi = getData<bool>(baodi, 0);
	cin.sync();
	cout << "输入已垫次数:" << endl;
	dian = getData<unsigned int>(dian, 1);
	while (1) {
		cin.sync();
		if (baodi == 1 && dian >= 90) {
			cout << "你已经是小保底了，为啥还多于90次捏?(╯‵□′)╯︵┻━┻,请重新输入~" <<endl;
			dian = getData<unsigned int>(dian, 1);
		} else break;
	}
	cin.sync();
	cout << "输入还要抽取的次数:" << endl;
	trial = getData<unsigned int>(trial, 1);
	cin.sync();
	cout << "输入想中UP的次数:" << endl;
	peach = getData<unsigned int>(peach, 1);
	cin.sync();
	/*cout << trial << endl;
	cout << dian << endl;
	system("pause");*/
	for (long times = 0; times < 100000; times++) {
		unsigned int favor = 0;
		unsigned int big = dian;
		unsigned int small = dian;
		bool state = baodi;
		while (big <= dian + trial) {
			small++;
			big++;
			//cout<<small<<" "<<big<<endl;
			int res = guess(small, state);
			//cout<<res<<endl;
			if (res == 2) {
				state = false;
				favor++;
				small = 0;
			} else if (res == 1) {
				state = true;
				small = 0;
			} //else continue;
		}
		if (favor >= peach) {
			sum++;
		}
		//cout << "抽中次数：" << favor << endl;
		total = total + favor;
	}
	double percent = sum / 1000.0;
	cout.setf(ios::fixed);
	cout << "抽中" << peach << "次以上次数:" << sum << ",概率:" << fixed << setprecision(3) << percent << "%" << endl;
	cout << "总次数:" << total << endl;
	cin.sync();
	cin.get();
	return 0;
}
