#ifndef CALC_H
#define CALC_H

#include "header.h"
#include "comparator.h"
#include "stats.h"
#include "yearstats.h"

enum operations_t {
	Menor = -1,
	Maior =  1
};

int year_peaks( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos, 
	const operations_t  &param );

int sum_states( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos );

double desvp_states( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos, 
	const double &media_states );

double growth_rate( 
	const Stats *vStats, 
	const int &vSize, 
	const int &begin_year,
	const int &end_year,
	const operations_t &param,
	string &municipio );


#endif