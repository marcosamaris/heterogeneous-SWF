set key left top

if (exists("log")) set logscale y; set format y "%.3g"; set key right bottom

filter = 'cat'
cols = ""
data = ""
title = ""
set datafile missing "inf"
min(x, y) = (x < y ? x : y)
title(i) = "No title"

set xlabel "Matrix order"
set ylabel yaxis
set terminal format
set output output
set format x "%.3g"
set xtics nomirror rotate by -20
do  for [i=1:words(files)] {
 	data = data."data/".word(files, i).".dat "
}
do for [j=1:words(nbprocs)] {
	prefix = "grep ^[[:space:]]*".word(nbprocs,j)
	plotfiles=system(prefix." -l ".data)
	if (words(plotfiles) > 0) {
		do  for [i=1:words(plotfiles)] {
			title(i)=sprintf("head -1 %s | sed 's/^#//'",word(plotfiles,i))
			cols=cols.system("head -2 ".word(plotfiles,i)." | grep ".test." | awk '{ for(i=1;i<NF;i++){ if($i ~ /".test."/) {print i}}'}")." "
		}
		print word(nbprocs,j)
		print system(title(i)).sprintf(" with %s procs",word(nbprocs,j))
		plot for [i=1:words(plotfiles)] '< '.prefix.' '.word(plotfiles, i) using 2:col title system(title(i)).sprintf(" with %s procs",word(nbprocs,j)) with linespoints lw 3 lt rgb word(colors, i)
	}
}
