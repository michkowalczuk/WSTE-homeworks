#!/bin/bash
save_arg()
{
if [ -f $2 ]; then
rm $2 -f
fi

txt=$1
for (( i=0; i<${#txt}; i++ )); do
echo "${txt:$i:1}" >> $2
done
}

check_args()
{
if [ $# -eq 0 ]; then
echo "Skrypt wymaga podania dwoch argumentow."
elif [ $# -eq 2 ]; then
echo $1 
echo $2
save_arg $@
else
echo "Podano nieprawidlowa liczbe argumentow. Wymagane podanie dokladnie dwoch argumentow."
fi
}

check_args $@


