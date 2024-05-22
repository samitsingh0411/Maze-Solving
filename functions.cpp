#include <stack>
#include <tuple>
#include <thread>
#include "functions.h"


cell :: cell() : up(nullptr), down(nullptr), right(nullptr), left(nullptr), state(wall), visited(false){}

makegrid :: makegrid(int n__) : n(n__) {

	if (n__ % 2 == 1) {
		std::cout << "Enter only even numbers: " << std::endl;
		return;
	}

	grid = new cell * [n__];
	for (int i = 0; i < n; i++) {
		grid[i] = new cell[n__];
	}

	for (int i = 0; i < n; i+=2) {
		for (int j = 0; j < n; j+=2) {

			grid[i][j].state = freepath;

		}
	}


}

static std::stack<cords> stack;

 cords makegrid :: setpath(int i, int j) {
	grid[i][j].visited = true;
	int choice = rand() % 4;

	// check up first
	if (choice == 0) {
		// up
		if (i >= 2 and !grid[i - 2][j].visited) {
			cords temp_cords(i - 2, j);
			grid[i][j].up = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}

		//down
		else if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			cords temp_cords(i + 2, j);
			grid[i][j].down = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
			
		}

		// right
		else if (j <= (n -  1) - 2 and !grid[i][j + 2].visited) {
			cords temp_cords(i, j + 2);
			grid[i][j].right = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
			
		}

		//left
		else if (j >= 2 and !grid[i][j - 2].visited) {
			cords temp_cords(i, j - 2);
			grid[i][j].left = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
			
		}

		// implies it is boxed in
		else if (!stack.empty()) {
			cords temp_cords(stack.top().i, stack.top().j);
			stack.pop();
			return temp_cords;
		}

		else {
			return cords(-7, -7);
		}
	}

	//chekc down first
	if (choice == 1) {

		//down
		if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			cords temp_cords(i + 2, j);
			grid[i][j].down = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}

		// up
		else if (i >= 2 and !grid[i - 2][j].visited) {
			cords temp_cords(i - 2, j);
			grid[i][j].up = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}


		// right
		else if (j <= (n - 1) - 2 and !grid[i][j + 2].visited) {
			cords temp_cords(i, j + 2);
			grid[i][j].right = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}

		//left
		else if (j >= 2 and !grid[i][j - 2].visited) {
			cords temp_cords(i, j - 2);
			grid[i][j].left = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}

		// implies it is boxed in
		else if (!stack.empty()) {
			cords temp_cords(stack.top().i, stack.top().j);
			stack.pop();
			return temp_cords;
		}

		else {
			return cords(-7, -7);
		}
	}

	// check right first
	if (choice == 2) {

		// right
		if (j <= (n - 1) - 2 and !grid[i][j + 2].visited) {
			cords temp_cords(i, j + 2);
			grid[i][j].right = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;

		}

		// up
		else if (i >= 2 and !grid[i - 2][j].visited) {
			cords temp_cords(i - 2, j);
			grid[i][j].up = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}

		//down
		else if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			cords temp_cords(i + 2, j);
			grid[i][j].down = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;

		}


		//left
		else if (j >= 2 and !grid[i][j - 2].visited) {
			cords temp_cords(i, j - 2);
			grid[i][j].left = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;

		}

		// implies it is boxed in
		else if (!stack.empty()) {
			cords temp_cords(stack.top().i, stack.top().j);
			stack.pop();
			return temp_cords;
		}

		else {
			return cords(-7, -7);
		}
	}

	// check left first
	if (choice == 3) {

		//left
		if (j >= 2 and !grid[i][j - 2].visited) {
			cords temp_cords(i, j - 2);
			grid[i][j].left = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;

		}

		// up
		else if (i >= 2 and !grid[i - 2][j].visited) {
			cords temp_cords(i - 2, j);
			grid[i][j].up = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;
		}

		//down
		else if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			cords temp_cords(i + 2, j);
			grid[i][j].down = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;

		}

		// right
		else if (j <= (n - 1) - 2 and !grid[i][j + 2].visited) {
			cords temp_cords(i, j + 2);
			grid[i][j].right = &grid[temp_cords.i][temp_cords.j];
			stack.push(temp_cords);
			return temp_cords;

		}


		// implies it is boxed in
		else if (!stack.empty()) {
			cords temp_cords(stack.top().i, stack.top().j);
			stack.pop();
			return temp_cords;
		}

		else {
			return cords(-7, -7);
		}
	}
}

void makegrid::putwall(int i, int j) {

		if (grid[i][j].up != nullptr) {
			grid[i - 1][j].state = freepath;
			grid[i][j].up = nullptr;
		}

		if (grid[i][j].down != nullptr) {
			grid[i + 1][j].state = freepath;
			grid[i][j].down = nullptr;
		}

		if (grid[i][j].left != nullptr) {
			grid[i][j - 1].state = freepath;
			grid[i][j].left = nullptr;
		}

		if (grid[i][j].right != nullptr) {
			grid[i][j + 1].state = freepath;
			grid[i][j].right = nullptr;
		}
	
	
}

void makegrid::display() {
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j].state == wall)
				std::cout << "H ";

			else
				std::cout << "  ";

		}
		std::cout << "\n";
	}


}

void sleep_for(int milisecond) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milisecond));
}

void clear_console() {
	system("cls");
}
