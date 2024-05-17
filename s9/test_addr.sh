ping $1 -c 3

if [ $? -eq 0 ]; 
then
	echo ""
	echo "Done"
else
	echo ""
	echo "The address is unreachable"
fi
