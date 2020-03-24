#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "tictactoe.h"
using namespace std;
int main(){
	
	int boardSize;
	bool xTurn = true;
	int turns = 0;

	cout << endl << "2 Player Tic Tac Toe" << endl << endl << endl;
	cout << "Enter a board size: " << endl << "(must be at least 3)" << "(e.g. 3 makes a 3x3 board)" << endl;
	cin >> boardSize;
	assert(boardSize > 2);
	tictactoe::board b(boardSize);
	while(1){
		cout << string(50, '\n');
		cout << b;
		if(xTurn){
			bool inserted = false;
			while(!inserted){
				int pos;
				cout << "X, enter the position you want to insert at: ";
				cin >> pos;
				inserted = b.xInsert(pos);
				xTurn = false;
			}	
		}
		else{
			bool inserted = false;
			while(!inserted){
				int pos;
				cout << "O, enter the position you want to insert at: ";
				cin >> pos;
				inserted = b.oInsert(pos);
				xTurn = true;
			}
		}	
		cout << b;
		turns++;
		if(b.xWin()){
			cout << "X has won!" << endl;
			break;
		}
		else if(b.oWin()){
			cout << "O has won!" << endl;
			break;
		}
		else if(turns == boardSize*boardSize){
			cout << "It's a tie!" << endl;
			break;
		}
	}
	return EXIT_SUCCESS;
}