# SWF of Task-based Applications over heterogeneous resources
Here a set of Benchmarks of two different works are stored, these Benchmark are saved in files SWF (Standard Workload Files). Those SWF is the result of different Workloads executed in different heterogeneous mahcines wuth GPUs and CPUs. These files are used to design new techniques of scheduling based-tasks applications with constraint of dependencies (These dependencies form a Direct Acyclic Graph). 

There are two folders in this repository, 2_resources and 3_resources, in the first are stored the data used for the work "Generic algorithms for scheduling applications on hybrid multi-core machines", predented in the International European Conference on Parallel and Distributed Computing of 2017. The second folder, 3_resources, stores the files created of the data collected over 3 differents resource types.

The benchmark is composed of six parallel applications. Five of them have been generated using Chameleon, a dense linear algebra software which is part of the MORSE project~\cite{agullo2012morse}, another applications has been synthetically generated with GGen, a library for generating Directed Acyclic Graphs~\cite{GGen:simutools10}.

The five applications of Chameleon, named \emph{getrf$\_$nopiv}, \emph{posv}, \emph{potrs}, \emph{potri} and \emph{potrs}, are composed of multiple sequential basic tasks of linear algebra such as \emph{SYRK} (symetric rank update), \emph{GEMM} (general matrix-matrix multiply) and \emph{TRSM} (triangular matrix equation solver). For both workloads (2_resources and 3_resources), The Chameleon applications were executed with the runtime StarPU~\cite{Augonnet:StarPU} and the traces of executions were collected. At first, all the applications were executed on CPUs and then were forced to execute on GPUs to have the processing times of each task of the application for different resources.
    
To generate the applications, different tilings of the matrices have been used, varying the number of sub-matrices denoted by $nb\_blocks$ and the size of the sub-matrices denoted by $block\_size$. The different values of $nb\_blocks$ were 5, 10 and 20 and the different values of $block\_size$ were 64, 128, 320, 512, 768 and 960, for a total of 18 configurations per application. Table \ref{fig:nb_tasks} shows the total number of tasks for each application and each value of $nb\_blocks$. Notice that the value of $block\_size$ does not impact the number of tasks.

### Total number of tasks in function of the number of blocks

|**Nb_blocks\Apps** | **getrf_nopiv** | **posv** | **potrf** | **potri** | **potrs** |
|---------| --- | ----- | -----| ----- | ----- |
|**5** | 55 | 65 | 35 | 105 | 30 |
|**10** | 385 | 330 | 220 | 660 | 110 |
|**20** | 2870 | 1960 | 1540 | 4620 | 420 |
    
For the setting with 2 resource workload, the applications were executed on a machine with two Dual core Xeon E7 v2 with a total of 10 physical cores with hyper-threading of 3 GHz and 256 GB of RAM. The machine had 4 GPUs NVIDIA Tesla K20 (Kepler architecture) with each 5 GB of memory and 200 GB/s of bandwidth.

For 3 resource types, the applications were executed on an Intel  Dual core i7-5930k machine with a total of 6 physical cores with hyper-threading of 3.5 GHz and 12 GB of RAM. This machine had 2 NVIDIA GPUs: a GeForce GTX-970 (Maxwell architecture) with 4 GB of memory and 224 GB/s of bandwidth; and a Quadro K5200 (Kepler architecture) with 8 GB of memory and 192 GB/s of bandwidth.

The execution time of each task and their respective dependencies were collected and formatted in different files, in SWF~(Standard Workload Format).
%The SWF was defined in order to ease the use of workload logs and models. With it, programs that analyze workloads or simulate system scheduling need only to be able to parse a single format, and can be applied to multiple workloads. 
The data set and other information are available\footnote{Hosted at: \url{https://github.com/marcosamaris/heterogeneous-SWF} [Accessed on 19 October 2016]} under Creative Commons Public License for the sake of reproducibility.

The application generated with GGen is \emph{fork-join}. It represents a real application that starts by executing sequentially and then forks to be executed in parallel with a specific diameter (number of parallel tasks), when the parallel execution has completed, results are aggregated by performing a join operation. This procedure can be repeated several times depending on the number of phases. For our experiments, we used 2, 5 and 10 phases with a diameter of 100, 200, 300, 400 and 500 for a total of 15 different configurations. Table \ref{fig:nb_tasksFork} shows the total number of tasks for each configuration of the fork-join application.


### Total number of tasks in function of the number of phases and the width of the phase

|**Nb_phases\Diameter** | **100** | **200**| **300** | **400** | **500**| 
|--- | --- | --- | --- | --- | --- |    
|**2** | 203 | 403 | 603 | 803 | 1003 |
|**5** | 506 | 1006 | 1506 | 2006 | 2506 |
|**10** | 1011 | 2011 | 3011 | 4011 | 5011 |
