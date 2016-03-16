#!/usr/bin/python

##
# This script uses pj_dump and starpu_page_state_states.in to extract the
# different events and their durations in order to compute the times spent in
# the runtime, in the tasks and in the pipeline. For a given trace, it extracts
# some information from its name and it generates a CSV file with the different
# times as explained above.
#
# Required dependencies:
# - pj_dump (cf. https://github.com/schnorr/pajeng)
# - starpu_paje_state_stats.in (cf. starpu/trunk/tools)
##
import getopt
import os
import re
import subprocess
import sys

def is_tr(event):
    if (event == "Initializing"     or
        event == "Deinitializing"   or
        event == "FetchingInput"    or
        event == "PushingOutput"    or
        event == "Scheduling"       or
        event == "Overhead"         or
        event == "Callback"         or
        event == "execute_on_all_wrapper"): # Weird?
        return True
    return False

def is_ti(event):
    if (event == "Idle" or
        event == "Sleeping"):
        return True
    return False

def is_tt(event):
    if (event.startswith("L2L")      or
        event.startswith("L2P")      or
        event.startswith("M2L")      or
        event.startswith("M2L-out")  or
        event.startswith("M2M")      or
        event.startswith("P2M")      or
        event.startswith("P2P")      or
        event.startswith("P2P-out")  or
        event.startswith("UnnamedTask")): # Klang
        return True
    return False

def which(file):
    for path in os.environ["PATH"].split(os.pathsep):
        if os.path.exists(os.path.join(path, file)):
            return os.path.join(path, file)
    return None

def paje_to_stats(file):
    cmd = "starpu_paje_state_stats.in -v " + file
    proc = subprocess.Popen(cmd.split(), stdout=subprocess.PIPE)
    stdout, stderr = proc.communicate()
    if not proc.returncode == 0:
        return (proc.returncode, stdout.decode())
    return (0, stdout.decode())

def main():
    if len(sys.argv) != 3:
        print sys.argv[0] + " <trace.paje> <compiler>"
        sys.exit(1)
    trace = sys.argv[1]
    compiler = sys.argv[2]

    # Make sure required tools are available.
    if which("pj_dump") == None:
        sys.exit("Failed to locate 'pj_dump' in your $PATH!")
    if which ("starpu_paje_state_stats.in") == None:
        sys.exit("Failed to locate 'starpu_paje_state_stats.in' in your $PATH")

    # Extract simulation parameters from the trace filename.
    prolate = True # Assume it's a non-uniform simu
    m = re.search("(.*)_algo_grouptask_nb_(.*)_h_(.*)_bs_(.*)_o_(.*)_prolate_t_(.*).paje",
                  trace)
    if not m:
        prolate = False
        # Uniform?
        m = re.search("(.*)_algo_grouptask_nb_(.*)_h_(.*)_bs_(.*)_o_(.*)_t_(.*).paje",
                      trace)
        if not m:
            print "Failed to extract simulation parameters. Malformed filename?"
            sys.exit(2)
 
    # Set simulation parameters from the regex.
    npart    = m.group(2)
    height   = m.group(3)
    bsize    = m.group(4)
    order    = m.group(5)
    nthreads = m.group(6)

    # Convert Paje trace using starpu_paje_state_stats script.
    ret, stdout = paje_to_stats(trace)
    if not ret == 0:
        print stdout
        sys.exit("Failed to get stats from the Paje trace!")

    # Initialize different times.
    tr = 0.0    # runtime
    tt = 0.0    # task
    ti = 0.0    # idle

    # Compute runtime, task and idle times.
    first_line = False
    for line in stdout.splitlines():
        # Get rid of the header.
        if first_line == False:
            first_line = True
            continue
        
        arr = line.replace("\"", "").split()
        if is_tr(arr[0]):
            tr += float(arr[2])
        elif is_ti(arr[0]):
            ti += float(arr[2])
        elif is_tt(arr[0]):
            tt += float(arr[2])
        else:
            print "[WARN] Unknown event '" + arr[0] + "'!"

    output_filename = compiler + ".db"
    if not os.path.isfile(output_filename):
        output = open(output_filename, "w")
        output.write("\"nthreads\"")
        output.write(",\"name\"")
        output.write(",\"npart\"")
        output.write(",\"height\"")
        output.write(",\"bsize\"")
        output.write(",\"order\"")
        output.write(",\"prolate\"")
        output.write(",\"event\"")
        output.write(",\"duration\"")
        output.write("\n")
        output.close()

    output = open(output_filename, "a")

    # Runtime
    output.write(nthreads)
    output.write("," + "\"" + compiler + "\"")
    output.write("," + npart)
    output.write("," + height)
    output.write("," + bsize)
    output.write("," + order)
    output.write("," + "\"" + str(prolate) + "\"")
    output.write("," + "\"runtime\"")
    output.write("," + str(tr))
    output.write("\n")

    # Task
    output.write(nthreads)
    output.write("," + "\"" + compiler + "\"")
    output.write("," + npart)
    output.write("," + height)
    output.write("," + bsize)
    output.write("," + order)
    output.write("," + "\"" + str(prolate) + "\"")
    output.write("," + "\"task\"")
    output.write("," + str(tt))
    output.write("\n")
    
    # Idle
    output.write(nthreads)
    output.write("," + "\"" + compiler + "\"")
    output.write("," + npart)
    output.write("," + height)
    output.write("," + bsize)
    output.write("," + order)
    output.write("," + "\"" + str(prolate) + "\"")
    output.write("," + "\"idle\"")
    output.write("," + str(ti))
    output.write("\n")

    output.close()

if __name__ == "__main__":
    main()
