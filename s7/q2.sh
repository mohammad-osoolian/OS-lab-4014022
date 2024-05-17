#!/bin/bash
read -p "Enter operator (+ - * /): " op
n1=$1
n2=$2

echo "n1 = $n1"
echo "n2 = $n2"
echo "op = $op"

case $op in 
+) res=$(($n1 + $n2));;
-) res=$(expr $n1 - $n2);;
\*) res=$(($n1*$n2));;
/) res=$(expr $n1 / $n2);;
esac

echo "result = $res"
