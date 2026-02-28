#include <iostream>
#include <iomanip> // pretty printing
#include "../include/globals.h"

void loadDataFromDB();
void Categorize();



int main()
{

	std::cout<<"-----Material Selector System -----\n"<<std::endl;
	loadDataFromDB();
	if(allMaterials.empty()){
		std::cout<<"Error: No materials loaded. Check Database"<<std::endl;
		return 1;
	}

	Categorize();

	return 0;
}
