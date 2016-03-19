#!/usr/bin/python

from glob import glob
import sys
import re
import os
import subprocess
import argparse

import csv as csv
import pandas as pd
import numpy as np

apps=["spotrf", "sgetrf_nopiv", "sgeqrf"]
TILE=[64, 128, 256, 320, 512, 640, 768, 960]
sizes=[1, 8, 20, 50, 100]


csv_names=['Nature', 'ResourceId', 'Type', 'Start', 'End', 'Duration', 'Depth',
            'Value', 'Footprint', 'JobId', 'Params', 'Size', 'Tag']

swf_names=["Job Number", "Submit Time","Wait Time", "Run Time", "Number of Allocated Processors", "Average CPU Time Used", "Used Memory"
            "Requested Number of Processors", "Requested Time", "Requested Memory", "Status", "User ID", "Group ID", 
            "Executable (Application) Number", "Queue Number", "Partition Number", "Preceding Job Number", "Think Time"]

for app in apps:
    os.system("mkdir -p ./" + app)      
    for tile in TILE:
        for i in sizes:
             df = pd.read_csv("../csv/" + app + "/" + app + "-" + str(tile) + "-" + str(i) + ".csv", names=csv_names) 
             
             df.dropna(how='any',inplace=True)        
             df.sort(' JobId ', ascending=True, inplace=True)
             
             df_swf = pd.DataFrame({csv_names : [-1]})
             
             
             
             
             
                


