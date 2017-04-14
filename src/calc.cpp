/**
* @file 	calc.cpp
* @brief	Onde fica a implementações das funções que utilizam a struct Stats para calcular estatisticas.
* @author	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 	http://www.cplusplus.com/
*/

#include "calc.h"
#include "stats.h"
#include <cmath>


/**
* @brief	Função year_peaks
* @details	Calcúla o município que teve o maior/menor número de nascimentos em determinado ano
* @param vStats	Ponteiro para um array de Stats
* @param vsize	Referência para uma variavel onde o tamanho de myGrowthRates vai ser armazenado
* @param year_pos	Posição do ano numa lista de 1994-2014
* @param param	Diz se quer uma comparação que resulta o maior ou o menor valor
*/
int year_peaks( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos, 
	const operations_t &param )
{
	long int peakAmount = vStats[0].nascimentos[year_pos];

	for (int i = 0; i < vSize; ++i)
		if( myCompare( static_cast<long int>(vStats[i].nascimentos[year_pos]), peakAmount ) == param )
			peakAmount = vStats[i].nascimentos[year_pos];
	return peakAmount;
}

/**
* @brief	Função sum_states
* @details	Calcúla a soma dos nascimentos em todos municípios em determinado ano
* @param vStats	Ponteiro para um array de Stats
* @param vsize	Referência para uma variavel onde o tamanho de myGrowthRates vai ser armazenado
* @param year_pos	Posição do ano numa lista de 1994-2014
*/
int sum_states( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos )
{
	int sum = 0;

	for (int i = 0; i < vSize; ++i)
		sum += vStats[i].nascimentos[year_pos];

	return sum;
}

/**
* @brief	Função desvp_states
* @details	Calcúla desvião padrão de nascimentos em todos municípios em determinado ano
* @param vStats	Ponteiro para um array de Stats
* @param vsize	Referência para uma variavel onde o tamanho de myGrowthRates vai ser armazenado
* @param year_pos	Posição do ano numa lista de 1994-2014
* @param media_states Referência para um variavel que armazena a média de nascimentos em year_pos
*/
double desvp_states( 
	const Stats *vStats, 
	const int &vSize, 
	const int &year_pos, 
	const double &media_states )
{

	double sum = 0;

	for (int i = 0; i < vSize; ++i)
		sum += pow( vStats[i].nascimentos[year_pos] - media_states, 2);

	return sqrt( sum / vSize );
}

/**
* @brief	Função growth_rate
* @details	Calcúla a maior/menor taxa de crescimento do municipio entre determido intervalo de tempo
* @param vStats	Ponteiro para um array de Stats
* @param vsize	Referência para uma variavel onde o tamanho de myGrowthRates vai ser armazenado
* @param year_pos	Posição do ano numa lista de 1994-2014
* @param begin_year 	Posição do ano inicial numa lista de 1994-2014
* @param end_year 	Posição do ano finial numa lista de 1994-2014
* @param param	Diz se quer uma comparação que resulta o maior ou o menor valor
* @param municipio Armazena nome do municipio escolhi
*/
double growth_rate( 
	const Stats *vStats, 
	const int &vSize, 
	const int &begin_year,
	const int &end_year,
	const operations_t &param,
	string &municipio )
{
	double peakRate =
		static_cast<double>( vStats[0].nascimentos[end_year-1994] )	/
		vStats[0].nascimentos[begin_year-1994];

	double muniGrowthRate;

	string muni_name = vStats[0].nome;
	
	for (int muni = 0; muni < vSize; ++muni)
	{

		muniGrowthRate = 
			static_cast<double>( vStats[muni].nascimentos[end_year-1994] ) 	/
			vStats[muni].nascimentos[begin_year-1994];

		if( myCompare( muniGrowthRate, peakRate ) == param )
		{
			peakRate = muniGrowthRate;
			muni_name = vStats[muni].nome;
		}
	}
	
	municipio = muni_name;
	
	return (100.00 * (peakRate - 1) );
}