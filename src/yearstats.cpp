#include "yearstats.h"

void saveYearStats(
	const YearStats *my_statistcs, 
	const char *filename)
{
	bool is_dat;				/**< Flag que siz se arquivo é '.dat' */
	string format(filename);    /**< string para armazenar conteudo de 'filename' e fazr comparações usando biblioteca <string> */

	// Se for arquivo no formato '.dat', 'is_dat' recebe valor 'true'.
	if (format.compare( format.size()-4,4,".dat" ) == 0 ) is_dat = true;

	// Se for arquivo no formato '.csv', 'is_dat' recebe valor 'false'.
	else if(format.compare( format.size()-4,4,".csv" ) == 0 ) is_dat = false;
	else
	{
		cerr << "Formato de arquivo de saída inválido. Válidos: " << endl
			<< ".dat" << endl
			<< ".csv" << endl;
		exit(1);
	}

	std::ofstream outData(filename); /**< Stream de saída para 'filename' */

	// Verifica se 'outData' abriu corretamente
	if(outData.is_open())
	{
		for (int i = 0; i < 21; ++i)
		{
			if(is_dat)
			{
				// Salvando no formato necessários para arquivos .dat
				outData << my_statistcs[i].ano << " " << my_statistcs[i].total_n << endl;
			}
			else
			{
				// Salvando no formato necessários para arquivos .csv
				outData << my_statistcs[i].ano << ";"
					//<< my_statistcs[i].total_n << ";"
					<< my_statistcs[i].media_n << ";"
					<< my_statistcs[i].desvp_n << ";"
					<< my_statistcs[i].maior_n << ";"
					<< my_statistcs[i].menor_n << endl;
			}
		}

		// Fecha stream.
		outData.close();
		
	}
	else
	{
		cerr << "Erro ao tentar inicializar stream de saída para arquivo no formato '.dat'." << endl;
		exit(1);
	}
}


// ano | total_n | media_n | desvp_n | maior_n | menor_n
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