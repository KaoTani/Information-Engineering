#!/bin/sh

MESSAGE="0 1"
NVAR1=0
NVAR2=1
i=0

while test true
do
    if test `expr $NVAR1 + $NVAR2` -gt 1000
    then
        break
    fi

    if [ `expr $i % 2` -eq 0 ]
    then
        NVAR1=`expr $NVAR1 + $NVAR2`
        MESSAGE="$MESSAGE $NVAR1"
    else
        NVAR2=`expr $NVAR1 + $NVAR2`
        MESSAGE="$MESSAGE $NVAR2"
    fi
    i=`expr $i + 1`
done

echo $MESSAGE

#AJG23085 谷口香央
#1000までで終わらせるのが大変だった。