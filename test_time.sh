#!/bin/bash
for (( i=1; i <= 1000; i++ ))
do
	./generator test 26 
	tm="$(time ./fillit test > /dev/null)"
	if [ $tm -gt 30 ]
	then
		break
	fi
done
