// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10, M = 10;
vector <int> y2;
vector <int> x2;
vector <int> y;



int x_start = 1, y_start = 1, x_end = N, y_end = M;



struct Point
{
	int n = 0, ne = 0, e = 0, se = 0, s = 0, sw = 0, w = 0, nw = 0;
	char a = '.';
	char p = '.';
	int pw = 0;
};

Point web[N + 2][M + 2];


void out_web()
{
	system("cls");

	/*for (int i = 1; i <= N; i++)
	{
	for (int j = 1; j <= M; j++)
	{
	cout << web[i][j].a;
	}
	cout << "" << endl;
	}*/
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << web[i][j].a;
		}
		cout << "" << endl;
	}
}

void make_barier(int x_barier, int y_barier)
{
	web[x_barier][y_barier].a = 'b';
	out_web();
}

void make_start(int x_start1, int y_start1)
{
	web[x_start1][y_start1].a = 's';
	out_web();

}
void make_end(int x_end1, int y_end1)
{
	web[x_end1][y_end1].a = 'e';
	out_web();
}

void find_first()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if ((web[i][j].a != 'b') &&
				(((web[i + 1][j + 1].a == 'b') && (web[i + 1][j].a != 'b') && (web[i][j + 1].a != 'b')) ||
				((web[i + 1][j - 1].a == 'b') && (web[i + 1][j].a != 'b') && (web[i][j - 1].a != 'b')) ||
					((web[i - 1][j - 1].a == 'b') && (web[i - 1][j].a != 'b') && (web[i][j - 1].a != 'b')) ||
					((web[i - 1][j + 1].a == 'b') && (web[i - 1][j].a != 'b') && (web[i][j + 1].a != 'b'))))
			{
				web[i][j].a = '*';
				out_web();
			}
		}
	}
}

