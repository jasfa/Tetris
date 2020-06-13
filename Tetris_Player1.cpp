void Tetris_Player1::create_block() {
	memset(blocknext, 0, sizeof(blocknext[4][4]));
	srand((unsigned)time(0));
	int t = rand() % 7;
	turn = 0;
	t0 = t; t1 = t0;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			blocknext[i][j] = block[t1][turn][i][j];
		}
	}
}
void Tetris_Player1::remove_block() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wr1 = 0xf5, wr2 = 0xf2, wr3 = 0xfb, wr4 = 0xf3, wr5 = 0xf1;
	int i, j, t = 0;
	gotoxy(ny, nx);
	for (i = nx; i < nx + 4; i++)
	{
		if (this->judgetop_block(nx + t))
		{
			for (j = 0; j < 4; j++)
			{
				if(nx!=3)
				{
					gotoxy(ny+2*j,nx+t);
					//cout << " ";
					if(map1[i][ny+2*j]!=1)
					{
						map1[i][ny+2*j]=0;
						cout<<" ";	
					}
					gotoxy(ny+2*j+1,nx+t);
					//cout << " ";
					if(map1[i][ny+2*j+1]!=1)
					{
						map1[i][ny+2*j+1]=0;
						cout<<" ";	
					}
					SetConsoleTextAttribute(hOut, wr1);
					gotoxy(36,nx+t);cout<<"║" ;
				}
			}
				
		}
		t++;
		gotoxy(ny, nx + t);
	}
}
void Tetris_Player1::print_block() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wr1 = 0xf5, wr2 = 0xf2, wr3 = 0xfb, wr4 = 0xf3, wr5 = 0xf1;
	SetConsoleTextAttribute(hOut, wr4);
	gotoxy(ny, nx);
	int i, j, t = 0;
	for (i = 0; i < 4; i++)
	{
		if (this->judgetop_block(nx + t))
		{
			for (j = 0; j < 4; j++)
			{
				if (blocknow[i][j] == 1)
				{
					SetConsoleTextAttribute(hOut, wr4);
					gotoxy(ny+2*j,nx+t);
					cout << "■";
					map1[nx+i][ny+2*j]=2;
					//cout<<map2[nx+i][ny+2*j]; 
					map1[nx+i][ny+2*j+1]=2;
					//cout<<map2[nx+i][ny+2*j+1];
					SetConsoleTextAttribute(hOut, wr1);
					if((nx-1+i)>=4)
					{
						gotoxy(36,nx+i-1);cout<<"║" ;
					}
				}
				else if (blocknow[i][j] == 0)
				{
					SetConsoleTextAttribute(hOut, wr4);
					//cout << "  ";
					gotoxy(ny+2*j,nx+t);
					if(map1[nx+i][ny+2*j]!=1)
					{
						map1[nx+i][ny+2*j]=0;
						cout << " ";
					}	
					//cout<<map2[nx+i][ny+2*j];
					gotoxy(ny+2*j+1,nx+t);
					if(map1[nx+i][ny+2*j+1]!=1) 
					{
						map1[nx+i][ny+2*j+1]=0;
						cout << " ";
					}
					SetConsoleTextAttribute(hOut, wr1);	
					if((nx-1+i)>=4)
					{
						gotoxy(36,nx+i-1);cout<<"║" ;
					}
					//cout<<map2[nx+i][ny+2*j+1]; 
				 } 
				 
			}
		}
		t++;
		gotoxy(ny, nx + t);
	}
	SetConsoleTextAttribute(hOut, wr4);
	/*for(i=3;i<30;i++)
	{
		for(j=2;j<37;j++)
		{
			cout<<map1[i][j];
		 } 
		 cout<<endl;
	 } 
	 Sleep(1000);*/
}
int Tetris_Player1::readkey() {
	if (_kbhit())
	{
		int op;
		op = _getch();
		int op1 = op;
		if (op1 == 's')
		{
			this->speedfall_block();
			return 1;
		}
		else if (op1 == 'a')
		{
			this->left_block();
			return 2;
		}
		else if (op1 == 'd')
		{
			this->right_block();
			return 3;
		}
		else if (op1 == 'w')
		{
			this->turn_block();
			return 4;
		}
		return 0;
	}
}
void Tetris_Player1::left_block() {
	//if(detectCollision())
	if(judgeleft())
	{
		remove_block();
		this->ny -= 2;
		this->nx += 1; 
		print_block();
	}	
}
void Tetris_Player1::right_block() {
	//if(detectCollision())
	if(judgeright())
	{
		remove_block();
		this->ny += 2;
		this->nx += 1; 
		print_block();
	}
}
int Tetris_Player1::fall_block() {
	while (1)
	{
		DWORD timetmp = GetTickCount();
		if (timetmp - time_now >= 850)
		{
			time_now = timetmp;
			if (this->judgebottom(nx)&&this->judgebottom_block()) 
			{
				this->normalfall_block();
				break;
			}
			else 
			{;
				this->markmap() ;
				this->gameover() ;
				this->clear_line() ;
				this->nx = 1;this->ny = 16;
				this->time_now = 0;
				Sleep(2000);
				this->nexttonow();
				this->print_block();
				this->clear_forecast();
				this->create_block();	
				this->forecast_block();
				break;
			}
			
		}
		break;
	}
	
	return 1;
}
void Tetris_Player1::normalfall_block() {
	remove_block();
	if (readkey()>0){}
	else this->nx += 1;
	print_block();
}	
void Tetris_Player1::speedfall_block() {
	if(detectCollision())
	{
		remove_block();
		this->nx += 2;
		print_block();
	}	
}
void Tetris_Player1::turn_block() {
	remove_block();
	if (this->turn < 3) this->turn++;
	else if (this->turn == 3) this->turn = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->blocknow[i][j] = block[t1][this->turn][i][j];
		}
	}
	//Sleep(1000);
	print_block();
}
bool Tetris_Player1::judgetop_block(int xn) {
	if (xn > 3) return true;
	else return false;
}
bool Tetris_Player1::judgebottom(int xn) {
	if (xn > 24) return false;
	else return true;
}
bool Tetris_Player1::judgebottom_block(){
	int x=nx+1;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(blocknow[i][j]==1)//有方块
			{
				if(map1[x+i][ny+2*j]==1&&map1[x+i][ny+2*j+1]==1&&(nx+i)>=1)
				{
					return false;
				 } 
			} 
		}
	}
	return true;
}
void Tetris_Player1::markmap(){
	int x=nx,y=ny,i,j,t=0;
	gotoxy(y,x);
	for (i = 0; i < 4; i++)
	{
			for (j = 0; j < 4; )
			{
				if (blocknow[i][j] == 1)
				{
					//cout << "■";
					map1[x+i][y+2*j]=1;
					//cout<<map1[x+i][y+2*j]; 
					map1[x+i][y+2*j+1]=1;
					//cout<<map1[x+i][y+2*j+1]; 
				}
				/*else if (blocknow[i][j] == 0)
				{
					//cout << "  ";
					if(map1[nx+i][ny+2*j]!=1)
						map1[nx+i][ny+2*j]=0;
					cout<<map1[nx+i][ny+2*j]; 
					if(map1[nx+i][ny+2*j+1]!=1)
						map1[nx+i][ny+2*j+1]=0;
					cout<<map1[nx+i][ny+2*j+1]; 
				 }*/ 
				 j++;
				 gotoxy(y+j*2,x+t);				
		}
		t++;
		gotoxy(y, x + t);
	}	
}
void Tetris_Player1::clear_line() {
	int i,j,flag,line;
	/*gotoxy(4,15); 
	i=15;
	for(j=4;j<36;j++)
	{
		map1[i][j]=1;
		cout<<map1[i][j];
	 } */
	for(i=3;i<=28;i++)
	{
		flag=1;
		for(j=4;j<36;j++)
		{
			if(map1[i][j]!=1)
			flag=0;
		}
		if(flag==1)
		{
			line=i;
			break;
		}
	}
	if(flag==1)
	{
		for(i=line;i>=3;i--)
		{
			for(j=4;j<36;j++)
			{
				map1[i][j]=map1[i-1][j];
			}
		}
		gotoxy(4,line);	
		for(i=line;i>=4;)
		{
			for(j=4;j<36;j++)
			{
				if(map1[i][j]!=1)
					cout<<" ";
				else if(map1[i][j]==1)
				{
					cout<<"■" ;
					j++;
				}
				//cout<<map2[i][j];	
			}
			i--;
			gotoxy(4,i);	
		}
	}
}

