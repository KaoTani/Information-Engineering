#!/bin/sh

cd test_dir
i=1

for files in $(ls *.jpg)
do
    mv $files place$i.jpg
    i=`expr $i + 1`
done

#AJG23085 谷口香央
#シェルスクリプトって意外と少ない行で書けて驚いた。