void find_second()
{
	for (int i = 1; i <= N; i++)
	{
		int k = 0, kb = 0;
		bool c = 0, cb = 0;
		for (int j = 0; j <= M; j++)
		{
			if (web[i][j].a == 'b')
			{
				c = 0;
				k = 0;
				cb = 1;
				kb = 0;
			}
			else if (c)
			{
				k++;
				web[i][j].w = k;
			}
			else if (web[i][j].a == '*')
			{
				if (cb)
				{
					web[i][j].w = kb;
					kb--;
				}
				c = 1;
				cb = 0;

			}
			else if (cb)
			{
				web[i][j].w = kb;
				kb--;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int k = 0, kb = 0;
		bool c = 0, cb = 0;
		for (int j = M + 1; j >= 1; j--)
		{
			if (web[i][j].a == 'b')
			{
				c = 0;
				k = 0;
				cb = 1;
				kb = 0;
			}
			else if (c)
			{
				k++;
				web[i][j].e = k;
			}
			else if (web[i][j].a == '*')
			{
				if (cb)
				{
					web[i][j].e = kb;
					kb--;
				}
				c = 1;
				cb = 0;
			}
			else if (cb)
			{
				web[i][j].e = kb;
				kb--;
			}
		}
	}
	for (int j = 1; j <= M; j++)
	{
		int k = 0, kb = 0;
		bool c = 0, cb = 0;
		for (int i = N + 1; i >= 1; i--)
		{
			if (web[i][j].a == 'b')
			{
				c = 0;
				k = 0;
				cb = 1;
				kb = 0;
			}
			else if (c)
			{
				k++;
				web[i][j].s = k;
			}
			else if (web[i][j].a == '*')
			{
				if (cb)
				{
					web[i][j].s = kb;
					kb--;
				}
				c = 1;
				cb = 0;
			}
			else if (cb)
			{
				web[i][j].s = kb;
				kb--;
			}
		}
	}
	for (int j = 1; j <= M; j++)
	{
		int k = 0, kb = 0;
		bool c = 0, cb = 0;
		for (int i = 0; i <= N; i++)
		{
			if (web[i][j].a == 'b')
			{
				c = 0;
				k = 0;
				cb = 1;
				kb = 0;
			}
			else if (c)
			{
				k++;
				web[i][j].n = k;
			}
			else if (web[i][j].a == '*')
			{
				if (cb)
				{
					web[i][j].n = kb;
					kb--;
				}
				c = 1;
				cb = 0;
			}
			else if (cb)
			{
				web[i][j].n = kb;
				kb--;
			}
		}
	}

}

void find_diag()
{
	int sx = y.size(), sy = y.size();
	for (int i = 0; i <= N + 1; i++)//NW //SE------------------------------------------------------------------------------------------------------------
	{
		sx = y.size(), sy = y.size();
		sx = y.size(), sy = y.size();
		int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, k6 = 0, k7 = 0, k8 = 0;
		bool c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
		int bk1 = 0, bk2 = 0, bk3 = 0, bk4 = 0, bk5 = 0, bk6 = 0, bk7 = 0, bk8 = 0;
		bool bc1 = 0, bc2 = 0, bc3 = 0, bc4 = 0, bc5 = 0, bc6 = 0, bc7 = 0, bc8 = 0;
		sx = y.size(), sy = y.size();
		sx = y.size(), sy = y.size();
		for (int j = 0; j <= M - i + 2; j++)
		{
			sx = y.size(), sy = y.size();
			sx = y.size(), sy = y.size();
			//k3++;
			//	web[N - j + 1][N - (i + j) + 2].se = k3;
			if (web[j][i + j].a == 'b')//NW-----------------------------------------------------------------
			{
				c1 = 0;
				k1 = 1;
				bc1 = 1;
				bk1 = 0;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();
			}
			else if ((web[j][i + j].w>0) || (web[j][i + j].n>0) || (web[j][i + j].a == '*'))
			{
				if (bc1)
				{
					web[j][i + j].nw = bk1;
					bk1--;
					sx = y.size(), sy = y.size();
					sx = y.size(), sy = y.size();
				}
				else
					web[j][i + j].nw = k1;

				c1 = 1;
				k1 = 1;
				bc1 = 0;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();
			}
			else if (c1)
			{

				web[j][i + j].nw = k1;
				k1++;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();
			}
			else if (bc1)
			{
				web[j][i + j].nw = bk1;
				bk1--;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();

			}

			if (web[i + j][j].a == 'b')//----------------------------------------------------------------------------------------------------------
			{
				c2 = 0;
				k2 = 1;
				bc2 = 1;
				bk2 = 0;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();
			}
			else if ((web[i + j][j].w>0) || (web[i + j][j].n>0) || (web[i + j][j].a == '*'))
			{
				if (bc2)
				{
					web[i + j][j].nw = bk2;
					bk2--;
					sx = y.size(), sy = y.size();
					sx = y.size(), sy = y.size();

				}
				else
					web[i + j][j].nw = k2;
				c2 = 1;
				bc2 = 0;
				k2 = 1;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();
			}
			else if (c2)
			{

				web[i + j][j].nw = k2;
				k2++;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();
			}
			else if (bc2)
			{
				web[i + j][j].nw = bk2;
				bk2--;
				sx = y.size(), sy = y.size();
				sx = y.size(), sy = y.size();

			}
			sx = y.size(), sy = y.size();
			sx = y.size(), sy = y.size();


			if (web[N - j + 1][N - (i + j) + 2].a == 'b')//SE--------------------------------------------------------------------------
			{
				c3 = 0;
				k3 = 1;
				bc3 = 1;
				bk3 = 0;
			}
			else if ((web[N - j + 1][N - (i + j) + 2].s>0) || (web[N - j + 1][N - (i + j) + 2].e>0) || (web[N - j + 1][N - (i + j) + 2].a == '*'))
			{
				if (bc3)
				{
					web[N - j + 1][N - (i + j) + 2].se = bk3;
					bk3--;
				}
				else
					web[N - j + 1][N - (i + j) + 2].se = k3;
				c3 = 1;
				bc3 = 0;
				k3 = 1;
			}
			else if (c3)
			{

				web[N - j + 1][N - (i + j) + 2].se = k3;
				k3++;
			}
			else if (bc3)
			{
				web[N - j + 1][N - (i + j) + 2].se = bk3;
				bk3--;
			}

			if (web[N - (i + j) + 2][N - j + 1].a == 'b')//+-------------------------------------------------------------------------------------------
			{
				c4 = 0;
				k4 = 1;
				bc4 = 1;
				bk4 = 0;
			}
			else if ((web[N - (i + j) + 2][N - j + 1].e>0) || (web[N - (i + j) + 2][N - j + 1].s>0) || (web[N - (i + j) + 2][N - j + 1].a == '*'))
			{
				if (bc4)
				{
					web[N - (i + j) + 2][N - j + 1].se = bk4;
					bk4--;

				}
				else
					web[N - (i + j) + 2][N - j + 1].se = k4;
				c4 = 1;
				bc4 = 0;
				k4 = 1;
			}
			else if (c4)
			{

				web[N - (i + j) + 2][N - j + 1].se = k4;
				k4++;
			}
			else if (bc4)
			{
				web[N - (i + j) + 2][N - j + 1].se = bk4;
				bk4--;

			}

			if (web[j][N - (i + j) + 2].a == 'b')//NE-----------------------------------------------------------------------------
			{
				c5 = 0;
				k5 = 0;
				bc5 = 1;
				bk5 = 0;
			}
			else if ((web[j][N - (i + j) + 2].n>0) || (web[j][N - (i + j) + 2].e>0) || (web[j][N - (i + j) + 2].a == '*'))
			{
				if (bc5)
				{
					web[j][N - (i + j) + 2].ne = bk5;
					bk5--;

				}
				else
					web[j][N - (i + j) + 2].ne = k5;
				c5 = 1;
				bc5 = 0;
				k5 = 1;
			}
			else if (c5)
			{

				web[j][N - (i + j) + 2].ne = k5;
				k5++;
			}
			else if (bc5)
			{
				web[j][N - (i + j) + 2].ne = bk5;
				bk5--;

			}

			if (web[N - (i + j) + 2][j].a == 'b')//SW------------------------------------------------------------------------------------------
			{
				c6 = 0;
				k6 = 0;
				bc6 = 1;
				bk6 = 0;
			}
			else if ((web[N - (i + j) + 2][j].s>0) || (web[N - (i + j) + 2][j].w>0) || (web[N - (i + j) + 2][j].a == '*'))
			{
				if (bc6)
				{
					web[N - (i + j) + 2][j].sw = bk6;
					bk6--;
				}
				else
					web[N - (i + j) + 2][j].sw = k6;
				c6 = 1;
				bc6 = 0;
				k6 = 1;
			}
			else if (c6)
			{

				web[N - (i + j) + 2][j].sw = k6;
				k6++;
			}
			else if (bc6)
			{
				web[N - (i + j) + 2][j].sw = bk6;
				bk6--;

			}

			if (web[j + i][N - (j)+1].a == 'b')//NE ------------------------------------------------------------------------
			{
				c7 = 0;
				k7 = 0;
				bc7 = 1;
				bk7 = 0;
			}
			else if ((web[j + i][N - (j)+1].n>0) || (web[j + i][N - (j)+1].e>0) || (web[j + i][N - (j)+1].a == '*'))
			{
				if (bc7)
				{
					web[j + i][N - (j)+1].ne = bk7;
					bk7--;

				}
				else
					web[j + i][N - (j)+1].ne = k7;
				c7 = 1;
				bc7 = 0;
				k7 = 1;
			}
			else if (c7)
			{

				web[j + i][N - (j)+1].ne = k7;
				k7++;
			}
			else if (bc7)
			{
				web[j + i][N - (j)+1].ne = bk7;
				bk7--;

			}

			if (web[j + i][N - (j)+1].a == 'b')//SW ----------------------------------------------------------------------------------------------------------------------
			{
				c8 = 0;
				k8 = 0;
				bc8 = 1;
				bk8 = 0;
			}
			else if ((web[N - (j)+1][j + i].s>0) || (web[N - (j)+1][j + i].w>0) || (web[j + i][N - (j)+1].a == '*'))
			{
				if (bc8)
				{
					web[N - (j)+1][j + i].sw = bk8;
					bk8--;

				}
				else
					web[N - (j)+1][j + i].sw = k8;
				c8 = 1;
				bc8 = 0;
				k8 = 1;
			}
			else if (c8)
			{

				web[N - (j)+1][j + i].sw = k8;
				k8++;
			}
			else if (bc8)
			{
				web[N - (j)+1][j + i].sw = bk8;
				bk8--;

			}
		}
		sx = y.size(), sy = y.size();
		sx = y.size(), sy = y.size();
	}
	sx = y.size(), sy = y.size();
	sx = y.size(), sy = y.size();
}

void way()
{
	web[y[0] % 100][y[0] / 100].a = 'e';
	out_web();
	while ((y[0] / 100 != y_start) || (y[0] % 100 != x_start))
	{
		if (web[y[0] % 100][y[0] / 100].p == '1')
		{
			int aaa= y[0] + 100 * web[y[0] % 100][y[0] / 100].pw + web[y[0] % 100][y[0] / 100].pw;
			y[0] =y[0]+ 100 * web[y[0] % 100][y[0] / 100].pw + web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == '2')
		{
			y[0] = y[0] - 100 * web[y[0] % 100][y[0] / 100].pw + web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == '3')
		{
			y[0] = y[0] + 100 * web[y[0] % 100][y[0] / 100].pw - web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == '4')
		{
			y[0] = y[0] - 100 * web[y[0] % 100][y[0] / 100].pw - web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == 'n')
		{
			y[0] = y[0] -  web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == 's')
		{
			
			y[0] = y[0] +  web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == 'w')
		{
			int aaa = y[0] - web[y[0] % 100][y[0] / 100].pw,kk=y[0],jljl= web[y[0] % 100][y[0] / 100].pw;
			y[0] = y[0] -100* web[y[0] % 100][y[0] / 100].pw;
		}
		else if (web[y[0] % 100][y[0] / 100].p == 'e')
		{
			y[0] = y[0] + 100*web[y[0] % 100][y[0] / 100].pw;
		}
		web[y[0] % 100][y[0] / 100].a = '@';
		out_web();
	}
	
	web[y[0] % 100][y[0] / 100].a = 's';
	out_web();
}

void extra()
{
	if (web[x_end][y_end].p == '.')
	if (y[0]/100 == y_end)
	{
		if ((y[0]%100 -abs( web[y[0]%100][y[0]/100].n) <= x_end)&&(y[0] % 100>x_end))
		{
			
			web[x_end][y_end].p = 's';
			web[x_end][y_end].pw = y[0]%100 - x_end;
			y[0] = 100 * y_end + x_end;
		}
		else if (((y[0]%100 +abs( web[y[0]%100][y[0]/100].s) >= x_end)&&(y[0]%100<x_end)))
		{
			int dfjdfisafsd = y[0] % 100 + abs(web[y[0] % 100][y[0] / 100].s), djgdgjsoigjisdosg = web[y[0] % 100][y[0] / 100].s;
			web[x_end][y_end].p = 'n';
			web[x_end][y_end].pw = -y[0]%100 + x_end;
			y[0] = 100 * y_end + x_end;
		}
	}
	else if (y[0]%100 == x_end)
	{
		if (((y[0]/100 -abs( web[y[0]%100][y[0]/100].w) <= y_end)&&(y[0]/100>y_end)))
		{
			int jxzvbjsd = y[0] / 100 - y_end,fjskifjiosdfjisjd= y[0] % 100;
			web[x_end][y_end].p = 'e';
			web[x_end][y_end].pw = y[0]/100 - y_end;
			y[0] = 100 * y_end + x_end;
		}
		else if (((y[0]/100 +abs( web[y[0]%100][y[0]/100].e) >= y_end) && (y[0] / 100<y_end)))
		{
			web[x_end][y_end].p = 'w';
			web[x_end][y_end].pw = -y[0]/100 + y_end;
			y[0] = 100 * y_end + x_end;
		}
	}
}

void extra_diag()
{
	if (y[0]/100 > y_end)//N
	{
		if (y[0]%100 > x_end)//NW
		{
			if ((y[0]%100 - abs(web[y[0]%100][y[0]/100].nw) <= x_end))
			{
				if (web[x_end][y[0] / 100 - y[0] % 100 + x_end].p == '.')
				{
					y.push_back(100 * (y[0] / 100 - y[0] % 100 + x_end) + x_end);
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].a = 'j';
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].p = '1';
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].pw = y[0] % 100 - x_end;
					out_web();

				}
			}
			if ((y[0] / 100 - abs(web[y[0] % 100][y[0] / 100].nw) <= y_end))
			{
				if (web[y[0] % 100 - y[0] / 100 + y_end][y_end].p == '.')
				{
					y.push_back(100 * (y_end)+y[0] % 100 - y[0] / 100 + y_end);
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].a = 'j';
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].p = '1';
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].pw = y[0] / 100 - y_end;
					out_web();
				}
			}
		}
		else if (y[0]%100 < x_end)//NE
		{
			if ((y[0] % 100 + abs(web[y[0] % 100][y[0] / 100].ne) >= x_end))
			{
				if (web[x_end][y[0] / 100 + y[0] % 100 - x_end].p == '.')
				{
					y.push_back(100 * (y[0] / 100 + y[0] % 100 - x_end) + x_end);
					web[x_end][y[0] / 100 + y[0] % 100 - x_end].a = 'j';
					web[x_end][y[0] / 100 + y[0] % 100 - x_end].p = '3';
					web[x_end][y[0] / 100 + y[0] % 100 - x_end].pw = x_end - y[0] % 100;
					out_web();
				}
			}
			if ((y[0] / 100 - abs(web[y[0] % 100][y[0] / 100].ne) <= y_end) )
			{
				if (web[y[0] % 100 + y[0] / 100 - y_end][y_end].p == '.')
				{
					y.push_back(100 * (y_end)+y[0] % 100 + y[0] / 100 - y_end);
					web[y[0] % 100 + y[0] / 100 - y_end][y_end].a = 'j';
					web[y[0] % 100 + y[0] / 100 - y_end][y_end].p = '3';
					web[y[0] % 100 + y[0] / 100 - y_end][y_end].pw = y[0] / 100 - y_end;
					out_web();
				}
			}
		}
	}
	else if (y[0]/100 < y_end)//S
	{
		if (y[0]%100 > x_end)//SW
		{
			if ((y[0]%100 - abs(web[y[0]%100][y[0]/100].nw) <= x_end) && (y[0] % 100>x_end))
			{
				if (web[x_end][y[0] / 100 - y[0] % 100 + x_end].p == '.')
				{
					y.push_back(100 * (y[0] / 100 - y[0] % 100 + x_end) + x_end);
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].a = 'j';
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].p = '2';
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].pw = y[0] % 100 - x_end;
					out_web();
				}
			}
			if ((y[0]/100 + abs(web[y[0]%100][y[0]/100].nw) >= y_end) && (y[0] / 100<y_end))
			{
				if (web[y[0] % 100 - y[0] / 100 + y_end][y_end].p == '.')
				{
					y.push_back(100 * (y_end)+y[0] % 100 - y[0] / 100 + y_end);
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].a = 'j';
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].p = '2';
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].a = y_end - y[0] / 100;
					out_web();
				}
			}
		}
		else if (y[0]%100 < x_end)//SE
		{
			if ((y[0]%100 + abs(web[y[0]%100][y[0]/100].ne) >= x_end) && (y[0] % 100<x_end))
			{
				if (web[x_end][y[0] / 100 - y[0] % 100 + x_end].p == '.')
				{
					y.push_back(100 * (y[0] / 100 - y[0] % 100 + x_end) + x_end);
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].a = 'j';
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].p = '4';
					web[x_end][y[0] / 100 - y[0] % 100 + x_end].pw = x_end - y[0] % 100;
					out_web();
				}
			}
			if ((y[0] / 100 + abs(web[y[0] % 100][y[0] / 100].ne) >= y_end) && (y[0] / 100<y_end))
			{
				if (web[y[0] % 100 - y[0] / 100 + y_end][y_end].p == '.')
				{
					y.push_back(100 * (y_end)+y[0] % 100 - y[0] / 100 + y_end);
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].a = 'j';
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].p = '4';
					web[y[0] % 100 - y[0] / 100 + y_end][y_end].pw = y_end - y[0] / 100;
					out_web();
				}
			}
		}
	}
}

