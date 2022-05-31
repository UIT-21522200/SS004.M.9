#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;

class Point {
public:
	int x, y;
	Point() {
		x = y = 0;
	}
	void set(int a, int b) {
		x = a;
		y = b;
	}
};
int save = 7;
Point mangtuong[2000]; // luu toa do tuong
int id = 0;
int sl = 7; // do dai con ran

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
void xu_ly_game_over(int toadox[], int toadoy[], int map);
void play(int speed);
void Menu();
void map2();
bool kt_ran_map2(int toadox[], int toadoy[]);
//============= ham main - xu ly chinh ==============
int main()
{
	Menu();
	return 0;
}
//============ khu vuc dinh nghia ham ===============

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
	SetColor(save);
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << char(2);
		}
		else
		{

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
int fl = 1;
int ss;
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
	cout << char(3);

	if (fl == 1) save = 7;
	else save = ss;
	ss = i;
	fl = 2;

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
	for (int i = 0; i < id - 1; i++) {
		if (xqua == mangtuong[i].x && yqua == mangtuong[i].y) return true;
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

// ngo van manh them xu ly game over;

void xu_ly_game_over(int toadox[], int toadoy[], int map) {
	if (map == 1) {
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
		}
	}
	else if (map == 2) {
		for (int i = 0; i < sl; i++) {
			gotoXY(toadox[i], toadoy[i]);
			cout << " ";
			Sleep(25);
		}
		for (int i = 0; i < id - 1; i++) {
			gotoXY(mangtuong[i].x, mangtuong[i].y);
			cout << " ";
		}
	}
	system("cls");
	gotoXY(55, 13);
	SetColor(124);
	cout << "Game Over\n";
	Sleep(300);
	SetColor(7);
}

//play gmae

void play(int speed) {
	sl = 7;
	int map;
	gotoXY(39, 8);
	cout << "===============MAP================";
	gotoXY(39, 9);
	cout << "|\t   1.Map 1              |";
	gotoXY(39, 10);
	cout << "|\t   2.Map 2              |";
	gotoXY(39, 11);
	cout << "===============MAP================";
	gotoXY(39, 12);
	cout << "Nhap lua chon cua ban: ";
	cin >> map;
	system("cls");
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	if (map == 1) {
		ve_tuong();
	}
	else if (map == 2) {
		map2();
	}
	save = 7;
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
		if (map == 1) {
			gameover = kt_ran(toadox, toadoy);
		}
		else if (map == 2) {
			gameover = kt_ran_map2(toadox, toadoy);
		}
		Sleep(speed);
	}
	xu_ly_game_over(toadox, toadoy, map);
}

// menu game;
void Menu() {
	int lc = 1;
	while (lc != 3) {
		system("cls");
		SetColor(6);
		gotoXY(39,8);
		cout << "===============MENU===============";
		gotoXY(39, 9);
		cout << "|\t   1.Play               |";
		gotoXY(39, 10);
		cout << "|\t   2.Speed              |";
		gotoXY(39, 11);
		cout << "|\t   3.Quit               |";
		gotoXY(39, 12);
		cout << "===============MENU===============";
		gotoXY(39, 13);
		cout << "Nhap lua chon cua ban: ";
		cin >> lc;
		system("cls");
		if (lc == 1) {
			sl = 7;
			play(55);
		}
		else if (lc == 2) {
			gotoXY(39, 8);
			cout << "===============SPEED==============";
			gotoXY(39, 9);
			cout << "|\t   1.Nhanh              |";
			gotoXY(39, 10);
			cout << "|\t   2.Trung Binh         |";
			gotoXY(39, 11);
			cout << "|\t   3.Cham               |";
			gotoXY(39, 12);
			cout << "===============SPEED==============";
			gotoXY(39, 13);
			cout << "Nhap lua chon cua ban: ";
			int choice = 2;
			cin >> choice;
			system("cls");
			if (choice == 1) play(40);
			else if (choice == 2) play(70);
			else if (choice == 3) play(120);
		}
	}
}


void map2() {
	for (int i = 10; i <= 100; i++) {
		gotoXY(i, 1);
		mangtuong[id++].set(i, 1);
		cout << "+";
		gotoXY(i, 26);
		mangtuong[id++].set(i, 26);
		cout << "+";
	}
	for (int i = 1; i <= 26; i++) {
		gotoXY(10, i);
		mangtuong[id++].set(10, i);
		cout << "+";
		gotoXY(100, i);
		mangtuong[id++].set(100, i);
		cout << "+";
	}
	for (int i = 21; i <= 89; i++) {
		if (!(i >= 44 && i <= 66)) {
			gotoXY(i, 7);
			mangtuong[id++].set(i, 7);
			cout << "+";
		}
		if ((i >= 26 && i <= 38) || (i >= 72 && i <= 84)) continue;
		gotoXY(i, 19);
		mangtuong[id++].set(i, 19);
		cout << "+";
	}
	for (int i = 7; i <= 19; i++) {
		gotoXY(21, i);
		mangtuong[id++].set(21, i);
		cout << "+";
		gotoXY(89, i);
		mangtuong[id++].set(89, i);
		cout << "+";
		if (i > 13) {
			gotoXY(55, i);
			mangtuong[id++].set(55, i);
			cout << "+";
			continue;
		}
		gotoXY(78, i);
		mangtuong[id++].set(78, i);
		cout << "+";
		gotoXY(32, i);
		mangtuong[id++].set(32, i);
		cout << "+";
	}
}

bool kt_ran_map2(int toadox[], int  toadoy[]) {
	if (kt_ran_cham_duoi(toadox, toadoy)) return true;
	for (int i = 0; i < id - 1; i++) {
		if (toadox[0] == mangtuong[i].x && toadoy[0] == mangtuong[i].y) return true;
	}
	return false;
}
