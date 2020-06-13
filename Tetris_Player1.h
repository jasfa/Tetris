class Tetris_Player1 :public Tetris {//玩家类1 
public:
	int nx, ny;
	int t0, t1;//暂时保存 
	int blocknow[4][4];
	int blocknext[4][4];
	int turn;
	int type;
	DWORD time_now;
	Tetris_Player1()
	{
		nx = 1; ny = 16;
		time_now = 0;
		for (int i = 4; i <= 29; i++)
		{
			map1[i][2] = 1;
			map1[i][3] = 1;
			map1[i][35] = 1;
			map1[i][36] = 1;
		}
		for (int j = 3; j <= 35; j++)
		{
			map1[29][j] = 1;
		}
	}
	Tetris_Player1(int x, int y) :nx(x), ny(y) {}
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
