#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATION_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATION_HPP_INCLUDED

#include <chrono>
#include <string>

#include "scifir/units.hpp"

using namespace std;

namespace life_incubator
{
	class incubation
	{
		public:
			enum status { PENDING, INCUBATING, FINISHED };

			incubation();
			explicit incubation(const string& new_name,const string& new_species,const string& new_dna_filepath,const string& new_user,const scifir::scalar_unit& new_total_time,const chrono::system_clock::time_point& new_start_time,const string& new_incubator,const scifir::scalar_unit& new_nutrients_flow,const scifir::scalar_unit& new_incubation_temperature,status new_incubation_status);

			string get_status_text() const;

			string name;
			string species;
			string dna_filepath;
			string user;
			scifir::scalar_unit total_time;
			chrono::system_clock::time_point start_time;
			string incubator;
			scifir::scalar_unit nutrients_flow;
			scifir::scalar_unit incubation_temperature;
			status incubation_status;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_DATA_INCUBATION_HPP_INCLUDED