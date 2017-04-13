#ifndef GROWRATE_H
#define GROWRATE_H

#include "header.h"
#include "stats.h"

struct GrowRate {
	string codigo;
	string nome;
	double taxa[20];
};

void allocStruct( 
	GrowRate **myGrowthRates, 
	int &size, 
	const char *source );

void readTarget( 
	GrowRate *myGrowthRates, 
	int &size, 
	const char *source );

void calcRate( 
	GrowRate *myGrowthRates, 
	const int &size, 
	const Stats *estado, 
	const int &qtd_muni );

void saveExtra( 
	const GrowRate *myGrowthRates,
	const int &size, 
	const char *filename );


#endif