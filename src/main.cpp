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

	const auto&m = allMaterials[0];
	std::cout<<"Testing Entry #1:"<<std::endl;
	std::cout<<"Name: "<<m.name<<std::endl;
	std::cout<<"Family: "<<m.family<<std::endl;
	std::cout<<"Density: "<<m.mech.density<<"kg/m3"<<std::endl;
	std::cout<<"modulus: "<<m.mech.modulus<<std::endl;
	std::cout<<"T_strenght: "<<m.mech.tensileStrength<<std::endl;
	std::cout<<"hardness: "<<m.mech.hardness<<std::endl;
	std::cout<<"p_ratio: "<<m.mech.p_ratio<<std::endl;
	std::cout<<"Dielectric Constant: "<<m.elec.d_constant<<std::endl;
	std::cout<<"Resistivity: "<<m.elec.resistivity<<std::endl;
	std::cout<<"Corrosion Resistance: "<<m.chem.corrosion_resistance<<std::endl;
	std::cout<<"pH Min: "<<m.chem.ph_min<<std::endl;
	std::cout<<"pH Max: "<<m.chem.ph_max<<std::endl;
	std::cout<<"refractive Index: "<<m.optics.refractive_index<<std::endl;
	std::cout<<"transparency: "<<m.optics.transparency<<std::endl;
	std::cout<<"T_conductivity: "<<m.therm.conductivity<<std::endl;
	std::cout<<"T_melting point: "<<m.therm.meltingpoint<<std::endl;
	std::cout<<"T_expansion: "<<m.therm.expansion<<std::endl;
	std::cout<<"T_heat capacity: "<<m.therm.heatcapacity<<std::endl;

	Categorize();

	return 0;
}
