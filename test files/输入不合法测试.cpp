#include <iostream>

using namespace std;

int main() {
	int tester1 = 0;
	while (1) {
		cin>>tester1;
		if(!cin){
			cout << "ÇëÊäÈëÕûÊı" << endl;
			cin.clear();
			cin.sync();	
		}
		else{
			cout<< tester1 <<endl;
			break;
		}
	}
	return 0;
}
