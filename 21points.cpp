  
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//��P�禡 
int draw() {
	return rand() % 13+1;
}

//���I�ƨ禡 
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

//�I��������P�W�禡 
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

//���P�禡�@ (���L�z��)
bool judge1(int yourPoint, int computerPoint) {
	if (yourPoint > 21) {
		cout << "�A���I�ƶW�L21�I,�A��F!" << endl;
		return true;

	}
	else if (computerPoint > 21) {
		cout<<"��⪺�`�I�Ƭ�: "<< computerPoint<<endl;
		cout << "��⪺�I�ƶW�L21�I,�AĹ�F!" << endl;
		return true;
	}
	else return false;
}

//���P�禡�G (��j�p)
bool judge2(int yourPoint, int computerPoint) {
	if (computerPoint == yourPoint) {
	cout<<"�A���I�Ƭ�: "<<yourPoint<<endl; 
	cout<<"��⪺�I�Ƭ�: "<<computerPoint<<endl; 
	cout << "����!" << endl;
	return true;
	}
	else if (yourPoint > computerPoint) {
	cout<<"�A���I�Ƭ�: "<<yourPoint<<endl; 
	cout<<"��⪺�I�Ƭ�: "<<computerPoint<<endl; 
	cout << "�AĹ�F!" << endl;
	return true;
	}
	else if (yourPoint < computerPoint) {
	cout<<"�A���I�Ƭ�: "<<yourPoint<<endl; 
	cout<<"��⪺�I�Ƭ�: "<<computerPoint<<endl; 
	cout << "�A��F!" << endl;
	return true;
	}
	else return false;
}

//�M�w���O�_��P�禡 
bool computerDraw(int computerPoint){
	if(computerPoint<17){
		return true;
	}
	else return (rand()%2)?true:false;
} 

//�D�禡
int main() {
	srand(time(0));
	char answer;//��P�P�_ 
	int yourPoint;//�A���I�� 
	int computerPoint;//��⪺�I�� 
	int your[5] , computer[5];

	computer[0] = draw();
	computerPoint = getCardPoint(computer[0]);
	your[0] = draw();
	yourPoint = getCardPoint(your[0]);
	cout << "�A�����P :" << cardName(your[0]) << endl;
	cout << "======================================" << endl;
	computer[1] = draw();
	computerPoint += getCardPoint(computer[1]);
	cout << "����� :" << cardName(computer[1]) << endl;
	your[1] = draw();
	yourPoint += getCardPoint(your[1]);
	cout << "�A��� :" << cardName(your[1]) << "    �A�ثe���I�Ʀ@�� :" << yourPoint <<endl;
	cout << "======================================" << endl;


	for (int j = 2; j < 5; j++) {
		cout << "�A�n��P��?(��Jy��n)" << endl;
		cin >> answer;
		if (answer == 'y') {
			your[j] = draw();
			yourPoint += getCardPoint(your[j]);
			cout << "�A���: " << cardName(your[j]) << "    �A�ثe���I�Ʀ@��: " << yourPoint << endl;
			if (judge1(yourPoint, computerPoint)) { break; };
			if(computerDraw(computerPoint)){
				computer[j] = draw();
				computerPoint += getCardPoint(computer[j]);
				cout << "�����: " << cardName(computer[j]) << endl;
				if (judge1(yourPoint, computerPoint)) { break; };
			}
			else cout<<"��⤣�Q��P"<<endl;
			if (judge1(yourPoint, computerPoint)) { break; };
		}
		else if (answer == 'n') {
			cout << "======================================" << endl;
			if(computerDraw(computerPoint)){
				computer[j] = draw();
				computerPoint += getCardPoint(computer[j]);
				cout << "�����: " << cardName(computer[j]) << endl;
				if (judge1(yourPoint, computerPoint)) { break; };
			}
			else {
				cout<<"��⤣�Q��P"<<endl;
				if (judge2(yourPoint, computerPoint)) { break; };
			}
			
		}
		else{
			cout<<"�п�Jy��n,���n�å�! "<<endl;
			j=2;
		}
	}
	
	system("pause");
	return 0;
}
