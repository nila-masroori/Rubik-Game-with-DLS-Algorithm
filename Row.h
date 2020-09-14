#ifndef Row_h
#define Row_h
#include<iostream>

using namespace std;

class Row {
private:
	/* Each row has 2 cubies, a left and a right */
	int left, right;

public:
	Row();//default constructor
	Row(const Row &r);//copy constructor
	Row(int l, int r);
	int getleft() const;//left cubie
	int getright() const;
	void setleft(int c);
	void setright(int c);
	void check_color();
	Row flip();

	bool same(); // whether both cubies are the same color, sets color
	int color; // -1 if !same, color id if same
};
#endif