/**
 * @file	stats.cpp
 * @brief	Implemetações das funções que utilizam a estrutura stats.
 * @author  Natália Azevedo de Brito (https://github.com/bnatalha)
 * @since	10/04/2017
 * @date	--/04/2017
 * @sa 		http://www.cplusplus.com/reference/string/stoi/
 */

#include "stats.h"

/**
* @brief  Função allocStats
* @detail Aloca o vetor 'estado'
* @param estado ponteiro para um vetor de Stats
* @param qtd_muni referência para onde vai ser armazenado o tamanho do vetor
* @param source ponteiro para um vetor de char com o nome do arquivo a ser lido
*/
void allocStats(Stats **estado, int &qtd_muni, char const *source )
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
		qtd_muni = new_line_char-2;

		// Aloca no heap o vetor de Stats como o tamanho calculado.
		*estado = new Stats[qtd_muni];

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
* @brief  Função fillStats
* @detail Preenche o vetor 'estado' com as informações lidas no arquivo .dat
* @param  estado 	ponteiro para um vetor de Stats
* @param  qtd_muni  referência para o tamanho do vetor
* @param  source 	ponteiro para um vetor de char com o nome do arquivo a ser lido
* @sa http://stackoverflow.com/questions/27093288/c-stringstream-error-handling
*/
void fillStats(Stats *estado, int &qtd_muni, char const *source )
{
	std::ifstream inData;	/**< Stream de entrada */
	string fromData;		/**< string "dummy" pra armazenar as linhas lidas do arquivo */

	// Abre a ifstream 'inData' com o arquivo especificado em 'source'.
	inData.open(source);
	
	// Preenche os campos do vetor estado adequadamente se a stream foi aberta com sucesso.
	if(inData.is_open()) {
		
		// "Descarta" a primeira linha.
		getline( inData, fromData );
		

		for ( int i = 0; i < qtd_muni; i++ ) {	// dá 2º linha até a penultima.
			
			//inData.ignore('"');

			// Armazena codigo da cidade
			inData.ignore(1);
			getline(inData, fromData, ' ');
			estado[i].codigo = fromData;
			
			//inData.ignore(1, '"');
			// Armazena nome da cidade
			getline(inData, fromData, '\"');
			estado[i].nome = fromData;

			//inData.ignore(';');
			// Armazena nascimentos da cidade
			inData.ignore(1);
			for (int j = 0; j < 21; ++j){
				getline(inData, fromData, ';');
				estado[i].nascimentos[j] = myStoi(fromData);
			}

//T			// Armazena total de nascimentos no perido 
			getline(inData, fromData);
			estado[i].total = myStoi(fromData);
		}

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
* @brief  Função printStats
* @detail Imprime o vetor de Stats 'municipio'
* @param  municipio vetor de Stats passado por referencia
*/
void printStats( Stats const &municipio )
{
	// Imprime código e nome de municípios.
	cout << "-" << municipio.codigo << "- " << municipio.nome << endl;
	
	// Imprime anos e respectivos nascimentos.
	for (int ano = 1994; ano <= 2014; ++ano) {
		cout << "(" << ano << ": " << municipio.nascimentos[ano-1994] << ")" << " ";
	}

//T	// Imprime total de nascimentos.
	cout << endl <<"TOTAL: " << municipio.total;
}