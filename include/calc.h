/**
* @file	calc.h
* @brief	Onde fica a enum operations_t e funções que calculam dados para Stats
* @author  Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date	13/04/2017
* @sa 		http://www.cplusplus.com/
*/

#ifndef CALC_H
#define CALC_H

#include "header.h"
#include "comparator.h"
#include "stats.h"
#include "yearstats.h"

/**
* @enum 	operations_t calc.h
* @brief	Menor é '-1' e Maior é '1'. Usada junto ao myCompare.
*/
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