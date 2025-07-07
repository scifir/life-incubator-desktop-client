#include "./incubator.hpp"

using namespace std;

namespace life_incubator
{
	incubator::incubator() : name(),incubator_status(),nutrients_injection_type(),max_water_volume(),max_nutrients_volume(),max_blood_volume(),number_incubations()
	{}

	incubator::incubator(const string& new_name,incubator::status new_incubator_status,incubator::nutrients_injection new_nutrients_injection_type,const scifir::scalar_unit& new_max_water_volume,const scifir::scalar_unit& new_max_nutrients_volume,const scifir::scalar_unit& new_max_blood_volume,int new_number_incubations) : name(new_name),incubator_status(new_incubator_status),nutrients_injection_type(new_nutrients_injection_type),max_water_volume(new_max_water_volume),max_nutrients_volume(new_max_nutrients_volume),max_blood_volume(new_max_blood_volume),number_incubations(new_number_incubations)
	{}

	string incubator::get_status_text() const
	{
		if (incubator_status == incubator::AVAILABLE)
		{
			return "Available";
		}
		else if (incubator_status == incubator::INCUBATING)
		{
			return "Incubating";
		}
		else if (incubator_status == incubator::INCUBATION_FINISHED)
		{
			return "Incubation finished";
		}
		else
		{
			return "Powered off";
		}
	}
}