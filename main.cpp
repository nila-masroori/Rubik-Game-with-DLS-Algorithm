#include <cstdlib>
#include <iostream>
#include<vector>
#include <iostream>
#include "Cube2.h"
#include"string.h"
#include"math.h"
#include<array>

bool dls(Cube c,int limit);//my second approach for solving with dls method
Cube depth_limited_search(Cube c,int limit,int main_limit,std::vector<Cube> stack);//better algorthim for solving with dls method (using stacks:LIFO)
Cube  depth_limited_search_increment(Cube c, int max_depth);//IDS


int main()
{
	//hint
	std::cout<<std::endl;
	std::cout<<"Enter the cubies of each side seperated by SPACE! and press enter after each surface:"<<std::endl<<std::endl;;
	Cube cube{} , cube_solved{};
	int arr[4];//for getting the cubies of each surface
	
	for (size_t i = 1; i <7 ; i++)
	{
		std::cout<<"Surface "<<i<<": ";
		for (size_t j = 0; j < 4; j++)
		{
			std::cin>>arr[j];
		}
		cube.set(i,arr[0],arr[1],arr[2],arr[3]);
	}
	std::cout<<"Thank you!"<<std::endl;
	std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
	std::cout<<"this is your cube!"<<std::endl;
	cube.show();
	std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
	std::vector<Cube> stack;//creating the stack for the depth_limited_search func
	stack.push_back(cube);//pushing the main cube to the stack
	std::cout<<"Now wait for the answer :)"<<std::endl;
	cube_solved=depth_limited_search_increment(cube,10);
	std::cout<<"Rubik with numbers:"<<std::endl;
	cube_solved.show();
	std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
	std::cout<<"Rubik with chars representing the colors:"<<std::endl;
	cube_solved.displayCube();
	std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
	cube_solved.show_colored();
	std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
	 
	 

	
}

Cube depth_limited_search(Cube c,int limit,int main_limit,std::vector<Cube> stack)
{
	
	std::vector<std::string> step;
	
	int iter{0};
	Cube parent{},empty{};
	size_t size{0};
	int cnt{};
	int node_num{};
	while (!stack.empty())//if the stack is not empty
	{
		//getiing the last element of the stack
		size=stack.size();
		parent=stack[size-1];
		Cube last{};
		if(parent.isSolved())
		{ 
			std::cout<<"here is the answer:"<<std::endl<<std::endl;
			std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
			std::cout<<"number of expanded nodes are:"<<node_num<<std::endl;
			std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
			for (size_t i = step.size()-parent.depth; i <step.size() ; i++)
			{
				std::cout<<step[i]<<std::endl;
				std::cout<<step[i+1]<<std::endl;
			}
			std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
			return parent;
			
			
		}
			stack.pop_back();//after checking 
			if(step.size()!=0)
			{
				step.pop_back();
				step.pop_back();
			}
			
			if(iter<limit)
			{
				Cube child{};
				//pushing from the right side
				for (size_t j = 1; j < 7; j++)
				{
					child=parent.Rotate(j,"cw");
					child.depth=parent.depth+1;
					stack.push_back(child);
					step.push_back(to_string(j));// for saving the path 
					step.push_back(",clockwise");
					child=parent.Rotate(j,"ccw");
					child.depth=parent.depth+1;
					stack.push_back(child);
					step.push_back(to_string(j));
					step.push_back(",counter_clockwise");
					node_num=node_num+2;// each time 2 nodes are expanded in this loop (each iteration)
				}
				
					iter++;
					
			}
			
			else 
			{
				
				for (size_t i = 0; i <11 ; i++)
				{
				
					size=stack.size();
					last=stack[size-1];
					if(last.isSolved())
					{
						std::cout<<"here is the answer!:"<<std::endl<<std::endl;
						std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
						std::cout<<"number of expanded nodes are:"<<node_num<<std::endl;
						std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
					for (size_t i = step.size()-last.depth; i <step.size() ; i++)
					{
						std::cout<<step[i]<<std::endl;
						std::cout<<step[i+1]<<std::endl;
					}
					std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
						return last;
						
						
					}
					stack.pop_back();
					step.pop_back();
					step.pop_back();
					
				}
				size=stack.size();
				parent=stack[size-1];
				
				cnt=main_limit-parent.depth;
				
				return depth_limited_search(parent,cnt,main_limit,stack);//kinda recursive!
				
				
			}
	}
	return empty;
}
	
	bool dls(Cube c,int limit)
	{
		Cube child{};
		if(c.isSolved())
		{
			std::cout<<"the answer is:"<<std::endl;
			c.displayCube();
			return true;
		}
		if(limit<0)
		{
			return false;
		}

		for (size_t i = 1; i < 13; i++)
		{
			if(i<6)
				child=c.Rotate(i,"cw");
			else if(i>6)
				child=c.Rotate(i-6,"ccw");
			
			if(dls(child,limit-1))
				return true;		
			
		}
		return false;
	}

Cube  depth_limited_search_increment(Cube c, int max_depth)
{
	std::vector<Cube> stack;//creating the stack for the depth_limited_search func
	stack.push_back(c);//pushing the main cube to the stack
	Cube new_cube{} , empty{};
	for (int i = 1; i < max_depth; i++)
	{
		
		new_cube=depth_limited_search(c,i,i,stack);//creating the answer with each depth
		//checking each answer for getting to the right answer
		if(new_cube.isSolved())
		{
			std::cout<<"the suitable limit: "<<i<<std::endl;
			return new_cube;
		}
	}
	std::cout<<"no answer was found with the given limit!!!"<<std::endl;
	return empty;
}























