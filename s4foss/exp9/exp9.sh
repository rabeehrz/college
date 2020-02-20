#!/bin/sh

cpulim=2.0;
memlim=2.0;
while true; do
	ps -e -o pmem=,pcpu=,pid=,user= | sort -r -k 1 | while read mem cpu pid user; do
		kill_mem=0
		kill_cpu=0
		if [ "$user" = "mohammedrabeeh" ]; then
			kill_mem=`echo "$mem > $memlim " | bc`
			kill_cpu=`echo "$cpu > $cpulim " | bc`
			if [[ "$kill_mem" == 1 ]]; then
				echo "KILL: $pid"
			elif [[ "$kill_cpu" == 1 ]]; then
				echo "KILL: $pid"
			fi
		fi
	done
done
