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

			string name;
			nutrients_injection nutrients_injection_type;
			scifir::volume max_water_volume;
			scifir::volume max_nutrients_volume;
			scifir::volume max_blood_volume;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATOR_HPP_INCLUDED