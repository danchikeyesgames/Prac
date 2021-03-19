#!/bin/bash
#LAB21

file1=$1;
count=$2;
if [ -e $file1 ]
    then 
        echo "The $file1 found"
        mkdir split
        cd split
        cp ../$file1 filetmp
        i=`wc -l < ../$1`
        echo "strtok $i"
        if [ $(($i%$count)) -eq 0 ]
            then
            n=$(($i/$count));
            else
            n=$(($i/$count));
            n=$(($n+1));
        fi
        echo $n
        for ((k=1;k<=n;k++)) {
            head -n$count filetmp > "output$k"
            echo "$k || $i"
            i=$(($i-$count))
            tail -n$i filetmp > tmp
            cat tmp > filetmp
        }
        rm tmp
        rm filetmp
        cd ..
        if [ -e block ]
            then
            rm -rf block
        fi
        mv split block
        echo "Finished..."
    else 
        echo "The $file1 not found"
fi