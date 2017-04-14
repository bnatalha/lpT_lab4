/**
* @file 	GrowRateStats.h
* @brief	Onde fica a struct GrowRate e suas funções.
* @author	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 	http://www.cplusplus.com/
*/

#ifndef GROWRATE_H
#define GROWRATE_H

#include "header.h"
#include "stats.h"


/**
* @struct  GrowRate GrowRateStats.h
* @brief   Tipo de estrutura que agrega dados de taxa de crescimento de um município no RN
*/
struct GrowRate {
	string codigo;	/**< Código do município */
	string nome;	/**< Nome do município */
	double taxa[20];	/**< Taxas de crescimento entre 1995 e 2014 */
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