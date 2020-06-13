void Tetris_xuanran::Welcome() {
	system("cls");//清屏
	system("color f3");
	for (int i = 1; i <= 46; i += 2)
	{
		Sleep(20);
		gotoxy(i, 1); cout << "■ ";
		gotoxy(i, 26); cout << "■ ";
	}
	for (int i = 2; i <= 25; i++)
	{
		Sleep(10);
		gotoxy(1, i); cout << "■";
		for (int j = 2; j <= 43; j++)
			cout << ' ';
		cout << "■";
	}
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wr1 = 0xf9;
	SetConsoleTextAttribute(hOut, wr1);
	gotoxy(20, 6); cout << "我罗斯方块";
	Sleep(100);
	gotoxy(18, 8); cout << "W e l c o m e " << endl;
	WORD wr2 = 0xf3;
	SetConsoleTextAttribute(hOut, wr2);
	Sleep(100);
	gotoxy(21, 10); cout << "操作方法" << endl;
	//Player1
	Sleep(100);
	gotoxy(15, 12); cout << "Player1";
	gotoxy(15, 14); cout << "w 旋转";
	Sleep(100);
	gotoxy(15, 16); cout << "s 加速下降" << endl;
	Sleep(100);
	gotoxy(15, 18); cout << "a 左移";
	Sleep(100);
	gotoxy(15, 20); cout << "d 右移" << endl;
	//Player2
	Sleep(100);
	gotoxy(27, 12); cout << "Player2";
	gotoxy(27, 14); cout << "↑ 旋转";
	Sleep(100);
	gotoxy(27, 16); cout << "↓ 加速下降" << endl;
	Sleep(100);
	gotoxy(27, 18); cout << "← 左移";
	Sleep(100);
	gotoxy(27, 20); cout << "→ 右移" << endl;
	Sleep(100);
	WORD wr3 = 0xf1;
	SetConsoleTextAttribute(hOut, wr3);
	gotoxy(21, 22); cout << "开始游戏";
	gotoxy(1, 31);
}
void Tetris_xuanran::Setname() {
	system("cls");
	for (int i = 40; i < 71; i += 2)
	{
		Sleep(20);
		gotoxy(i, 3); cout << "★";
		gotoxy(i, 23); cout << "★";
	}
	for (int i = 4; i < 23; i++)
	{
		Sleep(10);
		gotoxy(40, i); cout << "★";
		for (int j = 41; j <= 68; j++)
			cout << ' ';
		cout << "★";
	}
	gotoxy(48, 8); cout << "请输入玩家1的昵称：";
	gotoxy(50, 10);
	//string name1; 
	getline(cin, name1);
	Sleep(20);
	gotoxy(48, 14); cout << "请输入玩家2的昵称：";
	gotoxy(50, 16);
	//string name2; 
	getline(cin, name2);
}
void Tetris_xuanran::SetFrame() {
	system("cls");
	system("color f9");
	gotoxy(48, 1); cout << "我 罗 斯 方 块";
	//Player1方块界面 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wr1 = 0xf5, wr2 = 0xf2, wr3 = 0xfb, wr4 = 0xf3, wr5 = 0xf1;
	SetConsoleTextAttribute(hOut, wr1);
	gotoxy(2, 3); cout << "╔";
	gotoxy(36, 3); cout << "╗";
	gotoxy(2, 29); cout << "╚";
	gotoxy(36, 29); cout << "╝";
	for (int i = 3; i <= 35; i++)
	{
		//Sleep(20); 
		gotoxy(i, 3);
		cout << "═";
		gotoxy(i, 29);
		cout << "═";
	}
	for (int i = 4; i <= 28; i++)
	{
		//Sleep(20);
		gotoxy(2, i);
		cout << "║ ";
		for (int j = 3; j <= 34; j++)
			cout << ' ';
		cout << "║";
	}
	//Player2方块界面 
	gotoxy(73, 3); cout << "╔";
	gotoxy(107, 3); cout << "╗";
	gotoxy(73, 29); cout << "╚";
	gotoxy(107, 29); cout << "╝";
	for (int i = 74; i <= 106; i++)
	{
		//Sleep(20); 
		gotoxy(i, 3); cout << "═";
		gotoxy(i, 29); cout << "═";
	}
	for (int i = 4; i <= 28; i++)
	{
		//Sleep(20);
		gotoxy(73, i); cout << "║ ";
		for (int j = 73; j <= 104; j++)
			cout << ' ';
		cout << "║";
	}
	//Player1玩家界面 
	SetConsoleTextAttribute(hOut, wr2);
	Sleep(20);
	gotoxy(41, 4); cout << "下一个方块";
	Sleep(20);
	gotoxy(38, 5); cout << "╔";
	gotoxy(52, 5); cout << "╗";
	gotoxy(38, 12); cout << "╚";
	gotoxy(52, 12); cout << "╝";
	for (int i = 39; i <= 51; i++)
	{
		Sleep(20);
		gotoxy(i, 5); cout << "═";
		gotoxy(i, 12); cout << "═";
	}
	for (int i = 6; i <= 11; i++)
	{
		Sleep(20);
		gotoxy(38, i); cout << "║ ";
		for (int j = 39; j <= 50; j++)
			cout << ' ';
		cout << "║";
	}
	Sleep(20);
	SetConsoleTextAttribute(hOut, wr5);
	gotoxy(42, 14); cout << "Player1";
	Sleep(20);
	gotoxy(43, 16); cout << name1;
	/*Sleep(20);
	gotoxy(43, 18); cout << "Score";*/
	Sleep(20);
	SetConsoleTextAttribute(hOut, wr4);
	gotoxy(42, 22); cout << "w 旋转";
	gotoxy(42, 24); cout << "s 加速下降" << endl;
	gotoxy(42, 26); cout << "a 左移";
	gotoxy(42, 28); cout << "d 右移" << endl;
	//中间过渡 
	SetConsoleTextAttribute(hOut, wr3);
	for (int i = 3; i <= 29; i++)
	{
		Sleep(20);
		gotoxy(54, i); cout << "★";
	}
	//Player2玩家界面 
	SetConsoleTextAttribute(hOut, wr2);
	Sleep(20);
	gotoxy(59, 4); cout << "下一个方块";
	Sleep(20);
	gotoxy(56, 5); cout << "╔";
	gotoxy(70, 5); cout << "╗";
	gotoxy(56, 12); cout << "╚";
	gotoxy(70, 12); cout << "╝";
	for (int i = 57; i <= 69; i++)
	{
		Sleep(20);
		gotoxy(i, 5);
		cout << "═";
		gotoxy(i, 12);
		cout << "═";
	}
	for (int i = 6; i <= 11; i++)
	{
		Sleep(20);
		gotoxy(56, i);
		cout << "║ ";
		for (int j = 57; j <= 68; j++)
			cout << ' ';
		cout << "║";
	}
	Sleep(20);
	SetConsoleTextAttribute(hOut, wr5);
	gotoxy(60, 14); cout << "Player2";
	Sleep(20);
	gotoxy(61, 16); cout << name2;
	/*Sleep(20);
	gotoxy(61, 18); cout << "Score";*/
	Sleep(20);
	SetConsoleTextAttribute(hOut, wr4);
	gotoxy(60, 22); cout << "↑ 旋转";
	gotoxy(60, 24); cout << "↓ 加速下降" << endl;
	gotoxy(60, 26); cout << "← 左移";
	gotoxy(60, 28); cout << "→ 右移" << endl;
	gotoxy(1, 35);
}
