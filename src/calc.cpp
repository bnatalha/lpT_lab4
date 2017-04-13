#include "calc.h"
#include "stats.h"
#include <cmath>

int year_peaks( 
	const Stats 		*vStats, 
	const int   		&vSize, 
	const int   		&year_pos, 
	const operations_t  &param )
{
	long int thisAmount = vStats[0].nascimentos[year_pos];

	for (int i = 0; i < vSize; ++i)
		if( myCompare( static_cast<long int>(vStats[i].nascimentos[year_pos]), thisAmount ) == param )
			thisAmount = vStats[i].nascimentos[year_pos];
	return thisAmount;
}

int sum_states( 
	const Stats *vStats, 
	const int   &vSize, 
	const int   &year_pos )
{
	int sum = 0;

	for (int i = 0; i < vSize; ++i)
		sum += vStats[i].nascimentos[year_pos];

	return sum;
}

double desvp_states( 
	const Stats 	*vStats, 
	const int 		&vSize, 
	const int 		&year_pos, 
	const double	&media_states )
{

	double sum = 0;

	for (int i = 0; i < vSize; ++i)
		sum += pow( vStats[i].nascimentos[year_pos] - media_states, 2);

	return sqrt( sum / vSize );
}