##by @bnatalha
# "apenas um programa executável deverá ser gerado e entregue após a conclusão das tarefas"
CPPFLAGS += -Wall -std=c++11 -ansi -pedantic -O0 -g
#CPPFLAGS += -Wall -std=c++11 -g
INC =-I include

.PHONY: all val clean

#compilar tudo
all: bin/nascimentos clean

#gerar a documentação
doc: Doxyfile
	doxygen	

#checar vazamento de memoria
val:
	valgrind --leak-check=yes bin/nascimentos data/Nascimentos_RN.csv

#
#
#gerar executaveis
bin/nascimentos: bin/nascimentos.o bin/stats.o
	g++ $^ -o $@

#gerar objetos
bin/nascimentos.o: src/nascimentos.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

bin/stats.o: src/stats.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

#remover .o's
clean:
	$(RM) bin/*.o