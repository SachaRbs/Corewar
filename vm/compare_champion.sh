#!/bin/bash
make

DIFF_FILE="diff"
OUR_FILE="our_champ"
THEM_FILE="their_champ"

if [ -f $DIFF_FILE ]
then
	rm -f $DIFF_FILE
fi
touch $DIFF_FILE
./corewar ../ressources/vm_champs/champs/$1 ../ressources/vm_champs/champs/$2 > $OUR_FILE
../ressources/vm_champs/corewar -v 2 ../ressources/vm_champs/champs/$1 ../ressources/vm_champs/champs/$2 > $THEM_FILE
diff $OUR_FILE $THEM_FILE > $DIFF_FILE
cat $DIFF_FILE