/**
 * @file	nascimentos.cpp
 * @brief	onde fica a função main.
 * @author  Natália Azevedo de Brito (https://github.com/bnatalha)
 * @since	10/04/2017
 * @date	--/04/2017
 * @sa 		http://www.cplusplus.com/
 */

#include "stats.h"
#include "calc.h"

/**
* @brief  Função main
* @detail Recebe argumentos via linha de comando, --
* @param  estado 	ponteiro para um vetor de Stats
* @param  argc 		quantidade de argumentos passados via linha de comando
* @param  argv		ponteiro para array de chars contendo os argumentos passados via linha de comando
*/
int main(int argc, char const *argv[])
{
	/*
	recebe via linha de comando .csv
	aloca coisas no vetor de stats
	--
	calcular 
	(i) o maior número de nascimentos em cada ano;
	(ii) o menor número de nascimentos em cada ano;
	(iii) a média do número de nascimentos em cada ano;
	(iv) o desvio padrão2 do número de nascimentos em cada ano, e;
	(v) o número total de nascimentos em cada ano.
	--
	saida
	statisticas.csv
	totais.dat
	histograma.gnuplot
	--
	*/

	
	Stats *rio_norte = NULL;
	int mySize = 0;

	//exceções de leitura.

	//leitura de dados
	allocStats(&rio_norte, mySize, argv[1] );
	fillStats(rio_norte, mySize, argv[1] );
/*
	int op = 1;
	int index;

	while (op == 1){
		cout << ">> Indice de 0 a" << mySize-1 << ": "; //ultimo indice
		cin >> index;
		cout << ">> ";
		printStats(rio_norte[index]);
		cout << "--" << endl;
	}
*/

	cout << "(i) O maior número de nascimentos em cada ano:" << endl;
	getBornPeaks(rio_norte,mySize,Maior);
	cout << endl;

	cout << "(ii) O menor número de nascimentos em cada ano:" << endl;
	getBornPeaks(rio_norte,mySize,Menor);
	cout << endl;

	cout << "(iii) A média do número de nascimentos em cada ano:" << endl;
	getTotal(rio_norte,mySize,Media);
	cout << endl;

	cout << "(iv) O desvio padrão2 do número de nascimentos em cada ano:" << endl;
	getTotal(rio_norte,mySize,DesvP);
	cout << endl;

	cout << "(v) O número total de nascimentos em cada ano:" << endl;
	getTotal(rio_norte,mySize,Soma);
	cout << endl;
	
	delete[] rio_norte;

	return 0;
}