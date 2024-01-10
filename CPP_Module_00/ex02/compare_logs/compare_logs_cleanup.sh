#!/bin/bash

if [ -f recreated.log ] ; then 
    rm *.log
    echo "Compare_logs_cleanup: recreated.log and comparison files deleted ✅"
else
    echo "Compare_logs_cleanup: Nothing to cleanup."
fi
