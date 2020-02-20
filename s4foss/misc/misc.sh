#!/bin/sh

select term in \
	'Batman' \
	'Superman' \
	'Tiger' \
	'Bronco'
do
	echo "You selected $REPLY"
done
