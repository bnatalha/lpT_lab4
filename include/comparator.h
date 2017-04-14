/**
* @file		comparator.h
* @brief	Onde fica a função template myCompare
* @author 	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 		http://www.cplusplus.com/
*/

#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "header.h"

/**
* @brief	Função myCompare
* @details	Compara os valores passados como argumento, retornado qual o maior deles
*			com o valor '1' para se for 'a', '-1' se for 'b' e '0' se forem iguais.
* @param a 	Referência para uma variavel do tipo T
* @param b 	Referência para uma variavel do tipo T
*/
template <typename T>
int myCompare( const T &a, const T &b)
{
	if( a > b ) return 1;
	if( a < b ) return -1;
	return 0;
}

#endif