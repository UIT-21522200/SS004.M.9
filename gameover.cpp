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
