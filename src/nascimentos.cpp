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
#include "GrowRateStats.h"

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

	// Alocar o array de Stats
	allocStats(&rn, rn_cities_t, argv[1] );

	// Preencher o array de Stats
	fillStats(rn, rn_cities_t, argv[1] );

	// Alocar o array de YearStats
	YearStats *minhas_stats_anuais = new YearStats[21];

	// Preencher o array de YearStats
	for (int i = 0; i < 21; ++i)
	{
		minhas_stats_anuais[i].ano = i+1994;
		minhas_stats_anuais[i].total_n = sum_states( rn, rn_cities_t, i );
		minhas_stats_anuais[i].media_n = 
			static_cast<double>( minhas_stats_anuais[i].total_n ) / rn_cities_t;
		minhas_stats_anuais[i].desvp_n = desvp_states( rn, rn_cities_t, i, minhas_stats_anuais[i].media_n );
		minhas_stats_anuais[i].maior_n = year_peaks( rn, rn_cities_t, i, Maior);
		minhas_stats_anuais[i].menor_n = year_peaks( rn, rn_cities_t, i, Menor);
	}
/*
	// Imprimi valores das estatiscas dos anos no terminal
	cout << "Ano  |     total|     media|     desvp|     maior|     menor|" << endl;
	for (int i = 0; i < 21; ++i)
	{
		printYearStats(minhas_stats_anuais[i]);
		cout << endl;
	}
*/
	// TAREFA 1
	saveYearStats(minhas_stats_anuais, "data/estatisticas.csv");
	cout << "... Arquivo estatisticas.csv gerado em 'data/'" << endl;

	saveYearStats(minhas_stats_anuais, "data/totais.dat");
	cout << "... Arquivo totais.dat gerado em 'data/'" << endl << endl;

	//TAREFA 2
	string cidade;

	cout << "Municipio com maior taxa de queda 2013-2014: ";		
	double menor = growth_rate( rn, rn_cities_t, 2013, 2014, Menor, cidade);
	cout << cidade << " (" << std::setprecision(4) << menor << "%)" << endl;

	cout << "Municipio com maior taxa de crescimento 2013-2014: ";		
	double maior = growth_rate( rn, rn_cities_t, 2013, 2014, Maior, cidade);
	cout << cidade << " (+" << std::setprecision(4) << maior << "%)" << endl;

	//TAREFA 3

	GrowRate *meus_alvos = NULL;
	int target_total = 0;

	allocStruct( &meus_alvos, target_total, "data/alvos.dat" );
	cout << "......[" << target_total << "] municipios definidos como alvo(s)" << endl;
	
	// Pega codigos de alvos.dat e coloca em 'meus_alvos'
	readTarget( meus_alvos, target_total, "data/alvos.dat" );
	
	// Atribui nome, calcula e atribui taxas a 'meus_alvos'
	calcRate( meus_alvos, target_total, rn, rn_cities_t );
	
	for (int i = 0; i < target_total; ++i)
	{
		cout << "......{ " << meus_alvos[i].nome << " }" << endl;
	}

	saveExtra( meus_alvos, target_total, "data/extra.dat");
	cout << "... Arquivo extra.dat gerado em 'data/'" << endl << endl;

	// Deleta arrays alocados dinâmicamente
	delete[] rn;
	delete[] minhas_stats_anuais;
	delete[] meus_alvos;

	cout << "Encerrando programa..." << endl;
	return 0;
}