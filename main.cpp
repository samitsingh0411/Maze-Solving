#include "functions.h"

int main() {
	makegrid maze(30);

	int i = 0;
	int j = 0;

	while (i != -7 and j != -7) {
		cords temp_cords = maze.setpath(i, j);
		i = temp_cords.i;
		j = temp_cords.j;
	}

	for (int i = 0; i < maze.n; i += 2) {
		for (int j = 0; j < maze.n; j += 2) {
			maze.putwall(i, j);
		}
	}


	maze.grid[0][2].state = freepath;
	maze.grid[maze.n - 1][maze.n - 2].state = freepath;

	maze.display();


}
