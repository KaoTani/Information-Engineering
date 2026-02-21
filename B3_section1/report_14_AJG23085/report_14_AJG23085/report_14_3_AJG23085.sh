#!/bin/sh

mkdir bk

INTERVAL=3
for file in *
do
    if [ "$file" != "bk" ] && [ -f "$file" ]
    then
        cp "$file" "bk/$file"
    fi
    sleep $INTERVAL
done

#AJG23085 谷口香央
#sleepの入れるタイミングがわからなくて苦戦した