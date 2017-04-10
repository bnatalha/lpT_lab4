#include "stats.h"

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
	allocState(&rio_norte, mySize, argv[1] );
	fillState(rio_norte, mySize, argv[1] );

	int op = 1;
	int index;

	cout << ">> op: ";
	while (op != 0){
		cout << ">> Indice de 0 a" << mySize << ": ";
		cin >> index;
		cout << ">> [ ";
		printStats(rio_norte[index]);
		cout << " ];" << endl << ">> exit(0)? ";
		cin >> op;
	}


	delete[] rio_norte;

	return 0;
}