#ifndef DRAWING_H
#define DRAWING_H
#include <iostream>
using namespace std;

template <typename T> getData(T target, bool type) {   //type: target的类型。0 = 布尔值(bool), 1 = unsigned int非负整型
	while (1) {
		cin >> target;
		if (!cin) {
			if (type == 0) {
				cout << "请输入0或1" << endl;
			} else {
				std::cout << "请输入非负整数" << std::endl;
			}
			cin.clear();
			cin.sync();
		} else {
			return target;
		}
	}
	return 0;
}
namespace character {
	int guess(unsigned int &s, bool &st) {
		long long ra = (double)rand() / RAND_MAX * 1000;
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
}
namespace weapon {
	int guess(unsigned int &s, int &st) {
		long double ra = (double)rand() / RAND_MAX * 1000;
		if (s > 63) {
			if (s == 80) {
				if (st == 2) {
					return 2;
				} else if (ra >= 1 && ra <= 375) {
					return 2;
				} else if (ra > 375 && ra <= 1000) {
					return 1;
				}
			} else if (ra >= 1 && (ra <= (7 + (s - 63) * 60))) {
				if (st == 2) {
					return 2;
				} else if (ra >= 1 && ra <= ((7 + (s - 63) * 60) * 0.75)) {
					if (ra >= 1 && ra <= ((7 + (s - 63) * 60) * 0.375)) {
						return 1;
					} else {
						return 2;
					}
					return 2;
				} else {
					return 1;
				}
			} else {
				return 3;
			}
		} else {
			if (ra >= 1 && ra <= 7) {
				if (st == 2) {
					return 2;
				} else if (ra >= 1 && ra <= 2.625) {
					return 2;
				} else {
					return 1;
				}
			} else {
				return 3;
			}
		}
		return 3; //符合规范,实无意义
		
	}
}
#endif
