#Atharva Jibhakate
#PE-08
#S1032180110

addition()
{
	summ=`echo $1 + $2 | bc`
	echo "The Addition of numbers is:$summ"
}

substraction()

{

	difference=`echo $2 - $1 | bc`
	echo "The Substraction of numbers is:$difference"
}
	
multiplication()

{

	product=`echo $2 \* $1 | bc`
	echo "The Multiplication of numbers is:$product"
}
	
division()

{

	quotient= echo "scale=2; $2 / $1 " | bc 
	echo "The division of numbers is:$quotient"
}
	
echo "Enter number 1:"
read n1
echo "Enter number 2:"
read n2

echo -e "Operations to be performed:\n1.Addition\n2.Substraction\n3.Multiplication\n4.Division  ";
echo " Enter Choice: ";
read var
case $var in 
1)addition $n1 $n2;;
2)substraction $n2 $n1;;
3)multiplication $n2 $n1;;
4)division $n2 $n1;;
esac
