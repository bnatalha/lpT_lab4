/**
* @file 	GrowRateStats.cpp
* @brief	Onde fica a implementações das funções que utilizam a struct GrowRate.
* @author	Natália Azevedo de Brito (https://github.com/bnatalha)
* @since	10/04/2017
* @date		13/04/2017
* @sa 	http://www.cplusplus.com/
*/

#include "GrowRateStats.h"

/**
* @brief	Função allocStruct
* @details	Conta a quantidade de códigos do arquivo 'alvos.dat' e aloca o vetor myGrowthRates
* 			de acordo com a contagem.
* @param myGrowthRates	Ponteiro para um array de GrowRate
* @param size	Referência para uma variavel onde o tamanho de GrowRate vai ser armazenado
* @param source	Array de char com o nome do caminho para o arquivo .dat de onde será obtido os dados
*/
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
		// Conta a quantidade de '\n'
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


/**
* @brief	Função readTarget
* @details	Armazena os códigos do arquivo 'alvos.dat' no vetor myGrowthRates
* @param myGrowthRates	Array de GrowRate
* @param size	Referência para uma variavel com o tamanho de GrowRate
* @param source	Array de char com o nome do caminho para o arquivo .dat de onde será obtido os dados
*/
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

/**
* @brief	Função calcRate
* @details	Calcula as taxas de crescimento dos municípios entre 1995 - 2014 e armazena em myGrowthRates,
*			além de armazenar o nome dos respectivos municipios ( tudo co código destes )
* @param myGrowthRates	Ponteiro para um array de GrowRate
* @param size	Referência para uma variavel onde o tamanho de myGrowthRates vai ser armazenado
* @param estado	Array de Stats com os dados dos municípios
* @param qtd_muni	Referência para o tamanho de 'estado'
*/
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
				}
			}
		}		
	}
}


/**
* @brief	Função saveExtra
* @details	Gera o arquivo 'extra.dat' onde é armazenado os dados de myGrowthRates ao longo da execução
*			desta função
* @param myGrowthRates	Ponteiro para um array de GrowRate
* @param size	Referência para uma variavel onde o tamanho de myGrowthRates vai ser armazenado
* @param filename Array de char com o nome do caminho para o arquivo .dat a ser gerado
*/
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
			// Cria stringstream com nome da cidade
			std::stringstream NoSpace(myGrowthRates[i].nome);

			// Tira espaço para usar um nome inteiro de label no gnuplot
			string a;
			while(getline(NoSpace, a, ' ') ){
				outData << a;
			}

			// Separando os nomes das cidades
			outData << " ";
		}

		// Fim da primeira linha
		outData << endl;

		// Taxas que seram usadas pelo gnuplot
		for (int i = 0; i < 20; ++i)
		{
			// Ano analisado na linha
			outData << i+1995 << " ";

			for (int j = 0; j < size; ++j)
			{
				// Armazena dados referente a um ano de todas as cidades em uma linha 
				outData << myGrowthRates[j].taxa[i] << " ";
			}

			// Fim da linha
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