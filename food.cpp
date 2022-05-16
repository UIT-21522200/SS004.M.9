void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[])
{
	do
	{
		//12 <= xqua <= 98
		xqua = rand() % (98 - 12 + 1) + 12;
		//3 <= yqua <= 26
		yqua = rand() % (25 - 3 + 1) + 3;
	} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
	int i = rand() % (15 - 1 + 1) + 1;
	
	
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << "U";
	SetColor(save);
	save = i;
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
