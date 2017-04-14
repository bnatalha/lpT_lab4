/**
* @file		stats.h
* @brief	Onde fica a struct Stats e suas funções.
* @author 	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 		http://www.cplusplus.com/
*/

#ifndef STATS_H
#define STATS_H

#include "header.h"
#include "mystoi.h"

//Stats stats.h (???)

/**
* @struct  Stats stats.h
* @brief   Tipo de estrutura que agrega dados de nascimento de um município
* @details Os dados cobrem os anos 1994 a 2014
*/
struct Stats{
	string codigo;		 /**< Código do município */
	string nome;		 /**< Nome do município */
	int nascimentos[21]; /**< Número de nascimentos em cada ano contabilizado */
};

void allocStats( 
	Stats **estado, 
	int &qtd_muni, 
	char const *source );

void fillStats ( 
	Stats *estado, 
	int &qtd_muni, 
	char const *source );

void printStats( 
	Stats const &municipio );

#endif