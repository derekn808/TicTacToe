#include "tictactoe.h"
#include <stdlib.h>
namespace tictactoe{
	board::board(int board_size){
		size = board_size;

		b = new std::string*[board_size];
		for(int i = 0; i < board_size; ++i)
    		b[i] = new std::string[board_size];
    	
		for(int i = 0; i < board_size; ++i){
			for(int j = 0; j < board_size; ++j){
				std::string k = std::to_string(((i * board_size) + j));
				b[i][j] = k;
			}
		}
	}
	bool board::isNum(const std::string& s){
	    std::string::const_iterator it = s.begin();
	    while (it != s.end() && std::isdigit(*it)) ++it;
	    return !s.empty() && it == s.end();
	}
	
	std::string board::getItem(int pos) const{
		int row = pos / size;
		int col = pos % size;
		return b[row][col];
	}
	
	std::string board::getItem(int row, int col) const{
		return b[row][col];
	}

	void board::print(){
		for(int i = 0; i < getSize(); ++i){
			for(int j = 0; j < getSize(); ++j){
				std::cout << b[i][j];
			}
		}
	}

	bool board::xWin(){
		//Horizontal Win
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				if(b[i][j] != "X")
					break;
				if(j == (size-1))
					return true;
			}
		}

		//Vertical Win
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j){
				if(b[j][i] != "X")
					break;
				if(j == (size-1))
					return true;
			}
		
		//Top Left to Bottom Right Diagonal Win
		for(int i = 0; i < size; ++i){
			if(b[i][i] != "X")
				break;
			if(i == (size-1))
				return true;
		}
 
		//Top Right to Bottom Left Diagonal Win
		for(int i = 0; i < size; ++i){
			if(b[(size-1)-i][i] != "X")
				break;
			if(i == (size-1))
				return true;
		}

		return false;
	}

	bool board::oWin(){
		//Horizontal Win
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				if(b[i][j] != "O")
					break;
				if(j == (size-1))
					return true;
			}
		}

		//Vertical Win
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j){
				if(b[j][i] != "O")
					break;
				if(j == (size-1))
					return true;
			}
		
		//Top Left to Bottom Right Diagonal Win
		for(int i = 0; i < size; ++i){
			if(b[i][i] != "O")
				break;
			if(i == (size-1))
				return true;
		}
 
		//Top Right to Bottom Left Diagonal Win
		for(int i = 0; i < size; ++i){
			if(b[(size-1)-i][i] != "O")
				break;
			if(i == (size-1))
				return true;
		}

		return false;
	}

	bool board::xInsert(int pos){
		int row = pos / size;
		int col = pos % size;
		if(isNum(b[row][col])){
			b[row][col] = "X";
			return true;
		} 
		return false;
	}

	bool board::xInsert(int row, int col){
		if(isNum(b[row][col])){
			b[row][col] = "X";
			return true;
		} 
		return false;
	}

	bool board::oInsert(int pos){
		int row = pos / size;
		int col = pos % size;
		if(isNum(b[row][col])){
			b[row][col] = "O";
			return true;
		} 
		return false;
	}

	bool board::oInsert(int row, int col){
		if(isNum(b[row][col])){
			b[row][col] = "X";
			return true;
		} 
		return false;
	}

	std::ostream& operator << (std::ostream& out, const board& b){
		for(int i = 0; i < b.getSize(); ++i){
			out << std::endl;
			for(int j = 0; j < b.getSize(); ++j){
				out << "+---";
			}
			out << "+" << std::endl << "|";

			for(int j = 0; j < b.getSize(); ++j){
				std::string item = b.getItem(i,j);
				int len = item.length();
				if(len <= 1)
					out <<std::setw(2)<< item << std::setw(2) << "|";
				else if(len == 2)
					out <<std::setw(1)<< item << std::setw(2) << "|";
				else if (len == 3)
					out <<std::setw(0)<< item << std::setw(1) << "|";
			}
		}

		out << std::endl;
		for(int j = 0; j < b.getSize(); ++j){
			out << "+---";
		}
			out << "+";

		out << std::endl;
		return out;
	}
}