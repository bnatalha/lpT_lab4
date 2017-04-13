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
	int total;
};

//===============leitura e alocação de dados ========================

void allocStats( Stats **estado, int &qtd_muni, char const *source );
void fillStats ( Stats  *estado, int &qtd_muni, char const *source );

//===============gravação/impressão de dados =============================================

void printStats( Stats const &municipio );

//void saveStats

#endif