# Inicialização
clear
reset
set key off

# Configuracoes de saida: inclui formato de exportaxao, tamanho do grafico,
# fontes utilizadas e nomes do arquivo de saida

# Exportacao para o formato .png
set terminal png size 640,480 enhanced font 'Helvetica,12'
set output 'histograma.png'

# Exportacao para o formato .jpg
# set terminal jpeg size 640,480 enhanced font 'Helvetica' 12
# set output 'histograma.jpg'

# Exportacao para o formato .svg
# set terminal svg size 640,480 enhanced background rgb 'white' fname 'Helvetica' fsize 14 butt solid
# set output 'histograma.jpg'

# Titulo do grafico
set title 'Total de nascidos vivos no RN (1994-2014)'

# Configuracoes do eixo horizontal
set xrange[1994:2014]				# Faixa de valores
set xtics 1 						# Salto de valores
set xtic rotate by -45 scale 0		# Rotacao dos rotulos

# Configuracoes do eixo vertical
set yrange[0:80000]					# Faixa de valores

# Selecao do tipo de grafico a ser gerado (histograma)
set style data histogram
set style histogram clustered gap 1
set style fill solid border -1		# Preenchimento e contorno
set linetype 1 lc rgb 'green'		# Cor
set boxwidth 0.6					# Largura das barras verticais

# Plotagem do grafico
# Os dado a serem plotados costam no arquivo totais.dat
plot 'totais.dat' using 1:2 title '' smooth freq with boxes