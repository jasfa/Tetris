class Tetris_Player2 :public Tetris {//玩家类2 
public:
	int nx, ny;
	int blocknow[4][4];
	int blocknext[4][4];
	int turn;
	int type;
	int t0, t1;
	DWORD time_now;
	Tetris_Player2()
	{
		nx = 1; ny = 87;
		time_now = 0;
		for(int i=4;i<=29;i++)
		{
			map2[i][73]=1;
			map2[i][107]=1;
		 } 
		 for(int j=74;j<=106;j++)
		 {
		 	map2[29][j]=1;
		 }
	}
	Tetris_Player2(int x, int y) :nx(x), ny(y) {}
	void create_block();
	void remove_block();
	void print_block();
	int readkey();
	void left_block();
	void right_block();
	void turn_block();
	void normalfall_block();
	void speedfall_block();
	int fall_block();
	bool judgetop_block(int xn);
	bool judgebottom(int xn);
	bool judgebottom_block();
	void forecast_block();
	void nexttonow();
	void clear_forecast();
	void run();
	bool judgeleft();
	bool judgeright(); 
	bool detectCollision();
	void markmap();
	void clear_line();
	void gameover();
};
