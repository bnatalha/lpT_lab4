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

int sum_states( const Stats &state );
double desvp_states( const Stats *vStats, const int &vSize );

void getBornPeaks( const Stats *vStats, const int &vSize, const operations_t &param);
void getTotal( const Stats *vStats, const int &vSize, const operations_t &param );



#endif