#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
namespace tictactoe{
	class board{
		bool isNum(const std::string& s);
	public: 
		board(int board_size = 3);
		std::string getItem(int pos) const;
		std::string getItem(int row, int col) const;
		void print();
		size_t getSize() const {return size;}
		bool xWin();
		bool oWin();
		bool xInsert(int pos);
		bool xInsert(int row, int col);
		bool oInsert(int pos);
		bool oInsert(int row, int col);

	private:
		std::string **b;
		size_t size;
	};
	std::ostream& operator << (std::ostream& out, const board& b);
}
#endif