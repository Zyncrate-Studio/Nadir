#include "../include/globals.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>

// filtering and ranking logic 


/*function filters using hardconstraints 
and paases to a vector(selected materials)*/



std::vector<Material>Filtered_Materials; 

void Filter(std::vector<Material>&allMaterials){
	for (const auto &material:allMaterials)
	{
		bool passes=true;
		std::map<std::string,std::variant<double,std::string>>Material_Properties_Lookup={
			{"density",allMaterials.mech.density},
			{"modulus",allMaterials.mech.modulus},
			{"tensile-strenght",allMaterials.mech.tensilestrength},
			{"hardness",allMaterials.mech.hardness},
			{"poisson-ratio",allMaterials.mech.p_ratio},
			{"dielectric-constant",allMaterials.elec.d_constant},
			{"resistivity",allMaterials.elec.resistivity},
			{"thermal-conductivity",allMaterials.therm.conductivity},
			{"melting-point",allMaterials.therm.meltingpoint},
			{"thermal-expansion",allMaterials.therm.expansion},
			{"heat-capacity",allMaterials.therm.heatcapacity},
			{"corrosion-resistance",allMaterials.chem.corrosion_resistance},
			{"minimum-ph",allMaterials.chem.ph_min},
			{"maximum-ph",allMaterials.chem.ph_max},
			{"refractive-index",allMaterials.optics.refractive_index},
			{"transparency",allMaterials.optics.transparency}
		};

		for (const auto &constraint:Hard_Constraints){
			auto it=Material_Properties_Lookup.find(constraint.property_name);
			if(it!=Material_Properties_Lookup.end()){
				auto Mat_val=it->second;
				auto Con_val=constraint.value;

				bool Conditionmet=false;
				if(symbol=="<") Conditionmet=Mat_val<Con_val;
				else if(symbol==">") Conditionmet=Mat_val>Con_val;
				else if (symbol==">=") Conditionmet=Mat_val>=Con_val;
				else if(symbol=="<=")Conditionmet=Mat_val<=Con_val;
				else if(symbol=="==")Conditionmet=Mat_val==Con_val;
				if (!Conditionmet){
					passes=false;
					break;
				}
			}
		}
		if(passes)Filtered_Materials.push_back(material);

	}
	
}