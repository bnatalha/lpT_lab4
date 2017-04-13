#include "calc.h"
#include "stats.h"
#include <cmath>

int year_peaks( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos, 
	const operations_t &param )
{
	long int peakAmount = vStats[0].nascimentos[year_pos];

	for (int i = 0; i < vSize; ++i)
		if( myCompare( static_cast<long int>(vStats[i].nascimentos[year_pos]), peakAmount ) == param )
			peakAmount = vStats[i].nascimentos[year_pos];
	return peakAmount;
}

int sum_states( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos )
{
	int sum = 0;

	for (int i = 0; i < vSize; ++i)
		sum += vStats[i].nascimentos[year_pos];

	return sum;
}

double desvp_states( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos, 
	const double &media_states )
{

	double sum = 0;

	for (int i = 0; i < vSize; ++i)
		sum += pow( vStats[i].nascimentos[year_pos] - media_states, 2);

	return sqrt( sum / vSize );
}


double growth_rate( 
	const Stats *vStats, 
	const int &vSize, 
	const int &begin_year,
	const int &end_year,
	const operations_t &param,
	string &municipio )
{
	double peakRate =
		static_cast<double>( vStats[0].nascimentos[end_year-1994] )	/
		vStats[0].nascimentos[begin_year-1994];

	double muniGrowthRate;

	string muni_name = vStats[0].nome;
	
	for (int muni = 0; muni < vSize; ++muni)
	{

		muniGrowthRate = 
			static_cast<double>( vStats[muni].nascimentos[end_year-1994] ) 	/
			vStats[muni].nascimentos[begin_year-1994];

		if( myCompare( muniGrowthRate, peakRate ) == param )
		{
			peakRate = muniGrowthRate;
			muni_name = vStats[muni].nome;
		}
	}
	
	municipio = muni_name;
	
	return (100.00 * (peakRate - 1) );
}