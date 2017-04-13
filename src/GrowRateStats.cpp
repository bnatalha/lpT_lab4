#include "GrowRateStats.h"

// versao template colocando alloc de tudo aqui.
void allocStruct( 
	GrowRate **myGrowthRates, 
	int &size, 
	const char *source )
{
	std::ifstream inData;	/**< Stream de entrada */
	int new_line_char = 0;	/**< Quantidade de '\n' encontrados no arquivo */
	string fromData;		/**< string "dummy" pra armazenar as linhas lidas do arquivo */

	// Abre a ifstream 'inData' com o arquivo especificado em 'source'.
	inData.open(source);

	// Conta quantos '\n' existem no arquivo se a stream foi aberta com sucesso.
	if(inData.is_open())
	{
		for ( ; getline (inData, fromData ); ++new_line_char);

		// Atribuindo tamanho do vetor.
		size = new_line_char;

		// Aloca no heap o vetor de 'GrowRate' como o tamanho calculado.
		*myGrowthRates = new GrowRate[size];

		// Fecha a stream.
		inData.close();		
	}

	// Exceção caso aconteça um erro na leitura do arquivo.
	else
	{
		cerr << "'" << source << "' não encontrado." << endl;
		exit(1);
	}
}

void readTarget( 
	GrowRate *myGrowthRates, 
	int &size, 
	const char *source )
{
	std::ifstream inData;	/**< Stream de entrada */
	string fromData;		/**< string "dummy" pra armazenar as linhas lidas do arquivo */

	// Abre a ifstream 'inData' com o arquivo especificado em 'source'.
	inData.open(source);

	// Conta quantos '\n' existem no arquivo se a stream foi aberta com sucesso.
	if(inData.is_open())
	{
		// Atribui codigos a myGrow
		for (int i = 0;  i < size; i++)
			getline (inData, myGrowthRates[i].codigo );

		// Fecha a stream.
		inData.close();		
	}

	// Exceção caso aconteça um erro na leitura do arquivo.
	else
	{
		cerr << "'" << source << "' não encontrado." << endl;
		exit(1);
	}
}


void calcRate( 
	GrowRate *myGrowthRates, 
	const int &size, 
	const Stats *estado, 
	const int &qtd_muni )
{

	for ( int i = 0; i < qtd_muni; i++ )	// De municipio a municipio em 'estado'
	{	
		for ( int j = 0; j < size; ++j )	// De alvo a alvo em 'myGrowthRates'
		{
			// Se achou um municipio como o codigo
			if( myGrowthRates[j].codigo == estado[i].codigo )
			{
				// Associa nome ao municipio em 'myGrowthRates'
				myGrowthRates[j].nome = estado[i].nome;

				for (int k = 0; k < 20; ++k)
				{
					// Calcula e atribui taxas de crescimento a 'myGrowthRates'
					myGrowthRates[j].taxa[k] = 100.00* ( 
						(static_cast<double>( estado[i].nascimentos[k+1] ) 	/
						estado[i].nascimentos[k] ) - 1 );
					
					// cout << std::setprecision(4) << myGrowthRates[j].taxa[k] << " ";
				}
			}
		}		
	}
}

void saveExtra( 
	const GrowRate *myGrowthRates,
	const int &size, 
	const char *filename )
{
	string format(filename);    /**< string para armazenar conteudo de 'filename' e fazr comparações usando biblioteca <string> */

	// Se for arquivo não for no formato '.dat', aborta execução do programa.
	if (format.compare( format.size()-4,4,".dat" ) != 0 )
	{
		cerr << "Formato de arquivo de saída inválido. Válido: " << endl
			<< ".dat" << endl;
		exit(1);
	}

	std::ofstream outData(filename); /**< Stream de saída para 'filename' */

	// Verifica se 'outData' abriu corretamente
	if(outData.is_open())
	{
		// Labels das ordenadas
		for (int i = 0; i < size; ++i)
		{
			// Salvando no formato necessários para arquivos .dat
			outData << myGrowthRates[i].nome << " ";
		}

		outData << endl;

		// pontos	
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				outData << myGrowthRates[j].taxa[i] << " ";
			}
			outData << endl;

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