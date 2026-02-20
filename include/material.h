// datastructure of materials 
#pragma once 
#include <string>
#include <vector>

struct MechanicalProps{
	double density;
	double modulus;
	double tensileStrength;
	double hardness;
	double p_ratio;//poissons_ratio
};

struct ElectricalProps{
	double d_constant;//dielectric constant
	double resistivity;
};

struct ThermalProps{
	double conductivity;
	double meltingpoint;
	double expansion;
	double heatcapacity;
};

struct ChemicalProps{
	std::string corrosion_resistance;
	double ph_min;
	double ph_max;
};

struct OpticalProps{
	double refractive_index;
	std::string transparency;
};

/*enum class Family{Metal,Ceramic,Polymer,Composite,Semiconductor,Natural};
*/
class Material{
public:
	std::string name;
	std::string family;
	MechanicalProps mech;
	ElectricalProps elec;
	ChemicalProps chem;
	ThermalProps therm;
	OpticalProps optics;

	//constructor 
	Material(std::string name, std::string family, MechanicalProps mech,ElectricalProps elec,
		ChemicalProps chem,ThermalProps therm,OpticalProps optics): name(name), family(family), mech(mech),elec(elec),chem(chem),therm(therm),optics(optics){};

	// methods 
	/*void Populate(std::string name,
	Family family,
	MechanicalProps mech,
	ElectricalProps elec,
	ChemicalProps chem,
	ThermalProps therm,
	OpticalProps optics);*/

	void retrieve(); /*to test console adjust later
						for gui maybe seperate each member*/
};

extern std::vector<Material> allMaterials;
