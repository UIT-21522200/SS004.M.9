void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "=";
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 10, y = 26;
	while (x <= 100)
	{
		gotoXY(x, y);
		cout << "=";
		x++;
	}
}
void ve_tuong_phai()
{
	int x = 100, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "||";
		y++;
	}
}
void ve_tuong_trai()
{
	int x = 10, y = 1;
	while (y <= 26)
	{
		gotoXY(x, y);
		cout << "||";
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
