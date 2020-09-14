#include "Row.h"

Row::Row(){
	color = -1;
	left = 0;
	right = 0;
}

Row::Row(const Row & r){
	color = -1;
	left = r.getleft();
	right = r.getright();
}

Row::Row(int l, int r) {
	color = -1;
	left = l;
	right = r;
}

int Row::getleft() const {
	return left;
}

int Row::getright() const {
	return right;
}

void Row::setleft(int c) {
	left = c;
}

void Row::setright(int c) {
	right = c;
}

Row Row::flip() {
	int temp = left;
	left = right;
	right = temp;
	return Row(left,right);
}

bool Row::same() {
	if (left == right) {
		color = left;
		return true;
	}
	return false;
}

void Row::check_color()
{
	
	switch (this->left) {
	case 1:
	 	std::cout<<"\e[48;5;208m"<<1<<"\e[0m";//orange
	 break;
	case 2: 
		std::cout<<"\e[48;5;112m"<<2<<"\e[0m";//green
	break;
	case 3: 
		std::cout<<"\e[48;5;15m"<<3<<"\e[0m";//white
	break;
	case 4: 
		std::cout<<"\e[48;5;39m"<<4<<"\e[0m";//blue
	break;
	case 5: 
		std::cout<<"\e[48;5;196m"<<5<<"\e[0m";//red
	break;
	case 6:
		std::cout<<"\e[48;5;226m"<<6<<"\e[0m";//yellow
	break;
	default: cerr << "num2char error"; exit(2);
	}
	std::cout<< "   ";
	switch (this->right) {
	case 1:
	 	std::cout<<"\e[48;5;208m"<<1<<"\e[0m";//orange
	 break;
	case 2: 
		std::cout<<"\e[48;5;112m"<<2<<"\e[0m";//green
	break;
	case 3: 
		std::cout<<"\e[48;5;15m"<<3<<"\e[0m";//white
	break;
	case 4: 
		std::cout<<"\e[48;5;39m"<<4<<"\e[0m";//blue
	break;
	case 5: 
		std::cout<<"\e[48;5;196m"<<5<<"\e[0m";//red
	break;
	case 6:
		std::cout<<"\e[48;5;226m"<<6<<"\e[0m";//yellow
	break;
	default: cerr << "num2char error"; exit(2);
	}
	
}