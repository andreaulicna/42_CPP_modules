#!/bin/bash

(cd ../ ; make ; ./gbu > compare_logs/recreated.log)

echo "Compare_logs: recreated.log created ✅"

head -19 ../19920104_091532.log > original_1.log
head -38 ../19920104_091532.log  | tail -19 > original_2.log
head -57 ../19920104_091532.log | tail -19 > original_3.log
tail -2 ../19920104_091532.log > original_4.log

head -19 recreated.log > recreated_1.log
head -38 recreated.log  | tail -19 > recreated_2.log
head -57 recreated.log | tail -19 > recreated_3.log
tail -2 recreated.log > recreated_4.log

echo "Compare_logs: recreated.log split into 4 parts for comparison ✅"
