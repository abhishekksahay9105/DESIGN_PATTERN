#Compilier
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = fds

SRCS = FoodDeliveryMain.cc ContactInfo.cc  Dish.cc FoodDeliverySystem.cc  OrderDB.cc  Render.cc  Resturant.cc
OBJS = $(SRCS:.cc=.o)

# Rule to compile .cpp files into .o files
%.cpp: %.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	rm -rf $(OBJS)

