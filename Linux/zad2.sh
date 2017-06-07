#!/bin/bash
if [ $# -eq 0 ]; then
echo "Skrypt wymaga podania dwoch argumentow"
elif [ $# -eq 2 ]; then
echo $1 
echo $2
echo $1 > $2
else
echo "Podano nieprawidlowa liczbe argumentow. Wymagane podanie dokladnie dwoch argumentow."
fi
