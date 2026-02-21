#!/bin/sh

NVAR1=10
NVAR2=0

while test $NVAR1 -lt 100000
do
    NVAR1=`expr $NVAR1 \* 10`
    while test $NVAR2 -lt 10
    do
        NVAR2=`expr $NVAR2 + 1`
        ./report_15_AJG23085 $NVAR1 $NVAR2>> report_15_AJG23085-$NVAR1.txt
    done
    echo "$NVAR1 $(awk -f report_15_AJG23085.awk report_15_AJG23085-$NVAR1.txt)" >> report_15_AJG23085.txt 
    NVAR2=0
done

#AJG23085 谷口香央
#シェルスクリプトおもしろい！