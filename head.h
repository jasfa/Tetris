#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<winuser.h> 
using namespace std;
int block[7][4][4][4];//block[方块种类][4种变形][][] 
#define N 100
int map1[N][N]={0};
int map2[N][N]={0}; 
string name1, name2; 
int gg1=0,gg2=0,score1=0,score2=0;
void gotoxy(int x, int y) {//gotoxy（x，y）将光标移动到指定行y和列x
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//两个参数分别是指定哪个窗体，具体位置
}
