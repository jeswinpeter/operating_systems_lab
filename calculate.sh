echo "--- MENU ---"
echo "1 -> Addition"
echo "2 -> Subtraction"

echo "Enter choice of operation: "
read ch
echo "Enter First num: "
read x
echo "Enter 2nd num: "
read y

case $ch in
1) sum=$(($x+$y))
echo "Sum = " $sum;;
2)diff=$(($x-$y))
echo "Diff = " $diff;;
*)echo "Invalid Choice";;
esac