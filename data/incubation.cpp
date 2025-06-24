#include "./incubation.hpp"

using namespace std;

namespace life_incubator
{
	incubation::incubation() : name(),species(),dna_filepath(),user(),total_time(),start_time(),incubator(),nutrients_flow(),incubation_temperature()
	{}

	incubation::incubation(const string& new_name,const string& new_species,const string& new_dna_filepath,const string& new_user,const scifir::time_duration& new_total_time,const chrono::system_clock::time_point& new_start_time,const string& new_incubator,const scifir::scalar_unit& new_nutrients_flow,const scifir::temperature& new_incubation_temperature) : name(new_name),species(new_species),dna_filepath(new_dna_filepath),user(new_user),total_time(new_total_time),start_time(),incubator(new_incubator),nutrients_flow(new_nutrients_flow),incubation_temperature(new_incubation_temperature)
	{}
}