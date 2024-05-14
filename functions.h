#include <iostream>

enum state{freepath, wall};

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
	void setpath(int i, int j);
	void putwall();
	void display();

};