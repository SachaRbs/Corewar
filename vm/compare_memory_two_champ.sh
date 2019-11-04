#!/bin/bash
make
CYCLE=0
PRINT_CYCLE=0
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
	./corewar -d $CYCLE ../ressources/vm_champs/champs/$1.cor ../ressources/vm_champs/champs/$2.cor > $OUR_FILE
	../ressources/vm_champs/corewar -v 22 -d $CYCLE ../ressources/vm_champs/champs/$1.cor ../ressources/vm_champs/champs/$2.cor > $THEM_FILE
	diff $OUR_FILE $THEM_FILE > $DIFF_FILE
	if [ -s $DIFF_FILE ]
	then
		echo "Cycle "$CYCLE" is incorrect"
		cat $DIFF_FILE
		break
	else
		echo "Cycle "$CYCLE" is correct"
		let "CYCLE = CYCLE + 25"
	fi
done