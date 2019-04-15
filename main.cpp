/*
//	The UI for the game.
//	Takes in the user's inputs and calls the proper functions
//	to create the board and fills it in based on inputs.
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include “tictactoe.h”

int main()
{
	int board_size;
	int player = 1;
	int turns = 1;
	cout << “Tic Tac Toe” << endl;
	cout << “Player 1 is X” << endl;
	cout << “Player 2 is O” << endl;
	cout << “Enter number of squares you want in a row (i.e. 3 will make a 3x3 board):” <<endl;
	cin >> board_size;
	tictactoe::tictactoe game(board_size);
	int max=board_size^2;
	int min=((board_size*2)-1);
	int pos;
	while(turns<=max)
	{
		game.printBoard();
		std::cout << “Turn number: “ << turns << “\n” << “It is Player “ << player << “‘s turn” <<std::endl
		cout << “Where do you want to place your marker?” << endl;
		cin >> pos;
		while(game.isMarked(pos)==true)
		{
			cout << “Square is already marked. Please input new location.” << endl;
			cin >> pos;
		}
	if(player==1)
	{
		game.xInsert(pos);
	} 
	else if(player==2)
	{
		game.oInsert(pos);
	}
		
		if(turns>=min)
		{
			if(game.xWin == true)
			{
				game.printBoard();
				cout<< “Player 1 Wins!” << endl;
				break;
			}
			if(game.oWin == true)
			{
				game.printBoard();
				cout<< “Player 2 Wins!” << endl;
				break;
			}
		}
		if(turns==max)
		{
			game.printBoard();
			cout << “It’s a tie.” << endl;
			break;
		}
		turns ++;
		if(player==1)
		{
			player++;
		}
		else
		{
			player--;
		}
	}
	return EXIT_SUCCESS;
}