bool Tetris_Player1::judgeleft(){
	int y=ny-2;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(blocknow[i][j]==1)//有方块
			{
				if(map1[nx+i][y+j*2]==1&&map1[nx+i][y+2*j+1]==1&&(y+2*j)<4||(y+2*j+1)<4)
				{
					return false;
				 } 
			} 
		}
	}
	return true;
} 
bool Tetris_Player1::judgeright(){
	int y=ny+2;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(blocknow[i][j]==1)//有方块
			{
				if(map1[nx+i][y+j*2]==1&&map1[nx+i][y+2*j+1]==1&&(y+2*j)>35||(y+2*j+1)>35)
				{
					return false;
				 } 
			} 
		}
	}
	return true;
}
bool Tetris_Player1::detectCollision(){
	//发生碰撞返回false 
	//未发生返回true 
	int x=nx+2;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(blocknow[i][j]==1)//有方块 
			{
				if((nx+i)>24||(ny+j)<4||(ny+j)>31)//检查是否越界
				{
					return false;
				}
				else if(map1[x+i][ny+2*j]==1&&map1[x+i][ny+2*j+1]==1&&(nx+i)>=4) //检查map1是否标记过
				{
					return false;
				}
				 
			}
		}
	}
	return true;
}
void Tetris_Player1::forecast_block() {
	memset(blocknext, 0, sizeof(blocknext[4][4]));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			blocknext[i][j] = block[t0][0][i][j];
		}
	}
	int t = 6;
	gotoxy(43, 6);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blocknext[i][j] == 1) cout << "■";
			else cout << "  ";
		}
		t++;
		gotoxy(43, t + 1);
	}
}
void Tetris_Player1::nexttonow()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			blocknow[i][j]=blocknext[i][j];
		}
	}
}
void Tetris_Player1::clear_forecast() {
	int t = 6;
	gotoxy(43, 6);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "  ";
		}
		t++;
		gotoxy(43, t + 1);
	}
}
void Tetris_Player1::gameover() {
	if(!this->judgetop_block(this->nx))
		gg1=1;
}
