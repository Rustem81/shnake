#include <iostream> //������� ���������� ����� ������
#include <conio.h> 

using namespace std;
bool gameOver; //���� ���������
const int widht = 20;
const int heigt = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];//������� ��� ������ ��������� ������
int nTail;//����������� ��������� ������
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup() {//��������� ����������
	gameOver = false;
	dir = STOP;
	x = widht / 2-1;
	y = heigt / 2-1;
	fruitX = rand() % widht;
	fruitY = rand() % heigt;
	//fruitX = 10;
	//fruitY = 10;
	score = 0;

}
void Draw() {
	
	//��������� �����
	system("cls"); // ������ �����
	
	for (int i = 0; i < widht+1; i++) 
		cout << "#";// ������������ ������� �������
	cout << endl;//������� ������

		for (int i = 0; i < heigt; i++) { //**
			for (int j = 0; j < widht; j++) {
				if (j == 0||j== widht-1)
					cout << "#"; //������������ ������������ �������, �� ������� ����� **
				if (i == y && j == x)
					cout << "Z"; //����� ������
				else if (i == fruitY && j == fruitX)
					cout << "F"; //����� ������
				else {
					bool print = false;
					for (int k = 0; k < nTail; k++) {
						if (tailX[k] == j && tailY[k] == i) {
							
							cout << "o";
							print = true;
						}
					}
							
					if (!print)
						cout << " "; //� ����� ** ��������� ��������� 		
				}
				
				
			
			}
			cout << endl;
		}
	for (int i = 0; i < widht+1; i++) 
		cout << "#";
	cout << endl;
	cout << "Score:" <<score<< endl;
}

void Input() {//����������� �������� �� �������
	if (_kbhit()) {//����������� ������ ���� ������� ����� � ��������
		switch (_getch()) //����������� �������
		{
		case'a':
			dir = LEFT;
			break;
		
		case'd':
			dir = RIGHT;
			break;
		
		case'w':
			dir = UP;
			break;
		
		case's':
			dir = DOWN;
			break;

		case'x':
			gameOver = true;
			break;
		}


	}

}
void Logic() {//��� ������ ����
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}

	switch (dir)
	{
	
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	//if (x > widht || x < 0 || y>heigt || y < 0);
	//	gameOver = true;
	if (x >= widht-1)
		x = 0;
	else if (x < 0)
		x = widht - 2;

	if (y >= heigt)
		y = 0;
	else if (y < 0)
		y = heigt - 1;


	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	}

	if (x == fruitX && y==fruitY) {
		score += 10;
		fruitX = rand() % widht;
		fruitY = rand() % heigt;
		nTail++;


	}

}

int main() {

	Setup(); //��������� ���������� ��������� 
	while (!gameOver) {//���� ��������� ����� �������� ��� ������� �� �������
		Draw(); //������������ ��� �� �����������
		Input(); // ������� �������
		Logic(); // ������������ ������� � ����� ������

	}



	return 0;
}