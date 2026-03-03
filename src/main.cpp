#include <iostream>
#include <iomanip>
#include <string> // pretty printing
#include "../include/globals.h"

void loadDataFromDB();
void Categorize();
std::string symbol; // for <= or >= in passing values



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
