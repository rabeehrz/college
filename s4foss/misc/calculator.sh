i="y"
echo "enter the first number"
read n1
echo "enter the second number"
read n2
while [ $i == "y" ]
do
echo "1 - addition"
echo "2 - subtraction"
echo "3 - multiplication"
echo "4 - division"
echo "5 - modulo division"
read c
sum=0
case $c in
1) sum=`expr $n1 + $n2`
;;
2) sum=`expr $n1 - $n2`
;;
3) sum=`expr $n1 \* $n2`
;;
4) sum=`expr $n1 / $n2`
;;
5) sum=`expr $n1 % $n2`
;;
esac
echo $sum
echo "Continue?"
read i
if [ $i != "y"]
then
exit
fi
done
