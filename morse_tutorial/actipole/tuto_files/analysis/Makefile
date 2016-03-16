# methods = bind_scotch bind ternd classic pastix
methods:=$(shell cat config_tests.in | grep ^METHODS= | cut -d "=" -f 2)
t:=$(shell cat config_tests.in | grep ^TESTS_FOLDER= | cut -d "=" -f 2)
data=$(addprefix data/,$(addsuffix .dat,$(methods)))
files=$(shell ls $(t))
outputs=$(addprefix $(t)/,$(files))
f=pdf
times=times.$(f)
# mem_before=memory_before.$(f)
mem=memory.$(f)
nnz=nnz.$(f)
err=err.$(f)
out= $(times) $(mem_before) $(mem) $(nnz) $(err)
# names = $(foreach X,$(methods),`cat $(name_file) | grep $X | cut -d ' ' -f 2`)
colors = red green blue black yellow brown orange darkmagenta lightsalmon mediumaquamarine

define get-col =
echo $(2);
$(1) := $(shell cat config_tests.in | sed '2q;d' | grep $(2) | uniq | awk '{ for(i=1;i<NF;i++){ if($i ~ /$(2)/) {print i}}'});
endef

time_col = 3
mem_col = 4
nnz_col = 5
err_col = 6
nb_procs = 1 2 4 8

a:
	echo $(time_col)
	
all: times 

$(data):data/%.dat: $(outputs) read_data.sh
	./read_data.sh $(t) $*

$(methods):%: $(data) $(outputs)

$(times): $(data) plot_data.gp
	gnuplot -e "test='facto';format='$(f)';output='$(times)';yaxis='time (s)';type='times';col=$(time_col);log=1;files='$(methods)';colors='$(colors)';nbprocs='$(nb_procs)';" plot_data.gp

$(mem): $(methods) plot_data.gp
	gnuplot -e "test='memory';format='$(f)';output='$(mem)';yaxis='Memory used (Bytes)';type='memory';col=$(mem_col);files='$(methods)';colors='$(colors)';nbprocs='$(nb_procs)';" plot_data.gp

$(nnz): $(methods) plot_data.gp
	gnuplot -e "test='nnz';format='$(f)';output='$(nnz)';yaxis='Number of non-zeros';type='memory';col=$(nnz_col);files='$(methods)';colors='$(colors)';nbprocs='$(nb_procs)';" plot_data.gp

$(err): $(methods) plot_data.gp
	gnuplot -e "test='err';format='$(f)';output='$(err)';yaxis='Relative error';type='err';col=$(err_col);log=1;files='$(methods)';colors='$(colors)';nbprocs='$(nb_procs)';" plot_data.gp
# R --save --args mumps.dat alpha < R.r

new:
	./set_new_tests.sh -t $(t) -m $(m)

times: $(times)
mem: $(mem) 
nnz: $(nnz)
err: $(err)
# plot: $(times) $(mem) $(nnz)
plot: $(times) 
	evince $^ & 

clean:
	rm -f $(out)
dclean: clean
	rm -f $(data)
vclean: clean
	rm -f *.dat
