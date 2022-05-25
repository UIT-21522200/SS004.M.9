#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;
int sl = 7;
//================ khu vuc khai bao nguyen mau ham ============
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_duoi();
void ve_tuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);


// ngo van manh them xu ly game over;
void xu_ly_game_over(int toadox[], int toadoy[]) {
	if (kt_ran(toadox, toadoy) == true) {

		// xoa con ran vi no chet roi

		for (int i = 0; i < sl; i++) {
			gotoXY(toadox[i], toadoy[i]);
			cout << " ";
			Sleep(25);
		}

		// xoa tuong 

		for (int i = 100; i >= 10; i--) {
			gotoXY(i, 26);
			cout << " ";
			Sleep(0.5);
		}
		for (int i = 26; i >= 1; i--) {
			gotoXY(10, i);
			cout << " ";
			Sleep(1);
		}
		for (int i = 10; i <= 100; i++) {
			gotoXY(i, 1);
			cout << " ";
			Sleep(0.5);
		}
		for (int i = 1; i <= 26; i++) {
			gotoXY(100, i);
			cout << " ";
			Sleep(1);
		}

		system("cls");
		gotoXY(55, 13);
		SetColor(124);
		cout << "Game Over\n";
		Sleep(1000);
		SetColor(7);
	}
}

//play gmae

void play(int speed) {
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	//===================== kiem tra va tao qua ==============
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	//tao qua
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;// dinh hinh vi tri can di chuyen cho ran
	int check = 2;
	while (gameover == false)
	{
		//system("cls");
		//========= backspace
		xoa_du_lieu_cu(toadox, toadoy);
		// 0 : di xuong
		//1: di len
		//2: qua phai
		//3: trai
		//========= dieu khien
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0)//di len
				{
					check = 1;
				}
				else if (kitu == 80 && check != 1)//di xuong
				{
					check = 0;
				}
				else if (kitu == 77 && check != 3)//di phai
				{
					check = 2;
				}
				else if (kitu == 75 && check != 2)//di trai
				{
					check = 3;
				}
			}
			else {
				kitu = tolower(kitu);
				if (kitu == 'w' && check != 0) check = 1;
				else if (kitu == 's' && check != 1) check = 0;
				else if (kitu == 'd' && check != 3) check = 2;
				else if (kitu == 'a' && check != 2) check = 3;
			}
		}
		//========= thuc hien di chuyen
		if (check == 0)
		{
			y++;//di xuong
		}
		else if (check == 1)
		{
			y--;//di len
		}
		else if (check == 2)
		{
			x++;//di qua phai
		}
		else if (check == 3)
		{
			x--;//di qua trai	
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		//========== kiem tra =========
		gameover = kt_ran(toadox, toadoy);
		Sleep(speed);
	}
	xu_ly_game_over(toadox, toadoy);
}


// menu game;
void Menu() {
	int lc = 1;
	int speed = 150;
	while (lc != 3) {
		system("cls");
		cout << "===============MENU===============";
		cout << "\n|\t   1.Play                |";
		cout << "\n|\t   2.Speed               |";
		cout << "\n|\t   3.Quit                |";
		cout << "\n===============MENU===============";
		cout << endl << "Nhap lua chon cua ban: ";
		cin >> lc;
		system("cls");
		if (lc == 1) play(speed);
		else if (lc == 2) {
			cout << "\n1.Nhanh"; // speed = 100;
			cout << "\n2.Trung Binh"; // speed = 150;
			cout << "\n3.Cham"; // speed = 200;
			int choice = 2;
			cin >> choice;
			if (choice == 1) speed = 100;
			else if (choice == 2) speed = 150;
			else if (choice == 3) speed = 200;
		}
	}
}


//============= ham main - xu ly chinh ==============
int main()
{
	//---------------
	Menu();
	
	return 0;
}
//============ khu vuc dinh nghia ham =============
void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 10, y = 26;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
void ve_tuong_phai()
{
	int x = 100, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}
void ve_tuong()
{
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_phai();
	ve_tuong_trai();
	SetColor(7);
}
void khoi_tao_ran(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			SetColor(124);
			cout << "o";
		}
	}
}
void xoa_du_lieu_cu(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua)
{
	//b1: them toa do moi vao dau mang
	them(toadox, x);
	them(toadoy, y);
	if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false)
	{
		//b2: xoa toa do cuoi mang
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);

	}
	else
	{
		tao_qua(xqua, yqua, toadox, toadoy);
	}
	//b3: ve ran
	ve_ran(toadox, toadoy);
}
void them(int a[], int x)
{
	for (int i = sl; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt)
{
	for (int i = vt; i < sl; i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
bool kt_ran_cham_tuong(int x0, int y0)
{
	//ran cham tuong tren
	if (y0 == 1 && (x0 >= 10 && x0 <= 100))
	{
		return true;//gameover
	}
	//ran cham tuong duoi
	else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
	{
		return true;//gameover
	}
	//ran cham tuong phai
	else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
	{
		return true;//gameover
	}
	//ran cham tuong trai
	else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
	{
		return true;//gameover
	}
	return false;
}
bool kt_ran_cham_duoi(int toadox[], int toadoy[])
{
	for (int i = 1; i < sl; i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;//gameover
		}
	}
	return false;
}
bool kt_ran(int toadox[], int toadoy[])
{
	bool kt1 = kt_ran_cham_duoi(toadox, toadoy);//gameover = true
	bool kt2 = kt_ran_cham_tuong(toadox[0], toadoy[0]);//gameover = false
	if (kt1 == true || kt2 == true)
	{
		return true;//gameover
	}
	return false;
}
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[])
{
	do
	{
		//11 <= xqua <= 99
		xqua = rand() % (99 - 11 + 1) + 11;
		//2 <= yqua <= 25
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << "$";
	SetColor(7);//mau trang
}
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		if ((xqua == toadox[i]) && (yqua == toadoy[i]))
		{
			return true;//ran de len qua
		}
	}
	return false;
}
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0)
{
	if ((x0 == xqua) && (y0 == yqua))
	{
		return true;//ran an qua
	}
	return false;
}