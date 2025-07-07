#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATOR_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATOR_HPP_INCLUDED

#include <string>

#include "scifir/units.hpp"

using namespace std;

namespace life_incubator
{
	class incubator
	{
		public:
			enum nutrients_injection { NUTRIENTS_FLOW, INDIVIDUAL_NUTRIENTS };
			enum status { AVAILABLE, INCUBATING, INCUBATION_FINISHED, POWEROFF };

			incubator();
			explicit incubator(const string& new_name,incubator::status new_incubator_status,incubator::nutrients_injection new_nutrients_injection_type,const scifir::scalar_unit& new_max_water_volume,const scifir::scalar_unit& new_max_nutrients_volume,const scifir::scalar_unit& new_max_blood_volume,int new_number_incubations);

			string get_status_text() const;

			string name;
			status incubator_status;
			nutrients_injection nutrients_injection_type;
			scifir::scalar_unit max_water_volume;
			scifir::scalar_unit max_nutrients_volume;
			scifir::scalar_unit max_blood_volume;
			int number_incubations;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATOR_HPP_INCLUDED