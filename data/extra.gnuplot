# by @bnatalha
# $ gnuplot -e "filename='extra.dat'" extra.gnuplot

# Inicialização
clear
reset
set key off

# Configuracoes de saida: inclui formato de exportacao, tamanho do grafico,
# fontes utilizadas e nomes do arquivo de saida
# ==========================================================================
# Exportacao para o formato .png
set terminal png size 800,600 enhanced font 'Helvetica,11'
set output 'line.png'

# Titulo do grafico
set title 'Taxa de crescimento em alguns municipios no RN (1995-2014)'

# Configuracoes do eixo horizontal
set xrange[1995:2014]				# Faixa de valores
set xtics 1 						# Salto de valores
set xtic rotate by -45 scale 0		# Rotacao dos rotulos

# Configuracoes do eixo vertical
set ylabel "Taxa de crescimento (%)"
set ytics 25
set yrange[-100.00:470.00]					# Faixa de valores

# Selecao do tipo de grafico a ser gerado (linha)
set style data lines							# Plot com linhas
set style line 1 lw 2 lc rgb "blue" pointtype 6	# Plota primeira cidade com cor azul

# Mostra nome de graficos e uma amostra
set key

# Plotagem do grafico
# Os dado a serem plotados costam no arquivo extra.dat
# ==========================================================================
# Armazena o numero de cidades presentes na primeira linha do arquivo + 1
cidades = words(system("head -n 1 extra.dat")) + 1

# Plotando
plot for [i=2:cidades] 'extra.dat' using 1:i title columnhead(i-1) smooth freq with lines 