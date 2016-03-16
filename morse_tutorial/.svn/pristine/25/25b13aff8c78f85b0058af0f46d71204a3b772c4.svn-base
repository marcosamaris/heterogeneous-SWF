#!/usr/bin/python

import sys, getopt

def main(argv):

    input_file = open(argv[0], 'r')

    alltimes = {}
    allstatu = {}
    allbegin = {}
     
    for line in input_file:
        sl = line.split()
        if len(sl)==0:
            continue
        if sl[0]=='7' :
            # print sl[2].find('t', 0, 0), sl[2]
            if sl[2].find(argv[1]) == 0:
                if not alltimes.has_key(sl[2]):
                    alltimes[sl[2]] = {} #{'I':0, 'D':0, 'Fi':0, 'Po':0, 'C':0, 'B':0, 'E':0, 'Sc':0, 'Sl':0, 'P':0, 'U':0}
                    allstatu[sl[2]] = 'no'
                    allbegin[sl[2]] = -1
        elif sl[0]=='10' or sl[0]=='20':
            if alltimes.has_key(sl[2]):
                # print 'Fucking error 1 '+sl[2]
            # else:
                thread = sl[2]
                t      = float(sl[1])
                if allstatu[thread] != 'no':
                    if alltimes[thread].has_key(allstatu[thread]):
                        alltimes[thread][allstatu[thread]] += t-float(allbegin[thread])
                    else:
                        alltimes[thread][allstatu[thread]]  = t-float(allbegin[thread])
                else:
                    alltimes[thread]['P']  = t-float(allbegin[thread])
     
                allbegin[thread] = t
                allstatu[thread] = sl[4]
                # print 'Fucking error 1 '+sl[4]
                
        elif sl[0]=='9':
            if sl[4]=='stop_profiling':
                stopt = float(sl[1])
     
    # for th in alltimes:
        # if alltimes[thread].has_key('Sl'):
            # alltimes[th]['Sl'] += stopt-float(allbegin[th])
        # else:
            # alltimes[th]['Sl'] = stopt-float(allbegin[th])
            
    glob_tt_time = 0
    glob_ov_time = 0
    glob_sl_time = 0
    glob_ex_time = 0
    # print alltimes
    for th in alltimes:
        th_tt_time  = sum(alltimes[th].values())
        th_sl_time  = alltimes[th]['Sl']
        th_ex_time  = 0
        if(argv[1]=='w'):
            if(alltimes[th].has_key('GEMQRT'    )): th_ex_time += alltimes[th]['GEMQRT'    ]
            if(alltimes[th].has_key('GEQRT'     )): th_ex_time += alltimes[th]['GEQRT'     ]
            if(alltimes[th].has_key('TPQRT'     )): th_ex_time += alltimes[th]['TPQRT'     ]
            if(alltimes[th].has_key('TPMQRT'    )): th_ex_time += alltimes[th]['TPMQRT'    ]
            if(alltimes[th].has_key('INIT'      )): th_ex_time += alltimes[th]['INIT'      ]
            if(alltimes[th].has_key('Do_subtree')): th_ex_time += alltimes[th]['Do_subtree']
            if(alltimes[th].has_key('ASM'       )): th_ex_time += alltimes[th]['ASM'       ]
            if(alltimes[th].has_key('CLEAN'     )): th_ex_time += alltimes[th]['CLEAN'     ]
        elif(argv[1]=='t'):
            th_ex_time = alltimes[th]['E']
        th_ov_time = th_tt_time-th_sl_time-th_ex_time
        glob_tt_time += th_tt_time
        glob_ex_time += th_ex_time
        glob_ov_time += th_ov_time
        glob_sl_time += th_sl_time
        # print th,' ',th_ex_time/th_tt_time,th_sl_time/th_tt_time,th_ov_time/th_tt_time
     
    # print '\nGlobal: ',glob_ex_time/glob_tt_time,glob_sl_time/glob_tt_time,glob_ov_time/glob_tt_time

    print("%-50s        (exec., idle, ohead): %10.0f (%6.3f),  %10.0f (%6.3f),   %10.0f (%6.3f)  = %10.0f"%(argv[0],glob_ex_time,glob_ex_time/glob_tt_time,glob_sl_time,glob_sl_time/glob_tt_time,glob_ov_time,glob_ov_time/glob_tt_time,glob_tt_time))

if __name__ == "__main__":
   main(sys.argv[1:])    

