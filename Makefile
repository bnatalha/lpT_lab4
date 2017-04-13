##by @bnatalha

CPPFLAGS += -Wall -std=c++11 -ansi -pedantic -O0 -g
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
bin/nascimentos: bin/nascimentos.o bin/stats.o bin/calc.o bin/yearstats.o
	g++ $^ -o $@

#gerar objetos
bin/nascimentos.o: src/nascimentos.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

bin/stats.o: src/stats.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

bin/calc.o: src/calc.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

bin/yearstats.o: src/yearstats.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

#remover .o's
clean:
	$(RM) bin/*.o