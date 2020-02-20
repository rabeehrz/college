echo "Enter first no: "
read n1
echo "Enter second no: "
read n2

while true; do
	echo "1. Addition"
	echo "2. Subtracton"
	echo "3. Mulitplication"
	echo "4. Division"
	echo "5. Modulo"
	echo "Choose an option: "
	read o
	case $o in
		1)
		echo "Sum: `expr $n1 + $n2`"
		;;
		2)
		echo "Difference: `expr $n1 - $n2`"
		;;
		3)
		echo "Product: `expr $n1 \* $n2`"
		;;
		4)
		echo "Quotient `expr $n1 / $n2`"
		;;
		5)
		echo "Remainder `expr $n1 % $n2`"
		;;
		*)
		echo "Wrong Option!"
		;;
	esac
	echo ""
done

