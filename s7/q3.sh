#!/bin/bash

read -s -p "Enter password: " pass
echo " "

if [ $pass == "123456" ]
then
echo "Welcome"
else
echo "Wrong password"
fi
