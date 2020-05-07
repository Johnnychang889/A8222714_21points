#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//抽牌函數
int draw() {
	return rand() % 13+1;
}

//算點數函數
int getCardPoint(int card) {
	switch (card)
	{
	case 11:
		return 10;
	case 12:
		return 10;
	case 13:
		return 10;
	default:
		return card;
	}
}

//數字轉成對應牌名函數
string cardName(int point) {
	if (point == 1) return "A"; 
	else if (point == 2) return "2";
	else if (point == 3) return "3";
	else if (point == 4) return "4";
	else if (point == 5) return "5";
	else if (point == 6) return "6";
	else if (point == 7) return "7";
	else if (point == 8) return "8";
	else if (point == 9) return "9";
	else if (point == 10) return "10";
	else if (point == 11) return "J";
	else if (point == 12) return "Q";
	else if (point == 13) return "K";
}

//裁判(有無爆掉)
bool judge1(int yourPoint, int computerPoint) {
	if (yourPoint > 21) {
		cout << "你的點數超過21點,你輸了!" << endl;
		return true;

	}
	else if (computerPoint > 21) {
		cout << "對手的點數超過21點,你贏了!" << endl;
		return true;
	}
	else return false;
}

//裁判(比大小)
bool judge2(int yourPoint, int computerPoint) {
	if (computerPoint == yourPoint) {
	cout << "平手!" << endl;
	return true;
	}
	else if (yourPoint > computerPoint) {
	cout << "你贏了!" << endl;
	return true;
	}
	else if (yourPoint < computerPoint) {
	cout << "你輸了!" << endl;
	return true;
	}
	else return false;
}

//主函式
int main() {
	srand(time(0));
	char answer;
	int yourPoint, computerPoint;
	int your[5] , computer[5];

	computer[0] = draw();
	computerPoint = getCardPoint(computer[0]);
	your[0] = draw();
	yourPoint = getCardPoint(your[0]);
	cout << "你的底牌:" << cardName(your[0]) << endl;
	cout << "======================================" << endl;
	computer[1] = draw();
	computerPoint += getCardPoint(computer[1]);
	cout << "對手抽到:" << cardName(computer[1]) << endl;
	your[1] = draw();
	yourPoint += getCardPoint(your[1]);
	cout << "你抽到:" << cardName(your[1]) << "    你目前的點數共為:" << yourPoint <<endl;
	cout << "======================================" << endl;


	for (int j = 0; j < 3; j++) {
		cout << "你還要抽牌嗎?(輸入y或n)" << endl;
		cin >> answer;
		if (answer == 'y') {
			your[2] = draw();
			yourPoint += getCardPoint(your[2]);
			cout << "你抽到:" << cardName(your[2]) << "    你目前的點數共為:" << yourPoint << endl;
			if (judge1(yourPoint, computerPoint)) { break; };
			computer[2] = draw();
			computerPoint += getCardPoint(computer[2]);
			cout << "對手抽到:" << cardName(computer[2]) << endl;
			if (judge1(yourPoint, computerPoint)) { break; };
		}
		if (answer == 'n') {
			cout << "======================================" << endl;
			cout << "你的總點數:" << yourPoint << endl;
			cout << "對手的總點數:" << computerPoint << endl;
			if (judge2(yourPoint, computerPoint)) { break; };
		}
	}
	system("pause");
	return 0;
}