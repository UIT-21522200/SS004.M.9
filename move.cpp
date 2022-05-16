
		
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
			else 
			{
				if ((kitu == 'w' || kitu=='W') && check != 0)//di len
				{
					check = 1;
				}
				else if ((kitu == 's' || kitu == 'S') && check != 1)//di xuong
				{
					check = 0;
				}
				else if ((kitu == 'd' || kitu == 'D') && check != 3)//di phai
				{
					check = 2;
				}
				else if ((kitu == 'a' || kitu == 'A') && check != 2)//di trai
				{
					check = 3;
				}
      }
			

		
		
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
