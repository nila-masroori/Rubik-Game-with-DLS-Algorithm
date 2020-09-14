#include "Cube2.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;

Cube::Cube()
{
	createEmpty();
}

void Cube::createEmpty() {
	up.makeBlank();
	right.makeBlank();
	left.makeBlank();
	front.makeBlank();
	back.makeBlank();
	down.makeBlank();
	depth=0;
}

Cube::Cube(const Cube &c) {
	up = c.getSide(1);
	right = c.getSide(4);
	left = c.getSide(2);
	front = c.getSide(3);
	back = c.getSide(6);
	down = c.getSide(5);
	depth=c.depth;
}

Side Cube::getSide(int a) const {
	switch (a) {
	case 1: return up;
	case 4: return right;
	case 2: return left;
	case 3: return front;
	case 6: return back;
	case 5: return down;
	default: cerr << "Copy constructor error." << endl; exit(0);
	}
}

void Cube::set(int side, int a, int b, int c, int d) {
	/* 1 = up, 2 = left, 3 = front, 4 = right, 5 =down, 6 = back */
	switch (side) {
	case 1:
		up.setupper(Row(a, b));
		up.setlower(Row(c, d));
		break;
	case 4:
		right.setupper(Row(a, b));
		right.setlower(Row(c, d));
		break;
	case 2:
		left.setupper(Row(a, b));
		left.setlower(Row(c, d));
		break;
	case 3:
		front.setupper(Row(a, b));
		front.setlower(Row(c, d));
		break;
	case 6:
		back.setupper(Row(a, b));
		back.setlower(Row(c, d));
		break;
	case 5:
		down.setupper(Row(a, b));
		down.setlower(Row(c, d));
		break;
	default: cerr << "This should not be possible."; exit(1);
	}
}

char num2char(int a) {
	switch (a) {
	case 1: return 'o';//orange
	case 2: return 'g';//green
	case 3: return 'w';//white
	case 4: return 'b';//blue
	case 5: return 'r';//red
	case 6: return 'y';//yellow
	default: cerr << "num2char error"; exit(2);
	}
}

void Cube::displayCube() {
	
	cout << endl;
	cout << "        " <<num2char( up.getupper().getleft()) << "   " <<num2char( up.getupper().getright()) << endl<<endl;
	cout << "        " <<num2char( up.getlower().getleft()) << "   " << num2char(up.getlower().getright()) << endl<<endl;
	
	cout << num2char(left.getupper().getleft()) << "   " << num2char(left.getupper().getright()) << "   "
		<< num2char(front.getupper().getleft()) << "   " << num2char(front.getupper().getright()) << "   "
		<< num2char(right.getupper().getleft()) << "   " << num2char(right.getupper().getright())<< "   "
		<< endl<<endl;
	cout << num2char(left.getlower().getleft()) << "   " << num2char(left.getlower().getright()) << "   "
		<< num2char(front.getlower().getleft()) << "   " << num2char(front.getlower().getright()) << "   "
		<< num2char(right.getlower().getleft()) << "   " << num2char(right.getlower().getright()) << "   "
		 << endl<<endl; 
	cout << "        " << num2char(down.getupper().getleft())<< "   " << num2char(down.getupper().getright())<<endl<<endl;
	cout << "        " << num2char(down.getlower().getleft()) << "   " << num2char(down.getlower().getright())<<endl<<endl;
	cout << "        "<< num2char(back.getupper().getleft()) << "   " << num2char(back.getupper().getright())<<endl<<endl;
	cout << "        "<< num2char(back.getlower().getleft()) << "   " << num2char(back.getlower().getright()) << endl<<endl;
	cout << endl;
}
void Cube::num_assign()
{
 
 set(1,0,1,2,3);
 set(4,12,13,14,15);
 set(2,4,5,6,7);
 set(3,8,9,10,11);
 set(6,20,21,22,23);
 set(5,16,17,18,19);
 

}
void Cube::show()
{
	cout << endl;
	cout << "        " << up.getupper().getleft() << "   " << up.getupper().getright() << endl<<endl;
	cout << "        " << up.getlower().getleft() << "   " << up.getlower().getright() << endl<<endl;
	
	cout << left.getupper().getleft() << "   " << left.getupper().getright() << "   "
		<< front.getupper().getleft() << "   " << front.getupper().getright() << "   "
		<< right.getupper().getleft() << "   " << right.getupper().getright()<< "   "
		<< endl<<endl;
	cout << left.getlower().getleft() << "   " << left.getlower().getright() << "   "
		<< front.getlower().getleft() << "   " << front.getlower().getright() << "   "
		<< right.getlower().getleft() << "   " << right.getlower().getright() << "   "
		 << endl<<endl; 
	cout << "        " << down.getupper().getleft()<< "   " << down.getupper().getright()<<endl<<endl;
	cout << "        " << down.getlower().getleft() << "   " << down.getlower().getright()<<endl<<endl;
	cout << "        "<< back.getupper().getleft() << "   " << back.getupper().getright()<<endl<<endl;
	cout << "        "<< back.getlower().getleft() << "   " << back.getlower().getright() << endl<<endl;
	cout << endl;
}

void Cube::show_colored()
{
	
	cout << endl;
	cout << "        " ; up.getupper().check_color(); cout<< endl<<endl;
	cout << "        " ; up.getlower().check_color(); cout << endl<<endl;
	
	 left.getupper().check_color();   cout<< "   ";
		 front.getupper().check_color();  cout << "   ";
		 right.getupper().check_color();  cout<< "   "<< endl<<endl;

	 left.getlower().check_color();   cout<< "   ";
		 front.getlower().check_color();  cout<< "   ";
		 right.getlower().check_color();  cout<< "   "<< endl<<endl; 
		 
	cout << "        " ; down.getupper().check_color();  cout<<endl<<endl;
	cout << "        " ; down.getlower().check_color();  cout<<endl<<endl;
	cout << "        "; back.getupper().check_color();  cout<<endl<<endl;
	cout << "        "; back.getlower().check_color();  cout<< endl<<endl;
	cout << endl;
}

