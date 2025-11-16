#!/bin/bash

g++ -std=c++17 random.cpp -o random
g++ -std=c++17 taki.cpp -o taki
g++ -std=c++17 test.cpp -o test

for ((i=1;;i++))
do
    ./random > /dev/null
    if [ $? -ne 0 ]; then
        echo " random.cpp crashed at iteration $i"
        break
    fi

    ./taki < in.txt > out1.txt
    if [ $? -ne 0 ]; then
        echo " taki.cpp crashed (Segfault or Runtime Error) at iteration $i"
        echo "Input that caused the crash:"
        cat in.txt
        break
    fi

    ./test < in.txt > out2.txt
    if [ $? -ne 0 ]; then
        echo " test.cpp crashed (Segfault or Runtime Error) at iteration $i"
        echo "Input that caused the crash:"
        cat in.txt
        break
    fi

    diff -w out1.txt out2.txt > diff.txt
    if [ $? -ne 0 ]; then
        echo " Output mismatch on iteration $i"
        echo "Input:"
        cat in.txt
        echo "Your output:"
        cat out1.txt
        echo "Expected output:"
        cat out2.txt
        break
    else
        echo " Test $i passed"
    fi
done
