#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//��P���
int draw() {
	return rand() % 13+1;
}

//���I�ƨ��
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

//�Ʀr�ন�����P�W���
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

//���P(���L�z��)
bool judge1(int yourPoint, int computerPoint) {
	if (yourPoint > 21) {
		cout << "�A���I�ƶW�L21�I,�A��F!" << endl;
		return true;

	}
	else if (computerPoint > 21) {
		cout << "��⪺�I�ƶW�L21�I,�AĹ�F!" << endl;
		return true;
	}
	else return false;
}

//���P(��j�p)
bool judge2(int yourPoint, int computerPoint) {
	if (computerPoint == yourPoint) {
	cout << "����!" << endl;
	return true;
	}
	else if (yourPoint > computerPoint) {
	cout << "�AĹ�F!" << endl;
	return true;
	}
	else if (yourPoint < computerPoint) {
	cout << "�A��F!" << endl;
	return true;
	}
	else return false;
}

//�D�禡
int main() {
	srand(time(0));
	char answer;
	int yourPoint, computerPoint;
	int your[5] , computer[5];

	computer[0] = draw();
	computerPoint = getCardPoint(computer[0]);
	your[0] = draw();
	yourPoint = getCardPoint(your[0]);
	cout << "�A�����P:" << cardName(your[0]) << endl;
	cout << "======================================" << endl;
	computer[1] = draw();
	computerPoint += getCardPoint(computer[1]);
	cout << "�����:" << cardName(computer[1]) << endl;
	your[1] = draw();
	yourPoint += getCardPoint(your[1]);
	cout << "�A���:" << cardName(your[1]) << "    �A�ثe���I�Ʀ@��:" << yourPoint <<endl;
	cout << "======================================" << endl;


	for (int j = 0; j < 3; j++) {
		cout << "�A�٭n��P��?(��Jy��n)" << endl;
		cin >> answer;
		if (answer == 'y') {
			your[2] = draw();
			yourPoint += getCardPoint(your[2]);
			cout << "�A���:" << cardName(your[2]) << "    �A�ثe���I�Ʀ@��:" << yourPoint << endl;
			if (judge1(yourPoint, computerPoint)) { break; };
			computer[2] = draw();
			computerPoint += getCardPoint(computer[2]);
			cout << "�����:" << cardName(computer[2]) << endl;
			if (judge1(yourPoint, computerPoint)) { break; };
		}
		if (answer == 'n') {
			cout << "======================================" << endl;
			cout << "�A���`�I��:" << yourPoint << endl;
			cout << "��⪺�`�I��:" << computerPoint << endl;
			if (judge2(yourPoint, computerPoint)) { break; };
		}
	}
	system("pause");
	return 0;
}