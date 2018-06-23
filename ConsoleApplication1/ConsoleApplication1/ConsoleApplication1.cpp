// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

const int N = 5, M = 5;


struct Point
{
	int n = 0, ne = 0, e = 0, se = 0, s = 0, sw = 0, w = 0, nw = 0;
	char a = '.';

};

Point web[N+2][M+2];

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

void make_start(int x_start, int y_start)
{
	web[x_start][y_start].a = 's';

	out_web();

}
void make_end(int x_end, int y_end)
{
	web[x_end][y_end].a = 'e';
	out_web();
}

void find_first()
{
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if ((web[i][j].a != 'b') &&
				(((web[i + 1][j + 1].a == 'b') && (web[i + 1][j].a != 'b') && (web[i][j + 1].a != 'b'))||
				((web[i + 1][j - 1].a == 'b') && (web[i + 1][j].a != 'b') && (web[i][j - 1].a != 'b')) || 
					((web[i - 1][j - 1].a == 'b') && (web[i - 1][j].a != 'b') && (web[i][j - 1].a != 'b')) || 
					((web[i - 1][j + 1].a == 'b') && (web[i - 1][j].a != 'b') && (web[i][j + 1].a != 'b'))))
			{
				web[i][j].a = '@';
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
			else if (web[i][j].a == '@')
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
		for (int j = M+1; j >= 1; j--)
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
			else if (web[i][j].a == '@')
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
		int k = 0, kb=0;
		bool c = 0, cb=0;
		for (int i = N+1; i >= 1; i--)
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
			else if (web[i][j].a == '@')
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
			else if (web[i][j].a == '@')
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
	for (int i = 0; i <= N+1; i++)//NW //SE------------------------------------------------------------------------------------------------------------
	{
		int k1 = 0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,k8=0;
		bool c1 = 0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0;
		int bk1 = 0, bk2 = 0, bk3 = 0, bk4 = 0, bk5 = 0, bk6 = 0, bk7 = 0, bk8 = 0;
		bool bc1 = 0, bc2 = 0, bc3 = 0, bc4 = 0, bc5 = 0, bc6 = 0, bc7 = 0, bc8 = 0;
		for (int j = 0; j <= M - i + 2; j++)
		{
			//k3++;
		//	web[N - j + 1][N - (i + j) + 2].se = k3;
			if (web[j][i + j].a == 'b')//NW-----------------------------------------------------------------
			{
				c1 = 0;
				k1 = 1;
				bc1 = 1;
				bk1 = 0;
			}
			else if ((web[j][i + j].w>0)||(web[j][i + j].n>0)|| (web[j][i + j].a=='@'))
			{
				if (bc1)
				{
					web[j][i + j].nw = bk1;
					bk1--;

				}
				else 
				web[j][i + j].nw = k1;
				
				c1 = 1;
				k1 = 1;
				bc1 = 0;
			}
			else if (c1)
			{
				
				web[j][i + j].nw = k1;
				k1++;
			}
			else if (bc1)
			{
				web[j][i + j].nw = bk1;
				bk1--;

			}

			if (web[i+j][j].a == 'b')//----------------------------------------------------------------------------------------------------------
			{
				c2 = 0;
				k2 = 1;
				bc2 = 1;
				bk2 = 0;
			}
			else if ((web[i + j][j].w>0) || (web[i + j][j].n>0) || (web[i + j][j].a == '@'))
			{
				if (bc2)
				{
					web[i + j][j].nw = bk2;
					bk2--;

				}
				else
					web[i + j][j].nw = k2;
				c2 = 1;
				bc2 = 0;
				k2 = 1;
			}
			else if (c2)
			{
				
				web[i + j][j].nw = k2;
				k2++;
			}	
			else if (bc2)
			{
				web[i + j][j].nw = bk2;
				bk2--;

			}

			

			if (web[N-j+1][N-(i + j)+2].a == 'b')//SE--------------------------------------------------------------------------
			{
				c3 = 0;
				k3 = 1;
				bc3 = 1;
				bk3 = 0;
			}
			else if ((web[N - j + 1][N - (i + j) + 2].s>0) || (web[N - j + 1][N - (i + j) + 2].e>0) || (web[N - j + 1][N - (i + j) + 2].a == '@'))
			{
				if(bc3)
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
			
			if (web[N-(i + j)+2][N-j+1].a == 'b')//+-------------------------------------------------------------------------------------------
			{
				c4 = 0;
				k4 = 1;
				bc4 = 1;
				bk4 = 0;
			}
			else if ((web[N - (i + j) + 2][N - j + 1].e>0) || (web[N - (i + j) + 2][N - j + 1].s>0) || (web[N - (i + j) + 2][N - j + 1].a == '@'))
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
			else if ((web[j][N - (i + j) + 2].n>0) || (web[j][N - (i + j) + 2].e>0) || (web[j][N - (i + j) + 2].a == '@'))
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
			else if ((web[N - (i + j) + 2][j].s>0) || (web[N - (i + j) + 2][j].w>0) || (web[N - (i + j) + 2][j].a == '@'))
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

			if (web[j + i][N - (j ) + 1].a == 'b')//NE ------------------------------------------------------------------------
			{
				c7 = 0;
				k7 = 0;
				bc7 = 1;
				bk7 = 0;
			}
			else if ((web[j + i][N - (j ) + 1].n>0) || (web[j + i][N - (j ) + 1].e>0) || (web[j + i][N - (j ) + 1].a == '@'))
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

				web[j + i][N - (j ) + 1].ne = k7;
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
			else if ((web[N - (j)+1][j + i].s>0) || (web[N - (j)+1][j + i].w>0) || (web[j + i][N - (j)+1].a == '@'))
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
	}
}

int main()
{
	int x_start = 1, y_start = 1, x_end = N, y_end = M;
	out_web();
	for (int i = 0; i < N+2; i++)
	{
		web[i][0].a = 'b';
		web[i][M+1].a = 'b';
	}
	for (int i = 0; i < M + 2; i++)
	{
		web[0][i].a = 'b';
		web[N+1][i].a = 'b';
	}
	string a;
	while (cin >> a)
	{
		if (a == "b")
		{
			int x, y;
			cin >> x >> y;
			make_barier(x, y);
		}
		else if (a == "s")
		{
			cin >> x_start >> y_start;
			make_start(x_start, y_start);

		}
		else if (a == "e")
		{
			cin >> x_end >> y_end;
			make_end(x_end, y_end);
		}
		else if (a == "go")
		{
			find_first();
			find_second();
			find_diag();
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

