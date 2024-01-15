#!/bin/bash

FT_NBR1=\'?"\"\'
FT_NBR2=rcrdmddd

sum_result=$(echo "ibase=5; obase=13; ${FT_NBR1} + ${FT_NBR2}" | bc | tr '0123456789ABC' 'gtaio luSnemf')

echo "La suma es:"
echo $sum_result

