#include <iostream>

using namespace std;
bool gameOver; //���� ���������
const int widht = 20;
const int heigt = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup() {//��������� ����������
	gameOver = false;
	dir = STOP;
	x = widht / 2;
	y = heigt / 2;
	fruitX = rand() % widht;
	fruitY = rand() % heigt;
	score = 0;

}
void Draw() {
	
	//��������� �����
	system("cls"); // ������ �����
	
	for (int i = 0; i < widht+1; i++) 
		cout << "1";
		cout << endl;

		for (int i = 0; i < heigt; i++) {
			for (int j = 0; j < widht; j++) {
				if (j == 0||j== widht-1)
					cout << "2";
				cout << " ";
			
			}
			cout << endl;
		}

	for (int i = 0; i < widht+1; i++) 
			cout << "3";
			cout << endl;

	

}
void Input() {//����������� �������� �� �������

}
void Logic() {//��� ������ ����

}

int main() {

	Setup();
	while (!gameOver) {//���� ��������� ����� �������� ��� ������� �� �������
		Draw();
		Input();
		Logic();

	}



	return 0;
}