  
CXX		= g++ -std=c++11
CXXFLAGS	= -g -Wall
OBJS		= main.cpp tictactoe.cpp tictactoe.h
PROG		= tictactoe

all:		$(PROG)

$(PROG):	$(OBJS)
		$(CXX) -o $(PROG) $(OBJS)

clean:;		$(RM) $(PROG) core *.o