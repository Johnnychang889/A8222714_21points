  
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//抽牌函式 
int draw() {
	return rand() % 13+1;
}

//算點數函式 
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

//點數轉對應牌名函式 
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

//裁判函式一 (有無爆掉)
bool judge1(int yourPoint, int computerPoint) {
	if (yourPoint > 21) {
		cout << "你的點數超過21點,你輸了!" << endl;
		return true;

	}
	else if (computerPoint > 21) {
		cout<<"對手的總點數為: "<< computerPoint<<endl;
		cout << "對手的點數超過21點,你贏了!" << endl;
		return true;
	}
	else return false;
}

//裁判函式二 (比大小)
bool judge2(int yourPoint, int computerPoint) {
	if (computerPoint == yourPoint) {
	cout<<"你的點數為: "<<yourPoint<<endl; 
	cout<<"對手的點數為: "<<computerPoint<<endl; 
	cout << "平手!" << endl;
	return true;
	}
	else if (yourPoint > computerPoint) {
	cout<<"你的點數為: "<<yourPoint<<endl; 
	cout<<"對手的點數為: "<<computerPoint<<endl; 
	cout << "你贏了!" << endl;
	return true;
	}
	else if (yourPoint < computerPoint) {
	cout<<"你的點數為: "<<yourPoint<<endl; 
	cout<<"對手的點數為: "<<computerPoint<<endl; 
	cout << "你輸了!" << endl;
	return true;
	}
	else return false;
}

//決定對手是否抽牌函式 
bool computerDraw(int computerPoint){
	if(computerPoint<17){
		return true;
	}
	else return (rand()%2)?true:false;
} 

//主函式
int main() {
	srand(time(0));
	char answer;//抽牌與否 
	int yourPoint;//你的點數 
	int computerPoint;//對手的點數 
	int your[5] , computer[5];

	computer[0] = draw();
	computerPoint = getCardPoint(computer[0]);
	your[0] = draw();
	yourPoint = getCardPoint(your[0]);
	cout << "你的底牌 :" << cardName(your[0]) << endl;
	cout << "======================================" << endl;
	computer[1] = draw();
	computerPoint += getCardPoint(computer[1]);
	cout << "對手抽到 :" << cardName(computer[1]) << endl;
	your[1] = draw();
	yourPoint += getCardPoint(your[1]);
	cout << "你抽到 :" << cardName(your[1]) << "    你目前的點數共為 :" << yourPoint <<endl;
	cout << "======================================" << endl;


	for (int j = 2; j < 5; j++) {
		cout << "你要抽牌嗎?(輸入y或n)" << endl;
		cin >> answer;
		if (answer == 'y') {
			your[j] = draw();
			yourPoint += getCardPoint(your[j]);
			cout << "你抽到: " << cardName(your[j]) << "    你目前的點數共為: " << yourPoint << endl;
			if (judge1(yourPoint, computerPoint)) { break; };
			if(computerDraw(computerPoint)){
				computer[j] = draw();
				computerPoint += getCardPoint(computer[j]);
				cout << "對手抽到: " << cardName(computer[j]) << endl;
				if (judge1(yourPoint, computerPoint)) { break; };
			}
			else cout<<"對手不想抽牌"<<endl;
			if (judge1(yourPoint, computerPoint)) { break; };
		}
		else if (answer == 'n') {
			cout << "======================================" << endl;
			if(computerDraw(computerPoint)){
				computer[j] = draw();
				computerPoint += getCardPoint(computer[j]);
				cout << "對手抽到: " << cardName(computer[j]) << endl;
				if (judge1(yourPoint, computerPoint)) { break; };
			}
			else {
				cout<<"對手不想抽牌"<<endl;
				if (judge2(yourPoint, computerPoint)) { break; };
			}
			
		}
		else{
			cout<<"請輸入y或n,不要亂打! "<<endl;
			j=2;
		}
	}
	
	system("pause");
	return 0;
}
