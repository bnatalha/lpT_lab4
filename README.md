##Laboratório 4
# Natália Azevedo de Brito

Compilando:
	certifique-se de que existe a pasta bin/ no mesmo diretorio onde o Makefil se encontra.
	$ make

Gerando Documentação:
	se encontra em docs/
	$ make doc




Executando:
	$ bin/nascimentos data/Nascimentos_RN.csv

gnuplot EXTRA:
	 na pasta data/:
	$ gnuplot -e "filename='extra.dat'" extra.gnuplot

todos arquivos gerados .dat e .csv, alem dos gráficos e scripts do gnuplot em data/.


-não imprime caracteres exclusivos do teclado pt-br
-não sei se os dados das plotagens da tarefa extra estão corretos..