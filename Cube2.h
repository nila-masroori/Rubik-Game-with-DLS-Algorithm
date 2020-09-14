#ifndef Cube_h
#define Cube_h
#include "Side.h"
#include "Row.h"
#include<string>
#include <cstdio>
using namespace std;

/* Keep a virtual cube in the program to keep track of the permutations being applied */

class Cube {
private:
	/* Virtual cube contains a side for each side of the actual cube (6 total) */
	Side up, right, left, front, back, down;
	bool solved;

	void createEmpty(); // initializes an empty cube

public:
	Cube();//default constructor
	Cube(const Cube &c);//copy constructor
	Side getSide(int a) const;

	/* Input/Output */
	void set(int side, int a, int b, int c, int d);//setting the numbers of each side 
	void num_assign();
	void displayCube();//showing the colors with char
	void show();
	void show_colored();
	int depth;//for DLS
	/* Validation */
	bool isValid();
	bool isSolved();//equal to the goal_test :D

	/* Permutations */
	void U(); // U clockwise
	void Up(); // U counterclockwise
	

	void R();
	void Rp();
	
	
	void L();
	void Lp();
	
	
	void F();
	void Fp();
	

	void B();
	void Bp();
	

	void D();
	void Dp();

	Cube Rotate(int side,const string r);
	
	
};

/* Algorithm notation: 
 * U, R, L, F, B, D corresponds to the up, right, left, front, back, and down faces.
 * The default is clockwise; ' (prime) denotes counterclockwise.
 */

/* Color notation:
 * 1: orange
 * 2: green
 * 3: white
 * 4: blue
 * 5: red
 * 6: yellow
 */
#endif