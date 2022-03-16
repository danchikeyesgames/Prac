#!/bin/bash

NAME_FILE="file"
COUNT=1
FILEIN=$1
STRING=$2

if [ -e $FILEIN ]
    then
        if [ -z $STRING ]
            then
                echo "[Incorrected format] >./task.sh [name file] [number]"
            else
                NUM=$(wc -l $FILEIN | awk '{print $1}')
                KEY=$((NUM / STRING))
                if [ $KEY -eq 0 ]
                    then
                        echo "Your number bigger than strings of files"
                        mkdir out
                        head -n$NUM $FILEIN > out/file1
                    else
                        if [ $(($NUM % $STRING)) -ne 0 ]
                            then
                                KEY=$(($KEY + 1))
                        fi

                        mkdir out
                        for ((k=1;k<=KEY;k++)) {
                            head -n$(($STRING * k)) $FILEIN | tail -n $(( $STRING - (k / KEY) * (-$NUM + $STRING * (k - 1) + $STRING) )) > "out/$NAME_FILE$COUNT"
                            COUNT=$(($COUNT + 1))
                        }
                fi
        fi
    else
        echo "File $FILEIN not found"
fi