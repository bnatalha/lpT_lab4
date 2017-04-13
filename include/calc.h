#ifndef CALC_H
#define CALC_H

#include "header.h"
#include "comparator.h"
#include "stats.h"

enum operations_t {
	Menor = -1,
	Soma  =  0,
	Maior =  1,
	DesvP =  2,
	Media =  3
};

int year_peaks( 
	const Stats 		*vStats, 
	const int   		&vSize, 
	const int   		&year_pos, 
	const operations_t  &param );

int sum_states( 
	const Stats *vStats, 
	const int   &vSize, 
	const int   &year_pos );

double desvp_states( 
	const Stats 	*vStats, 
	const int 		&vSize, 
	const int 		&year_pos, 
	const double	&media_states );


#endif