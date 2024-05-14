#include "functions.h"

int main() {
	makegrid maze(40);
	maze.setpath(0 , 0);
	maze.putwall();
	maze.display();
}

