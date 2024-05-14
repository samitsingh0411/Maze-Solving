#include <stack>
#include <tuple>
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

void makegrid :: setpath(int i, int j) {
	static std::stack<std::tuple<int, int>> stack;
	grid[i][j].visited = true;
	
	int choice = rand() % 4;

	// check up first
	if (choice == 0) {
		// up
		if (i >= 2 and !grid[i - 2][j].visited) {
			std::tuple<int, int> temp_cords((i - 2), j);
			grid[i][j].up = &grid[i - 2][j];
			stack.push(temp_cords);
			setpath(i - 2, j);
		}

		//down
		else if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			std::tuple<int, int> temp_cords((i + 2), j);
			grid[i][j].down = &grid[i + 2][j];
			stack.push(temp_cords);
			setpath(i + 2, j);
		}

		// right
		else if (j <= (n -  1) - 2 and !grid[i][j + 2].visited) {
			std::tuple<int, int> temp_cords(i, j + 2);
			grid[i][j].right = &grid[i][j + 2];
			stack.push(temp_cords);
			setpath(i, j + 2);
		}

		//left
		else if (j >= 2 and !grid[i][j - 2].visited) {
			std::tuple<int, int> temp_cords(i, j - 2);
			grid[i][j].left = &grid[i][j - 2];
			stack.push(temp_cords);
			setpath(i, j - 2);
		}

		// implies it is boxed in
		else if (!stack.empty()) {
			auto cords = stack.top();
			int x = std::get<0>(cords);
			int y = std::get<1>(cords);
			stack.pop();
			setpath(x, y);
		}

		else {
			return;
		}
	}

	//chekc down first
	if (choice == 1) {
		//down
		if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			std::tuple<int, int> temp_cords((i + 2), j);
			grid[i][j].down = &grid[i + 2][j];
			stack.push(temp_cords);
			setpath(i + 2, j);
		}

		// up
		else if (i >= 2 and !grid[i - 2][j].visited) {
			std::tuple<int, int> temp_cords((i - 2), j);
			grid[i][j].up = &grid[i - 2][j];
			stack.push(temp_cords);
			setpath(i - 2, j);
		}


		// right
		else if (j <= (n - 1) - 2 and !grid[i][j + 2].visited) {
			std::tuple<int, int> temp_cords(i, j + 2);
			grid[i][j].right = &grid[i][j + 2];
			stack.push(temp_cords);
			setpath(i, j + 2);
		}

		//left
		else if (j >= 2 and !grid[i][j - 2].visited) {
			std::tuple<int, int> temp_cords(i, j - 2);
			grid[i][j].left = &grid[i][j - 2];
			stack.push(temp_cords);
			setpath(i, j - 2);
		}

		// implies it is boxed in
		else if (!stack.empty()) {
			auto cords = stack.top();
			int x = std::get<0>(cords);
			int y = std::get<1>(cords);
			stack.pop();
			setpath(x, y);
		}

		else {
			return;
		}
	}

	// check right first
	if (choice == 2) {

		// right
		if (j <= (n - 1) - 2 and !grid[i][j + 2].visited) {
			std::tuple<int, int> temp_cords(i, j + 2);
			grid[i][j].right = &grid[i][j + 2];
			stack.push(temp_cords);
			setpath(i, j + 2);
		}

		// up
		else if (i >= 2 and !grid[i - 2][j].visited) {
			std::tuple<int, int> temp_cords((i - 2), j);
			grid[i][j].up = &grid[i - 2][j];
			stack.push(temp_cords);
			setpath(i - 2, j);
		}

		//down
		else if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			std::tuple<int, int> temp_cords((i + 2), j);
			grid[i][j].down = &grid[i + 2][j];
			stack.push(temp_cords);
			setpath(i + 2, j);
		}


		//left
		else if (j >= 2 and !grid[i][j - 2].visited) {
			std::tuple<int, int> temp_cords(i, j - 2);
			grid[i][j].left = &grid[i][j - 2];
			stack.push(temp_cords);
			setpath(i, j - 2);
		}

		// implies it is boxed in
		else if (!stack.empty()) {
			auto cords = stack.top();
			int x = std::get<0>(cords);
			int y = std::get<1>(cords);
			stack.pop();
			setpath(x, y);
		}

		else {
			return;
		}
	}

	// check left first
	if (choice == 3) {
		//left
		if (j >= 2 and !grid[i][j - 2].visited) {
			std::tuple<int, int> temp_cords(i, j - 2);
			grid[i][j].left = &grid[i][j - 2];
			stack.push(temp_cords);
			setpath(i, j - 2);
		}

		// up
		else if (i >= 2 and !grid[i - 2][j].visited) {
			std::tuple<int, int> temp_cords((i - 2), j);
			grid[i][j].up = &grid[i - 2][j];
			stack.push(temp_cords);
			setpath(i - 2, j);
		}

		//down
		else if (i <= (n - 1) - 2 and !grid[i + 2][j].visited) {
			std::tuple<int, int> temp_cords((i + 2), j);
			grid[i][j].down = &grid[i + 2][j];
			stack.push(temp_cords);
			setpath(i + 2, j);
		}

		// right
		else if (j <= (n - 1) - 2 and !grid[i][j + 2].visited) {
			std::tuple<int, int> temp_cords(i, j + 2);
			grid[i][j].right = &grid[i][j + 2];
			stack.push(temp_cords);
			setpath(i, j - 2);
		}

		// implies it is boxed in
		else if (!stack.empty()) {
			auto cords = stack.top();
			int x = std::get<0>(cords);
			int y = std::get<1>(cords);
			stack.pop();
			setpath(x, y);
		}

		else {
			return;
		}
	}

}

void makegrid::putwall() {
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			if (grid[i][j].up != nullptr) {
				grid[i - 1][j].state = freepath;
			}

			if (grid[i][j].down != nullptr) {
				grid[i + 1][j].state = freepath;
			}

			if (grid[i][j].left != nullptr) {
				grid[i][j - 1].state = freepath;
			}

			if (grid[i][j].right != nullptr) {
				grid[i][j + 1].state = freepath;
			}
		}
	}
}

void makegrid::display() {
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j].state == wall)
				std::cout << "& ";

			else
				std::cout << ". ";

		}
		std::cout << "\n";
	}
}
