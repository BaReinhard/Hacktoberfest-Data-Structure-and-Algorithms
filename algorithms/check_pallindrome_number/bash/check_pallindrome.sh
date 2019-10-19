echo "Enter a string to be entered: "
read str

len=`echo $str | wc -c`
len=`expr $len - 1`
rev=""

while [ $len -gt 1 ]
do
        rev1=`expr $str | cut -c $len`
        rev=$rev$rev1
        len=`expr $len - 1`
done


if [ $str = $rev ]
then
echo "String is pallindrome"
else
echo "String is not pallindrome"
fi