void diag()
{
	if ((web[y[0] % 100][y[0] / 100].nw >0 )&&(web[y[0] % 100 - web[y[0] % 100][y[0] / 100].nw][y[0] / 100 - web[y[0] % 100][y[0] / 100].nw].p == '.'))
	{
		y.push_back(100 * (y[0] / 100 - web[y[0] % 100][y[0] / 100].nw) + y[0] % 100 - web[y[0] % 100][y[0] / 100].nw);
		web[y[0] % 100 - web[y[0] % 100][y[0] / 100].nw][y[0] / 100 - web[y[0] % 100][y[0] / 100].nw].p = '1';
		web[y[0] % 100 - web[y[0] % 100][y[0] / 100].nw][y[0] / 100 - web[y[0] % 100][y[0] / 100].nw].pw = web[y[0] % 100][y[0] / 100].nw;
	}
	if ((web[y[0] % 100][y[0] / 100].ne >0)&&(web[y[0] % 100 - web[y[0] % 100][y[0] / 100].ne][y[0] / 100 + web[y[0] % 100][y[0] / 100].ne].p == '.'))
	{
		y.push_back(100 * (y[0] / 100 + web[y[0] % 100][y[0] / 100].ne) + y[0] % 100 - web[y[0] % 100][y[0] / 100].ne);
		web[y[0] % 100 - web[y[0] % 100][y[0] / 100].ne][y[0] / 100 + web[y[0] % 100][y[0] / 100].ne].p = '2';
		web[y[0] % 100 - web[y[0] % 100][y[0] / 100].ne][y[0] / 100 + web[y[0] % 100][y[0] / 100].ne].pw = web[y[0] % 100][y[0] / 100].ne;
	}
	if ((web[y[0] % 100][y[0] / 100].sw >0) && (web[y[0] % 100 + web[y[0] % 100][y[0] / 100].sw][y[0] / 100 - web[y[0] % 100][y[0] / 100].sw].p =='.'))
	{
		y.push_back(100 * (y[0] / 100 - web[y[0] % 100][y[0] / 100].sw) + y[0] % 100 + web[y[0] % 100][y[0] / 100].sw);
		web[y[0] % 100 + web[y[0] % 100][y[0] / 100].sw][y[0] / 100 - web[y[0] % 100][y[0] / 100].sw].p = '3';
		web[y[0] % 100 + web[y[0] % 100][y[0] / 100].sw][y[0] / 100 - web[y[0] % 100][y[0] / 100].sw].pw = web[y[0] % 100][y[0] / 100].sw;
	}
	if ((web[y[0] % 100][y[0] / 100].se >0) && (web[y[0] % 100 + web[y[0] % 100][y[0] / 100].se][y[0] / 100 + web[y[0] % 100][y[0] / 100].se].p == '.'))
	{
		y.push_back(100 * (y[0] / 100 + web[y[0] % 100][y[0] / 100].se) + y[0] % 100 + web[y[0] % 100][y[0] / 100].se);
		web[y[0] % 100 + web[y[0] % 100][y[0] / 100].se][y[0] / 100 + web[y[0] % 100][y[0] / 100].se].p = '4';
		web[y[0] % 100 + web[y[0] % 100][y[0] / 100].se][y[0] / 100 + web[y[0] % 100][y[0] / 100].se].pw = web[y[0] % 100][y[0] / 100].se;
	}
}