bool Cube::isValid() {
	/* Make sure that there are exactly four of each color */
	int colors[6] = { 0 };
	Side* sides[6];
	sides[1] = &up;
	sides[4] = &right;
	sides[2] = &left;
	sides[3] = &front;
	sides[6] = &back;
	sides[5] = &down;
	for (int i = 0; i < 6; ++i) {
		Side temp = *sides[i];
		colors[temp.getupper().getleft()]++;
		colors[temp.getupper().getright()]++;
		colors[temp.getlower().getleft()]++;
		colors[temp.getlower().getright()]++;
	}
	if (!(colors[1] == 4 && colors[4] == 4 && colors[2] == 4 && colors[3] == 4 && colors[6] == 4 && colors[5] == 4)) {
		return false;
	}

	return true;
}

bool Cube::isSolved() {
	if(up.getlower().getleft()!=0)
		if (up.same() && right.same() && left.same() && front.same() && back.same() && down.same()) 
			return true;
	return false;
}

/* PERMUTATION NOTE:
 * Right-side corresponds with upper and left-side corresponds with lower.
 * When going between non-corresponding halves, flip() must be used to correct the alignment.
 */

void Cube::Up() {
	up.CCW(); // turn clockwise on "up" side
	Row temp = right.getupper(); // save to a temporary row as it will be replaced
	right.setupper(front.getupper());
	front.setupper(left.getupper());
	left.setupper(back.getlower().flip());
	back.setlower(temp.flip());
	cout << "U' ";
}

void Cube::U() {
	up.CW();
	Row temp =right.getupper() ;
	right.setupper(back.getlower().flip());
	back.setlower(left.getupper().flip());
	left.setupper(front.getupper());
	front.setupper(temp);
	
	cout << "U ";
}


void Cube::Rp() {
	right.CCW();
	Row temp = back.getrightside();
	back.setrightside(down.getrightside());
	down.setrightside(front.getrightside());
	front.setrightside(up.getrightside());
	up.setrightside(temp);
	cout << "R' ";
}

void Cube::R() {
	right.CW();
	Row temp = back.getrightside();
	back.setrightside(up.getrightside());
	up.setrightside(front.getrightside());
	front.setrightside(down.getrightside());
	down.setrightside(temp);
	cout << "R ";
}



void Cube::L() {
	left.CW();
	Row temp = down.getleftside();
	down.setleftside(front.getleftside());
	front.setleftside(up.getleftside());
	up.setleftside(back.getleftside());
	back.setleftside(temp);
	cout << "L ";
}

void Cube::Lp() {
	left.CCW();
	Row temp = front.getleftside();
	front.setleftside(down.getleftside());
	down.setleftside(back.getleftside());
	back.setleftside(up.getleftside().flip());
	up.setleftside(temp);
	cout << "L' ";
}


void Cube::F() {
	front.CW();
	Row temp = up.getlower();
	up.setlower(left.getrightside().flip());
	left.setrightside(down.getupper());
	down.setupper(right.getleftside().flip());
	right.setleftside(temp);
	cout << "F ";
}

void Cube::Fp() {
	front.CCW();
	Row temp = up.getlower();
	up.setlower(right.getleftside());
	right.setleftside(down.getupper().flip());
	down.setupper(left.getrightside());
	left.setrightside(temp.flip());
	cout << "F' ";
}



void Cube::B() {
	back.CW();
	Row temp = right.getrightside();
	right.setrightside(down.getlower().flip());
	down.setlower(left.getleftside());
	left.setleftside(up.getupper().flip());
	up.setupper(temp);
	cout << "B ";
}

void Cube::Bp() {
	back.CCW();
	Row temp = left.getleftside();
	left.setleftside(down.getlower());
	down.setlower(right.getrightside().flip());
	right.setrightside(up.getupper());
	up.setupper(temp.flip());
	cout << "B' ";
}



void Cube::D() {
	down.CW();
	Row temp = front.getlower();
	front.setlower(left.getlower());
	left.setlower(back.getupper().flip());
	back.setupper(right.getlower().flip());
	right.setlower(temp);
	cout << "D ";
}

void Cube::Dp() {
	down.CCW();
	Row temp = front.getlower();
	front.setlower(right.getlower());
	right.setlower(back.getupper().flip());
	back.setupper(left.getlower().flip());
	left.setlower(temp);
	cout << "D' ";
}
Cube Cube::Rotate(int side,const string r)//r is for the rotation;side is the number of the side that should be rotated;
{
	 /* 1 = up, 2 = left, 3 = front, 4 = right, 5 =down, 6 = back */
   

    if(r=="cw")//if its clockwise
    {
        switch (side) {
	case 1:
		(*this).U();
		break;
	case 4:
		(*this).R();
		break;
	case 2:
		(*this).L();
		break;
	case 3:
		(*this).F();
		break;
	case 6:
		(*this).B();
		break;
	case 5:
		(*this).D();
		break;
		default:cerr << "Invalid cube.";
			 break;
        }

    }
    else if(r=="ccw")
    {
         switch (side) {
	case 1:
		(*this).Up();
		break;
	case 4:
		(*this).Rp();
		break;
	case 2:
		(*this).Lp();
		break;
	case 3:
		(*this).Fp();
		break;
	case 6:
		(*this).Bp();
		break;
	case 5:
		(*this).Dp();
		break;
		default:cerr << "Invalid cube.";
			 break;
        }
		

    }
    return *this;
}

