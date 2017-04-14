/**
* @file		mystoi.h
* @brief	Onde fica as funções mystoi e myTo_String
* @author 	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 		http://www.cplusplus.com/
*/

#ifndef MYSTOI_H
#define MYSTOI_H

#include "header.h"

/**
* @brief   Função myStoi
* @detail  Similar a std::stoi encontrada na libraria de C, converte
* 		   's' interpretando seu conteudo como um número inteiro, retornando um valor int.
		   (std::stoi não estava sendo reconhecide por algum motivo)
* @param &s referência a string s.
*/
template <typename T>
T myStoi (string &s)
{
	stringstream flux(s);	/**< Constroi a streamstring flux com a string 's'; */
	T x;	/**< Variavel que vai receber o conteudo de 'flux'; */

	flux >> x;	// Extraindo conteudo do buffer

	return x;
}
//por alguma razão não compilava std::stoi

/**
* @brief   Função myTo_String
* @detail  Similar a std::to_string encontrada na libraria de C, converte
* 		   'x' retornando seu conteudo em forma de string.
*		   (std::to_sting não estava sendo reconhecide por algum motivo)
* @param &x referência a variável do tipo T.
*/
template <typename T>
string myTo_String (T &x)
{
	stringstream flux;	/**< Constroi a streamstring flux com a string 's'; */
	string s;	/**< Variavel que vai receber o conteudo de 'flux'; */

	flux << x;	// Armazena conteudo do buffer

	flux >> s;	// Extrai conteudo do buffer

	return s;
}


#endif