void pram()
{
	if ((web[y[0] % 100][y[0] / 100].n > 0)&&(web[y[0] % 100 - web[y[0] % 100][y[0] / 100].n][y[0] / 100].p == '.'))
	{
		int fdjsio = y[0] % 100 - web[y[0] % 100][y[0] / 100].n, afji = y[0] / 100, safasf = y[0] % 100;
		y.push_back(100 * (y[0] / 100) + y[0] % 100 - web[y[0] % 100][y[0] / 100].n);
		web[y[0] % 100 - web[y[0] % 100][y[0] / 100].n][y[0] / 100 ].p = 's';
		web[y[0] % 100 - web[y[0] % 100][y[0] / 100].n][y[0] / 100].pw = web[y[0] % 100][y[0] / 100].n;
	}
	if ((web[y[0] % 100][y[0] / 100].s > 0) && (web[y[0] % 100 + web[y[0] % 100][y[0] / 100].s][y[0] / 100].p == '.'))
	{
		y.push_back(100 * (y[0] / 100) +y[0] % 100 + web[y[0] % 100][y[0] / 100].s);
		web[y[0] % 100 + web[y[0] % 100][y[0] / 100].s][y[0] / 100].p = 'n';
		web[y[0] % 100 + web[y[0] % 100][y[0] / 100].s][y[0] / 100].pw = web[y[0] % 100][y[0] / 100].s;
	}
	if ((web[y[0] % 100][y[0] / 100].w > 0) && (web[y[0] % 100][y[0] / 100 - web[y[0] % 100][y[0] / 100].w].p == '.'))
	{
		y.push_back(100 * (y[0] / 100 - web[y[0] % 100][y[0] / 100].w)+ y[0] % 100);
		web[y[0] % 100 ][y[0] / 100 - web[y[0] % 100][y[0] / 100].w].p = 'e';
		web[y[0] % 100][y[0] / 100 - web[y[0] % 100][y[0] / 100].w].pw = web[y[0] % 100][y[0] / 100].w;
	}
	if ((web[y[0] % 100][y[0] / 100].e > 0) && (web[y[0] % 100][y[0] / 100 + web[y[0] % 100][y[0] / 100].e].p == '.'))
	{
		y.push_back(100 * (y[0] / 100 + web[y[0] % 100][y[0] / 100].e)+ y[0] % 100);
		web[y[0] % 100][y[0] / 100 + web[y[0] % 100][y[0] / 100].e].p = 'w';
		web[y[0] % 100][y[0] / 100 + web[y[0] % 100][y[0] / 100].e].pw = web[y[0] % 100][y[0] / 100].e;
	}


}

