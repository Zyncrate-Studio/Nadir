#include "../include/globals.h"
#include <vector>
#include <iostream>
#include <string>

// filtering and ranking logic 
/*
here we seperate the materials by family to enable some logic for decision making
e.g when strenght is part of the hard constraints then metal family is included etc. */

/*splitting the various materials by category*/

std::vector<Material>Metals;
std::vector<Material>Ceramic;
std::vector<Material>Polymer;
std::vector<Material>Composite;
std::vector<Material>Semiconductor;
std::vector<Material>Natural;

void Categorize(){

	for(const auto& material:allMaterials){
		if (material.family=="Metal") Metals.push_back(material);
		else if(material.family=="Ceramic") Ceramic.push_back(material);
		else if(material.family=="Polymer") Polymer.push_back(material);
		else if(material.family=="Composite") Composite.push_back(material);
		else if(material.family=="Semiconductor") Semiconductor.push_back(material);
		else if(material.family=="Natural") Natural.push_back(material);
	}
}

/*function that works with the category to carry out the selection process
*/