#Compilier
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = tic_tac_toe
SRCS = GameMain.cc Game.cc Board.cc MoveStrategy.cc Player.cc
OBJS = $(SRCS:.cc=.o)


# Rule to compile .cpp files into .o files
%.cpp: %.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	rm -rf $(OBJS)

