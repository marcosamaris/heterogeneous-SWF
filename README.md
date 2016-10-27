# SWF of Task-based Application over heterogeneous resource

The benchmark is composed of six parallel applications. Five of them have been generated from Chameleon, a dense linear algebra software which is part of the MORSE project~\cite{agullo2012morse}, while the sixth has been generated with GGen, a library for generating directed acyclic graphs~\cite{GGen:simutools10}, and it corresponds to a more irregular application.

The five applications of Chameleon, named \emph{getrf$\_$nopiv}, \emph{posv}, \emph{potrs}, \emph{potri} and \emph{potrs}, are composed of multiple sequential basic tasks of linear algebra such as \emph{SYRK} (symetric rank update), \emph{GEMM} (general matrix-matrix multiply) and \emph{TRSM} (triangular matrix equation solver), as shown in Table~\ref{tab:kernels}. 
\begin{table}[htpb]
\begin{center}
\caption{Basic kernel of linear algebra of each application}
\scalebox{0.75}{
\begin{tabular}{|c|c|c|c|c|c|c|}
	\hline
	\backslashbox{\bf Kernels}{\bf Apps} & {\bf getrf$\_$nopiv} & {\bf posv} & {\bf potrf} & {\bf potri} & {\bf potrs}\\
	\hline
	{\bf syrk}& & x & x & x & \\
	\hline
	{\bf gemm}& x & x & x & x & x \\
	\hline
	{\bf trsm}& x & x & x & x & x \\
	\hline
\end{tabular}}
\label{tab:kernels}
\end{center}
\end{table}
To generate the applications, different tilings of the matrices have been used, varying the number of sub-matrices denoted by $nb\_blocks$ and the size of the sub-matrices denoted by $block\_size$. The different values of $nb\_blocks$ were 5, 10 and 20 and the different values of $block\_size$ were 64, 128, 320, 512, 768 and 960, for a total of 18 configurations per application. Table \ref{fig:nb_tasks} shows the total number of tasks for each application and each value of $nb\_blocks$. Notice that the value of $block\_size$ does not impact the number of tasks.

\begin{table}[htpb]
\begin{center}
\caption{Total number of tasks in function of the number of blocks}
\scalebox{0.75}{
\begin{tabular}{|c|c|c|c|c|c|c|}
	\hline
	\backslashbox{\bf Nb$\_$blocks}{\bf Apps} & {\bf getrf$\_$nopiv} & {\bf posv} & {\bf potrf} & {\bf potri} & {\bf potrs} \\
	\hline
	{\bf 5} & 55 & 65 & 35 & 105 & 30 \\
	\hline
	{\bf 10} & 385 & 330 & 220 & 660 & 110 \\
	\hline
	{\bf 20} & 2870 & 1960 & 1540 & 4620 & 420 \\
	\hline
\end{tabular}}
\label{fig:nb_tasks}
\end{center}
\end{table}
The Chameleon applications were executed with the runtime StarPU~\cite{Augonnet:StarPU} and the traces of executions were collected. At first, all the applications were executed on CPUs and then were forced to execute on GPUs to have the processing times of each task of the application for both computing units.

The machine where this data was collected had the following hardware characteristics: Dual core Xeon E7 v2, with a total of 20 physical cores  with hyper-threading of 3 GHz of processor base Frequency, 256 GB of RAM, operative system Linux Ubuntu 14.04. This machine had 4 GPUs NVIDIA Tesla K20 with each 4 GB of global memory, 200 GB/s of bandwidth and 2496 cores divided in 13 multiprocessors.

The execution time of each task and their respective dependencies were collected and formatted in different files, in SWF~(Standard Workload Format).
%The SWF was defined in order to ease the use of workload logs and models. With it, programs that analyze workloads or simulate system scheduling need only to be able to parse a single format, and can be applied to multiple workloads. 
The data set and other information are available\footnote{Hosted at: \url{https://github.com/marcosamaris/heterogeneous-SWF} [Accessed on 19 October 2016]} under Creative Commons Public License for the sake of reproducibility.

The application generated with GGen is \emph{fork-join}. It represents a real application that starts by executing sequentially and then forks to be executed in parallel with a specific diameter (number of parallel tasks), when the parallel execution has completed, results are aggregated by performing a join operation. This procedure can be repeated several times depending on the number of phases. For our experiments, we used 2, 5 and 10 phases with a diameter of 100, 200, 300, 400 and 500 for a total of 15 different configurations. Table \ref{fig:nb_tasksFork} shows the total number of tasks for each configuration of the fork-join application.

\begin{table}[htpb]
\begin{center}
\caption{Total number of tasks in function of the number of phases and the width of the phase}
\scalebox{0.8}{
\begin{tabular}{|c|c|c|c|c|c|c|}
	\hline
	\backslashbox{\bf Nb$\_$phases}{\bf Diameter} & {\bf 100} & {\bf 200} & {\bf 300} & {\bf 400} & {\bf 500} \\
	\hline
	{\bf 2} & 203 & 403 & 603 & 803 & 1003 \\
	\hline
	{\bf 5} & 506 & 1006 & 1506 & 2006 & 2506 \\
	\hline
	{\bf 10} & 1011 & 2011 & 3011 & 4011 & 5011 \\
	\hline
\end{tabular}}
\label{fig:nb_tasksFork}
\end{center}
\end{table}
The running time of each task was computed using a Gaussian distribution with center $p$ and standard deviation $\frac{p}{4}$, where $p$ is the number of phases. We have decided to establish various acceleration factors in each diameter of fork. In this way, for all the configurations there are five parallel tasks with an acceleration factor between $0.1$ and $0.5$ while the others have an acceleration factor between $0.5$ and $50$.
