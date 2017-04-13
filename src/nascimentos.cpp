/**
 * @file	nascimentos.cpp
 * @brief	Onde fica a função main.
 * @author  Natália Azevedo de Brito (https://github.com/bnatalha)
 * @since	10/04/2017
 * @date	--/04/2017
 * @sa 		http://www.cplusplus.com/
 */

#include "stats.h"
#include "calc.h"
#include "yearstats.h"

/**
* @brief  Função main
* @detail Recebe argumentos via linha de comando, --
* @param  estado 	ponteiro para um vetor de Stats
* @param  argc 		quantidade de argumentos passados via linha de comando
* @param  argv		ponteiro para array de chars contendo os argumentos passados via linha de comando
*/
int main(int argc, char const *argv[])
{

	Stats *rn = NULL;
	int rn_cities_t = 0;
	string cidade;

	// Alocar o array de Stats
	allocStats(&rn, rn_cities_t, argv[1] );

	// Preencher o array de Stats
	fillStats(rn, rn_cities_t, argv[1] );

	// Alocar o array de YearStats
	YearStats *myYearsStats = new YearStats[21];

	// Preencher o array de YearStats
	for (int i = 0; i < 21; ++i)
	{
		myYearsStats[i].ano = i+1994;
		myYearsStats[i].total_n = sum_states( rn, rn_cities_t, i );
		myYearsStats[i].media_n = 
			static_cast<double>( myYearsStats[i].total_n ) / rn_cities_t;
		myYearsStats[i].desvp_n = desvp_states( rn, rn_cities_t, i, myYearsStats[i].media_n );
		myYearsStats[i].maior_n = year_peaks( rn, rn_cities_t, i, Maior);
		myYearsStats[i].menor_n = year_peaks( rn, rn_cities_t, i, Menor);
	}
/*
	// Imprimi valores das estatiscas dos anos no terminal
	cout << "Ano  |     total|     media|     desvp|     maior|     menor|" << endl;
	for (int i = 0; i < 21; ++i)
	{
		printYearStats(myYearsStats[i]);
		cout << endl;
	}
*/
	saveYearStats(myYearsStats, "data/estatisticas.csv");
	cout << "... Arquivo estatisticas.csv gerado em 'data/'" << endl;

	saveYearStats(myYearsStats, "data/totais.dat");
	cout << "... Arquivo totais.dat gerado em 'data/'" << endl << endl;

	cout << "Municipio com maior taxa de queda 2013-2014: ";		
	double menor = growth_rate( rn, rn_cities_t, 2013, 2014, Menor, cidade);
	cout << cidade << " (" << std::setprecision(4) << menor << "%)" << endl;

	cout << "Municipio com maior taxa de crescimento 2013-2014: ";		
	double maior = growth_rate( rn, rn_cities_t, 2013, 2014, Maior, cidade);
	cout << cidade << " (+" << std::setprecision(4) << maior << "%)" << endl;

	// Deleta arrays alocados dinâmicamente
	delete[] myYearsStats;
	delete[] rn;

	cout << "Encerrando programa..." << endl;
	return 0;
}