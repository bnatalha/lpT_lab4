/**
 * @file	mystoi.cpp
 * @brief	--
 * @author  Natália Azevedo de Brito (https://github.com/bnatalha)
 * @since	10/04/2017
 * @date	--/04/2017
 * @sa 		http://www.cplusplus.com/reference/string/stoi/
 */
#include "mystoi.h"

/**
* @brief   Função myStoi
* @detail  Similar a std::stoi encontrada na libraria de C, converte
* 		   's' interpretando seu conteudo como um número inteiro, retornando um valor int.
		   (std::stoi não estava sendo reconhecide por algum motivo(será que é por causa do -pedantic?))
* @param &s referência a string s.
*/
int myStoi (string &s)
{
	stringstream flux(s);	/**< Constroi a streamstring flux com a string 's'; */
	int x;					/**< Variavel que vai receber o conteudo de 'flux'; */

	flux >> x;	// Extraindo conteudo do buffer

	return x;
}
//por alguma razão não compilava std::stoi