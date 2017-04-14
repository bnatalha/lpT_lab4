/**
* @file		yearstats.h
* @brief	Onde fica a struct YearStats e suas funções.
* @author 	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 		http://www.cplusplus.com/
*/

#ifndef YEARSTATS_H
#define YEARSTATS_H

#include "header.h"

/**
* @struct  YearStats yearstats.h
* @brief   Tipo de estrutura que agrega dados de nascimento de um ano no RN
* @details Os dados cobrem estatisticas dos anos como média de nascimentos,
* 		   maior numero de nascimentos em um municipio, etc.
*/
struct YearStats {
	int ano;	/**< Ano ( em [1994, 2014] ) */
	int total_n;	/**< Total de nascimentos no ano */
	double media_n;	/**< Média de nascimentos no ano*/
	double desvp_n;	/**< Desvio padrão de nascimentos no ano */
	int maior_n;	/**< Maior numero de nascimentos em um municipio no ano */
	int menor_n;	/**< Menor numero de nascimentos em um municipio no ano */
};

void printYearStats( 
	const YearStats &ano );

void saveYearStats(
	const YearStats *my_statistcs, 
	const char *filename);

#endif