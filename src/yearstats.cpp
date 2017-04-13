#include "yearstats.h"

// Ano | total_n | media_n | desvp_n | maior_n | menor_n
void printYearStats( const YearStats &ano )
{
	int am = cout.width() ;

	cout << ano.ano << " |";
	
	cout.width(10); 
	cout << ano.total_n;
	cout.width(1);
	cout << "|";

	cout.width(10); 
	cout << ano.media_n;
	cout.width(1);
	cout << "|";

	cout.width(10); 
	cout << ano.desvp_n;
	cout.width(1);
	cout << "|";

	cout.width(10); 
	cout << ano.maior_n;
	cout.width(1);
	cout << "|";

	cout.width(10); 
	cout << ano.menor_n;
	cout.width(1);
	cout << "|";

	cout.width(am);
}