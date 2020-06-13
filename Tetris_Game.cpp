void Tetris_Game::pause_() {//玩家界面显示游戏暂停
	//player1
	gotoxy(15, 15);
	cout << "游戏暂停";
	gotoxy(86, 15);
	cout << "游戏暂停";
	char ch;
	while (1)
	{
		while (1)
		{
			if (_kbhit())
			{
				ch = _getch(); break;
			}
		}
		if (ch == 32)//按空格解除暂停 
			break;
	}
	//清楚暂停的信息 
	for (int i = 15; i < 25; i++)
	{
		gotoxy(i, 15); cout << ' ';
	}
	for (int i = 86; i < 96; i++)
	{
		gotoxy(i, 15); cout << ' ';
	}
}
void Tetris_Game::end1_(){
	for(int i=4;i<=28;i++)
	{
		for(int j=3;j<=35;j++)
		{
			gotoxy(j,i);
			cout<<" ";
		}
	 } 
	 for(int i=4;i<=28;i++)
	{
		for(int j=74;j<=106;j++)
		{
			gotoxy(j,i);
			cout<<" ";
		}
	 } 
	gotoxy(15, 14);
	cout << "You Lose!"; 
	gotoxy(15, 16);
	cout << "Game Over";
	gotoxy(86, 14);
	cout << "You Win!"; 
	gotoxy(86, 16);
	cout << "Game Over";
}
void Tetris_Game::end2_(){
	for(int i=4;i<=28;i++)
	{
		for(int j=3;j<=35;j++)
		{
			gotoxy(j,i);
			cout<<" ";
		}
	 }
	 for(int i=4;i<=28;i++)
	{
		for(int j=74;j<=106;j++)
		{
			gotoxy(j,i);
			cout<<" ";
		}
	 }  
	gotoxy(15, 14);
	cout << "You Win!"; 
	gotoxy(12, 16);
	cout << "Game Over";
	gotoxy(86, 14);
	cout << "You Lose!"; 
	gotoxy(85, 16);
	cout << "Game Over";
}