void find_way()
{

	int sy = y.size(), sx = y.size();

	while (y.size() != 0)
	{
		if ((y[0] % 100 == x_end) && (y[0] / 100 == y_end))
		{
			break;
		}
		extra();
		if ((y[0]%100 == x_end) && (y[0]/100 == y_end))
		{
			break;
		}
		extra_diag();
		if ((y[0]%100 == x_end) && (y[0]/100 == y_end))
		{
			break;
		}
		pram();
		diag();

	
		y.erase(y.begin());
	}
	if (y.size() == 0)
	{
		cout << "NO WAY" << endl;
	}
	else
	{
		way();
		cout << "WAY FOUND" << endl;
	}
}

int main()
{

	out_web();
	for (int i = 0; i < N + 2; i++)
	{
		web[i][0].a = 'b';
		web[i][M + 1].a = 'b';
	}
	for (int i = 0; i < M + 2; i++)
	{
		web[0][i].a = 'b';
		web[N + 1][i].a = 'b';
	}
	string a;
	while (cin >> a)
	{
		if (a == "b")
		{
			int x1, y1;
			cin >> x1 >> y1;
			make_barier(x1, y1);
		}
		else if (a == "s")
		{
			cin >> x_start >> y_start;
			y.push_back(100*(y_start)+x_start);
			make_start(x_start, y_start);

		}
		else if (a == "e")
		{
			cin >> x_end >> y_end;
			make_end(x_end, y_end);
		}
		else if (a == "go")
		{
			int sx = y.size(), sy = y.size();
			find_first();

			find_second();
			sx = y.size(), sy = y.size();
			find_diag();
			sx = y.size(), sy = y.size();
			find_way();
			out_web();
		}
		else if (a == "exit")
		{
			break;
		}
		else
		{
			out_web();
			cout << "error" << endl;
		}
	}
	return 0;
}

