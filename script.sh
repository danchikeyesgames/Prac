#!/bin/bash
#LAB21

file1=$1;
count=$2
i=0
if [ -e $file1 ]
    then 
        echo "The $file1 found"
        mkdir split
        cd split
        cp ../$file1 filetmp
        for var in $(cat filetmp)
            do
                i=$(($i+1))
            done
        m=$(($i/$2))
        if [ $(($i%$2)) -eq 0 ] 
            then 
                n=$m
            else 
                n=$(($m+1))
        fi
        for ((k=1;k<=n;k++)) {
            #cat filetmp
            head -n$count filetmp > "output$k"
            echo "$k || $i"
            i=$(($i-$2))
            tail -n$i filetmp > tmp
            cat tmp > filetmp
        }
        rm tmp
        rm filetmp
        cd ..
        mv split block
        echo "Finished..."
    else 
        echo "The $file1 not found"
fi
