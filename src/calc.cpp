#include "calc.h"
#include "stats.h"
#include <cmath>

void getBornPeaks( const Stats *vStats, const int &vSize, const operations_t &param)
{
	string thisCity;
	long int thisAmount;
	
	for (int i = 0, year = 1994; i < 21; ++i)
	{	
		thisAmount = vStats[0].nascimentos[i];
		thisCity = vStats[0].nome;

		cout << year+i << ": ";

		for (int j = 0; j < vSize; ++j)
		{
			if( myCompare( static_cast<long int>(vStats[j].nascimentos[i]), thisAmount ) == param )
			{
				thisAmount = vStats[j].nascimentos[i];
				thisCity = vStats[j].nome;
			}
		}

		cout << thisCity << ", com " << thisAmount << " nascimentos" << endl;

	}
}
// no caso te ter duas cidades com o maior/menor numero de nascimentos em um ano, 
// faria um for pra descobrir qual o maior/menor
// um for pra pegar os que tão na mesma quantidade que o igual
// e ("enfia la" se dosse uma lista por posição) imprime os iguais a media que fossem achados.

int sum_state( const Stats *vStats, const int &vSize, const int &year )
{
	//long int sum = 0;
	int sum = 0;
	//for (int i = 0; i < 21; ++i) sum += static_cast<long int>(vStats[i].nascimentos[year]);
	for (int i = 0; i < vSize; ++i) sum += vStats[i].nascimentos[year];
	return sum;
}

double desvp_states( const Stats *vStats, const int &vSize, const int &year )
{
	//long int media = sum_state( vStats, vSize, year );
	//long int sum = 0;

	double media = static_cast<double>( sum_state( vStats, vSize, year ) ) / vSize;
	double sum = 0;

	for (int i = 0; i < vSize; ++i)
	{
		//sum += pow( static_cast<long int>(vStats[i].nascimentos[year]) - media, 2);
		sum += pow( vStats[i].nascimentos[year] - media, 2);
	}

	return sqrt( sum / vSize );
}


void getTotal( const Stats *vStats, const int &vSize, const operations_t &param )
{
	for (int i = 0, year = 1994; i < 21; ++i)
	{
		cout << year+i << ": ";

		if( param == Soma )
			cout << sum_state( vStats, vSize, i )	<< endl;
		if( param == Media)
			cout << static_cast<double>( sum_state( vStats, vSize, i ) ) / vSize << endl;
		if( param == DesvP)
			cout << desvp_states( vStats, vSize, i ) << endl;
	}
}
