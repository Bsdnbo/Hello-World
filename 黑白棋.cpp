#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//声明本程序中用到的变量
const int chessboard_size = 8;
char chessboard[chessboard_size][chessboard_size];

int counter;
int playerid;
int playercount1;
int playercount2;
//打印棋盘需要的要素
char chessmap_[4][40] = {
	"     a   b   c   d   e   f   g   h\n",
	"   ┏━┯━┯━┯━┯━┯━┯━┯━┓\n",
	"   ┠─┼─┼─┼─┼─┼─┼─┼─┨\n",
	"   ┗━┷━┷━┷━┷━┷━┷━┷━┛\n"
};
//声明本程序中用到的函数
void welcome();
void menu();
void initial();
void print();
bool legalwithpostion(int x, int y, int xoffset, int yoffset, int legal);
bool illegal(int x, int y);
void reversal(int x, int y);
bool skip();
void input();
bool gameover();
void game();
//欢迎界面
void welcome()
{
	printf("□■■■■■■■■■□□□□□□■□□□□□□□□□■□□■□□□■□\n");
	printf("□■□□□■□□□■□□□□□■□□□□□□□□□□■□□■□□□■□\n");
	printf("□■□■□■□■□■□□□■■■■■■■■■□□□□■□■■■■■■■\n");
	printf("□■□□□■□□□■□□□■□□□□□□□■□□■■■■□■□□□■□\n");
	printf("□■■■■■■■■■□□□■□□□□□□□■□□□□■□□■■■■■□\n");
	printf("□□□□□■□□□□□□□■□□□□□□□■□□□■■□□■□□□■□\n");
	printf("□■■■■■■■■■□□□■■■■■■■■■□□□■■■□■■■■■□\n");
	printf("□□□□□■□□□□□□□■□□□□□□□■□□■□■□□■□□□■□\n");
	printf("■■■■■■■■■■■□□■□□□□□□□■□□□□■□■■■■■■■\n");
	printf("□□□□□□□□□□□□□■□□□□□□□■□□□□■□□□□□□□□\n");
	printf("□■□■□□■□□■□□□■■■■■■■■■□□□□■□□■□□□■□\n");
	printf("■□□□■□□■□□■□□■□□□□□□□■□□□□■□■□□□□□■\n");
	printf("                                                  信科基佬 ♂ 友情出品\n");
	system("pause");
}

//选取菜单界面
void menu()
{
	system("cls");
	printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("★                                                                            ★\n");
	printf("★                          益智游戏——黑白棋                                ★\n");
	printf("★                                                                            ★\n");
	printf("★     1.开始新游戏；                                                         ★\n");
	printf("★                                                                            ★\n");
	printf("★     2.读档；                                                               ★\n");
	printf("★                                                                            ★\n");
	printf("★                                                                            ★\n");
	printf("★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("**************************键入命令序号，按Enter确认*****************************\n");
	system("pause");//临时使用pause，应为输入模式的步骤
}

void initial()
{
	int i, j;
	counter = 4;
	playerid = 0;
	playercount1 = 0;
	playercount2 = 0;
	for (i = 0; i < chessboard_size; i++)
	{
		for (j = 0; j < chessboard_size; j++)
		{
			chessboard[i][j] = '+';
		}
	}
	chessboard[chessboard_size / 2 - 1][chessboard_size / 2 - 1] = 1;
	chessboard[chessboard_size / 2][chessboard_size / 2] = 1;
	chessboard[chessboard_size / 2 - 1][chessboard_size / 2] = 2;
	chessboard[chessboard_size / 2][chessboard_size / 2 - 1] = 2;
}

void print()
{

/*	int i, j;
	printf("  a b c d e f g h\n");
	for (i = 0; i < chessboard_size; i++)
	{
		printf("%c ", i + 'a');
		for (j = 0; j < chessboard_size; j++)
		{
			printf("%c", chessboard[i][j]);
			if (j != chessboard_size - 1)
			{
				printf("-");
			}
		}
		printf("\n");
	}*/
	int tmpplayercount1 = 0, tmpplayercount2 = 0;
	for (size_t i = 0; i < chessboard_size; i++)
	{
		for (size_t j = 0; j < chessboard_size; j++)
		{
			if (chessboard[i][j] == 1)
			{
				tmpplayercount1++;
			}
			else if (chessboard[i][j] == 2)
			{
				tmpplayercount2++;
			}
		}
	}
	printf("%s", chessmap_[0]);
	for (int i = 1; i <= 8; ++i)
	{
		if (i == 1)
			printf("%s", chessmap_[1]);
		else
			printf("%s", chessmap_[2]);
		printf(" %d ┃", i);
			for(int j = 1; j <= 8; ++j)
			{
				if (j != 8)
				{
					if (chessboard[i - 1][j - 1] == 1)
						printf("○│");
					else if (chessboard[i - 1][j - 1] == 2)
						printf("●│");
					else
						printf("　│");
				}

				else if (j == 8 && i == 4)
				{
					if (chessboard[i - 1][j - 1] == 1)
						printf("○┃              Player 1:  %d \n", tmpplayercount1);
					else if (chessboard[i - 1][j - 1] == 2)
						printf("●┃              Player 1:  %d \n", tmpplayercount1);
					else
						printf("　┃              Player 1:  %d \n", tmpplayercount1);
				}
				else if (j == 8 && i == 5)
				{
					if (chessboard[i - 1][j - 1] == 1)
						printf("○┃              Player 2:  %d \n", tmpplayercount2);
					else if (chessboard[i - 1][j - 1] == 2)
						printf("●┃              Player 2:  %d \n", tmpplayercount2);
					else
						printf("　┃              Player 2:  %d \n", tmpplayercount2);
				}
				else
				{
					if (chessboard[i - 1][j - 1] == 1)
						printf("○┃\n");
					else if (chessboard[i - 1][j - 1] == 2)
						printf("●┃\n");
					else
						printf("　┃\n");
				}
			}


	}
	printf("%s", chessmap_[3]);


}

bool legalwithpostion(int x, int y, int xoffest, int yoffset, int legal)
{
	int self = playerid + 1;
	int emulant = (playerid + 1) % 2 + 1;
	x += xoffest;
	y += yoffset;
	if (x < 0 || x >= chessboard_size || y < 0 || y >= chessboard_size)
	{
		return 0;
	}
	if (chessboard[x][y] == emulant)
	{
		legal = 1;
		return legalwithpostion(x, y, xoffest, yoffset, legal);
	}
	else if (chessboard[x][y] == self)
	{
		if (legal == 1)
		{
			return 1;
		}
		return 0;
	}
	else
	{
		return 0;
	}
	return 0;
}

bool illegal(int x, int y)
{
	int i, j, legal;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			legal = 0;
			if (legalwithpostion(x, y, i, j, legal))
			{
				return 0;
			}
		}
	}
	return 1;
}

