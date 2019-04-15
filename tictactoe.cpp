#include <stdlib.h>
#include <cassert>
#include “tictactoe.h”
namespace tictactoe
{
	/*Initializes the board*/
	tictactoe::tictactoe(int board_size)
	{	
		assert(board_size>2);		//prevents first player from always winning
		size=board_size;
		board = new std::string *[size];
		for(int i=0; i<size; i++)
		{
			board[i] = new std::string[size]
		}
		for(int i=0; i<size; i++)
		{
			for(int j=0;j<size;j++)
			{
				std::string num= std::to_string(((i*size)+j+1))
				board[i][j]=num;
			}
		}
	}

	/*Prints out the board in its current state*/
	void tictactoe::printBoard()
	{
		for(int i=0; i<size; i++)
		{
			for(j=0; j<size; j++)
			{
				if(j!=(size-1))
				{
					std::cout<< board[i][j] << endl;
				}
				else
				{
					std::cout<< board[i][j] << “ | “ << endl;
				}
			}
			if(i!=(size-1))
			{
				for(int k=0;k<size;k++)
				{
					if(k!=(size-1))
					{
						std::cout<< “---”<< endl;
					}
					else
					{
						std::cout<< “---+” << endl;
					}
				}
			}
}
	}
	
	/*Checks to see if a square is marked*/
	bool tictactoe::isMarked(int pos)
	{
		pos--;
		int row = pos /size;
		int col = pos%size;
		if(strcmp(board[row][col], “X”)==0 || strcmp(board[row][col], “O”)==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*Returns what value is stored in the given square on the board*/
	std::string tictactoe::getSquare(int row, int col)
	{
		return board[row][col];
	}
	
	/*Inserts an X at given position*/
	bool tictactoe::xInsert(int pos)
	{
		pos--;
		int row = pos /size;
		int col = pos%size;
		if(isMarked(pos+1))
		{
			board[row][col] = “X”;
			return true;
		}
		return false;
	}

	/*Inserts an O at given position*/
	bool tictactoe::oInsert(int pos)
	{
		pos--;
		int row = pos /size;
		int col = pos%size;
		if(isMarked(pos+1))
		{
			board[row][col] = “O”;
			return true;
		}
		return false;
	}

	/*Checks for all possible win conditions for X*/
	bool tictactoe::xWin()
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0; j<size; j++)
			{
				if(strcmp(board[i][j], “X”)!=0)
				{
					break;
				}
				if(j==(size)-1)
				{
					return true;
				}
			}
		}

		for(int i=0;i<size;i++)
		{
			for(int j=0; j<size; j++)
			{
				if(strcmp(board[j][i], “X”)!=0)
				{
					break;
				}
				if(j==(size-1))
				{
					return true;
				}
			}
		}

		for(int i=0; i<size; i++)
		{
			(strcmp(board[i][i], “X”)!=0)
			{
				break;
			}
			if(i == (size-1))
			{
				return true;
			}
		}

		for(int i=0; i<size; i++)
		{
			(strcmp(board[size-1-i][i], “X”)!=0)
			{
				break;
			}
			if(i == (size-1))
			{
				return true;
			}
		}
	}
	
	/*Checks for all possible win conditions for O*/
	bool tictactoe::oWin()
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0; j<size; j++)
			{
				if(strcmp(board[i][j], “O”)!=0)
				{
					break;
				}
				if(j==(size)-1)
				{
					return true;
				}
			}
		}

		for(int i=0;i<size;i++)
		{
			for(int j=0; j<size; j++)
			{
				if(strcmp(board[j][i], “O”)!=0)
				{
					break;
				}
				if(j==(size-1))
				{
					return true;
				}
			}
		}

		for(int i=0; i<size; i++)
		{
			(strcmp(board[i][i], “O”)!=0)
			{
				break;
			}
			if(i == (size-1))
			{
				return true;
			}
		}

		for(int i=0; i<size; i++)
		{
			(strcmp(board[size-1-i][i], “O”)!=0)
			{
				break;
			}
			if(i == (size-1))
			{
				return true;
			}
		}
	}
}