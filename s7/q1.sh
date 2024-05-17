#!/bin/bash
a=$1
b=$2
echo "num1 = $a"
echo "num2 = $b"
sum=$(( $1+$2 ))
echo "sum = $sum"

if [ $a -gt $b ] 
then
echo "$a is the bigger number"
fi

if [ $b -gt $a ]
then
echo "$b is the bigger number"
fi

let a=$a+1

t=0
cnt=0

for (( i=$a; i<$b; i++ ))
do
let cnt=$cnt+1
let t=$t+i
echo $i
done

let avg=$t/$cnt
echo "avg = $avg"

