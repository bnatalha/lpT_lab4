#ifndef MYSTOI_H
#define MYSTOI_H

#include "header.h"

/**
* @brief   Função myStoi
* @detail  Similar a std::stoi encontrada na libraria de C, converte
* 		   's' interpretando seu conteudo como um número inteiro, retornando um valor int.
		   (std::stoi não estava sendo reconhecide por algum motivo(será que é por causa do -pedantic?))
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