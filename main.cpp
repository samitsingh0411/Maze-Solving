#include "functions.h"

int main() {
	makegrid maze(60);

	int i = 0;
	int j = 0;

	while (i == -7 and j == -7) {
		cords temp_cords = maze.setpath(i, j);
		i = temp_cords.i;
		j = temp_cords.j;
	}

	maze.putwall();

	maze.display();
}
