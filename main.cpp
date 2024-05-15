#include "functions.h"

int main() {
	makegrid maze(2234);
	maze.setpath(0 , 0);
	maze.putwall();
	maze.display();
}
