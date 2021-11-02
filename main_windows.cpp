#include <iostream>
#include <stdlib.h>
#include <ctime>

//#define Randmod(x) rand()%x

using namespace std;

int guess(int s, bool st);
int main() {
	int total = 0;
	int sum = 0;
	int dian = 0, trial = 0, peach = 0;
	bool baodi = 0;
	srand((unsigned)time(NULL));
	cout<<"垫之前是小保底还是大保底? 1/true =小,0/false =大"<<endl;
		while (1) {
			cin >> baodi;
			if (!cin >> baodi && baodi == 0) {
				cout << "请输入1/true或0/false" << endl;
				dian = 0;
				cin.sync();
			} else {
				break;
			}
		}
	cout << "输入已垫次数:" << endl;
	while (1) {
		cin >> dian;
		if (!cin >> dian && dian == 0) {
			cout << "请输入正整数" << endl;
			dian = 0;
			cin.sync();
		} else {
			break;
		}
	}
	cout << "输入还要抽取的次数:" << endl;
	while (1) {
		cin >> trial;
		if (!cin >> trial && trial == 0) {
			cout << "请输入正整数" << endl;
			trial = 0;
			cin.sync();
		} else {
			break;
		}
	}
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
	/*cout << trial << endl;
	cout << dian << endl;
	system("pause");*/
	for (long int times = 0; times < 100000; times++) {
		int favor = 0;
		int big = dian;
		int small = dian;
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
	long double percent = 1.0 * (sum / 1000);
	cout << "抽中" << peach << "次以上次数:" << sum << ",概率:" << percent << "%" << endl;
	cout << "总次数:" << total << endl;
	system("pause");
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