void reversal(int x, int y)
{
	int i, j, m, n, legal;
	int self = playerid + 1;
	int enemy = (playerid + 1) % 2 + 1;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			legal = 0;
			if (legalwithpostion(x, y, i, j, legal))
			{
				m = x + i;
				n = y + j;
				while (chessboard[m][n] == enemy)
				{
					chessboard[m][n] = self;
					m += i;
					n += j;
				}
			}
		}
	}
}

bool skip()
{
	int i, j;
	for (i = 0; i < chessboard_size; i++)
	{
		for (j = 0; j < chessboard_size; j++)
		{
			if (chessboard[i][j] != '+')
			{
				continue;
			}
			if (!illegal(i, j))
			{
				return 0;
			}
		}
	}
	playerid = (playerid + 1) % 2;
	return 1;
}

void input()
{
	char ix, iy;
	int x, y;
	printf("Player 1 : ○\n\n");
	printf("Player 2 : ●\n");
	printf("------------\n");
	printf("Player %d :", playerid+1);
	scanf("%c%c", &ix, &iy);
	getchar();
	x = ix - '1';
	y = iy - 'a';
	while (x < 0 || x >= chessboard_size || y < 0 || y >= chessboard_size || chessboard[x][y] != '+' || illegal(x, y))
	{
		printf("The postion is illegal!!!\nPlease input again: ");
		scanf("%c%c", &ix, &iy);
		getchar();
		x = ix - '1';
		y = iy - 'a';
	}
	chessboard[x][y] = playerid + 1;
	reversal(x, y);
	counter++;
	playerid = (playerid + 1) % 2;
}

bool gameover()
{
	int i, j;
	if (counter >= chessboard_size * chessboard_size)
	{
		system("cls");
		print();
		for (i = 0; i < chessboard_size; i++)
		{
			for (j = 0; j < chessboard_size; j++)
			{
				if (chessboard[i][j] == 1)
				{
					playercount1++;
				}
				else if (chessboard[i][j] == 2)
				{
					playercount2++;
				}
			}
		}
		printf("player 1 score: %d!!\n", playercount1);
		printf("player 2 score: %d!!\n", playercount2);
		if (playercount1 > playercount2)
		{
			printf("player 1 win!!\n");
		}
		else if (playercount1 < playercount2)
		{
			printf("player 2 win!!\n");
		}
		else
		{
			printf("draw game!!\n");
		}
		return 1;
	}
	return 0;
}


void game()
{
	welcome();
	menu();
	initial();
	while (!gameover())
	{
		system("cls");
		print();
		if (skip())
		{
			continue;
		}
		else
		{
			input();
		}
	}
}

int main()
{
	char ch = 'y';
	while (1)
	{
		game();
		getchar();
		printf("continue? (y/n):");
		ch = getchar();
		if (ch == 'n')
		{
			break;
		}
	}
	return 0;
}
