int main() {
	Tetris_xuanran t;
	t.Welcome();
	Sleep(2000);
	t.Setname();
	Sleep(1000);
	t.SetFrame();
	Tetris_Game t2;
	/*t2.pause_();*/
	Sleep(1000);
	Tetris_Player1 player1(1, 16);
	Tetris_Player2 player2(1, 87);
	player1.create_block();	
	player2.create_block();	
	player1.forecast_block();
	player2.forecast_block();
	Sleep(2000);
	player1.nexttonow();
	player2.nexttonow();
	player1.print_block();
	player2.print_block();
	player1.clear_forecast();
	player2.clear_forecast();
	player1.create_block();	
	player2.create_block();	
	player1.forecast_block();
	player2.forecast_block();
	int i=0;
	while(1)
	{
		player1.fall_block();
		player2.fall_block();
		if(gg1==1)
		{
			t2.end1_() ;
			break;
		}
			
		if(gg2==2)
		{
			t2.end2_() ;
			break;
		}
			
			/*else 
			{
				
				if(player1.fall_block()==1)
				{
					Tetris_Player1 player1(1, 16);
					player1.create_block();	
					player1.forecast_block();
					Sleep(2000);
					player1.print_block();
					player1.fall_block();
			}
				if(player2.fall_block()==1)
				{
					Tetris_Player2 player2(1,87);
					player2.create_block();	
					player2.forecast_block();
					Sleep(2000);
					player2.print_block();
					player2.fall_block();
				}
			}
			i++;*/
		}	
	gotoxy(1, 40);
	return 0;
}

