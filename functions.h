#include <iostream>

enum state{freepath, wall};

struct cords {
	int i;
	int j;

	cords(int i, int j) : i(i), j(j){}
};

class cell {
public:
	cell* up;
	cell* down;
	cell* left;
	cell* right;

	state state;
	bool visited;

public: //methods
	cell();
		
};


class makegrid {
public: //variables

	int n;
	cell** grid;

public: //methods

	makegrid(int n__);
	cords setpath(int i, int j);
	void putwall();
	void display();

};