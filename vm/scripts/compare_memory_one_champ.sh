#!/bin/bash
make
CYCLE=20000
OUT_CONDITION=1

DIFF_FILE="diff"
OUR_FILE="our"
THEM_FILE="them"

if [ -f $DIFF_FILE ]
then
	rm -f $DIFF_FILE
fi
touch $DIFF_FILE
while [ $OUT_CONDITION ]
do
	./corewar -v 1 -d $CYCLE ../ressources/vm_champs/champs/championships/$1 > $OUR_FILE
	../ressources/vm_champs/corewar -v 2 -d $CYCLE ../ressources/vm_champs/champs/championships/$1 > $THEM_FILE
	diff $OUR_FILE $THEM_FILE > $DIFF_FILE
	if [ -s $DIFF_FILE ]
	then
		echo "Cycle "$CYCLE" is incorrect"
		cat $DIFF_FILE
		break
	else
		echo "Cycle "$CYCLE" is correct"
		let "CYCLE = CYCLE + 10000"
	fi
done