#ifndef STATS_H
#define STATS_H

#include "header.h"
/**
* @struct  Stats stats.h ??
* @brief   Tipo de estrutura que agrega dados de nascimento de um município
* @details Os dados cobrem os anos 1994 a 2014
*/
struct Stats{
	string codigo;		/**< Código do município */
	string nome;		/**< Nome do município */
	int nascimentos[21]; /**< Número de nascimentos em cada ano contabilizado */
	int total;
};

//===============leitura de dados ===================
void allocState(Stats **estado, int &qtd_muni, char const *source );
void fillState(Stats *estado, int &qtd_muni, char const *source );

//===Operações com stats

void printStats( Stats const &municipio );	// Imprime o conteudo de uma Stat.

#endif