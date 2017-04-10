#include "stats.h"

void allocState(Stats **estado, int &qtd_muni, char const *source )
{
	std::ifstream	inData;

	cout << source << " is source." << endl;

	inData.open(source);

	//conta linhas
	int linhas = 0;
	string wat = "";
	if(inData.is_open())
	{
		cout << "open." << endl;
		for ( ; getline (inData, wat ); ++linhas) if (linhas == 0) continue;			
	}

	qtd_muni = linhas;

	//aloca linhas
	*estado = new Stats[qtd_muni];

	inData.close();
}

// http://stackoverflow.com/questions/27093288/c-stringstream-error-handling
void fillState(Stats *estado, int &qtd_muni, char const *source )
{
	std::ifstream	inData;
	stringstream fluxo;
	string wat;

	inData.open(source);
	
	//armazena
	if(inData.is_open()) {
		for ( int i = 0; i <= qtd_muni; i++ ) {
			if (i == 0 or i == qtd_muni  ) {
				getline( inData, wat );
				wat = "";
				continue;
			}

			//inData.ignore('"');
			inData.ignore(1);
			getline(inData, wat, ' ');
			fluxo.str(wat);
			fluxo >> estado[i-1].codigo;
			wat = "";

			//inData.ignore(1, '"');
			getline(inData, wat, '\"');
			fluxo.str(wat);
			fluxo >> estado[i-1].nome;
			wat = "";

			//inData.ignore(';');
			inData.ignore(1);
			for (int j = 0; j < 21; ++j){
				getline(inData, wat, ';');
				fluxo.str(wat);
				fluxo >> estado[i-1].nascimentos[j];
				wat = "";
			}

			getline(inData, wat);
			fluxo.str(wat);
			fluxo >> estado[i-1].total;
			wat = "";
		}
	}

	cout << "whats wat: [" << wat << "]" << endl;
	inData.close();
}


void printStats( Stats const &municipio )
{
	cout << "-" << municipio.codigo << "- " << municipio.nome << endl;
	
	for (int ano = 1994; ano <= 2014; ++ano) {
		cout << ano << " " << municipio.nascimentos[ano-1994] << endl;
	}

	cout << endl;
}