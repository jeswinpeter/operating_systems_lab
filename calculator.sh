echo ---- Calculator ----
echo Addition : 1
echo Subtraction : 2
echo Multiplication : 3
echo Division : 4
echo --------------------
echo Enter 2 Numbers:
read A
read B
echo Enter option number : 
read option
case $option in 
1)rs=$(($A + $B))
	echo sum is $rs;;
2)rs=$(($A - $B))
	echo difference is $rs;;
3)rs=$(($A * $B))
	echo product is $rs;;
4)rs=$(($A / $B))
	echo Result = $rs;;
esac  
