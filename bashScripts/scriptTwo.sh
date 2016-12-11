#!/bin/bash

myArray=("$@")
declare -A x_vect;
x=0;
readArguments()
{
  for (( i = 0; i < 3; i++ )); do
    if [[ ${#myArray[*]} -le $i ]]; then
      tempI=$i;
      echo "Nie podales argumentu $tempI. Wprowadz go teraz"
      read myArray[$tempI];
    fi
  done
}
checkVariables()
{
  for (( i = 1; i < 3; i++ )); do
    case ${myArray[$i]} in
      ''|*[!0-9]*) echo "Argumenty nie spełniają założeń zadania" ;exit -1;;
    esac
  done
}
readFile()
{
  IFS=';';
  text="`cat ${myArray[0]}`"
  for item in $text; do
    x_vect[$x]=$item;
    x=`expr $x + 1`;
  done
}
findVector()
{
  max=${x_vect[0]};
  min=${x_vect[0]};
  for item in ${x_vect[*]}; do
    if (( $item > $max )); then
      max=$item;
    fi
    if (( $item < $min )); then
      min=$item;
    fi
  done

  echo "Minimalny wektor $min A maksymalny $max";
}
przedzial()
{
  sum=0;
  iterator=${myArray[1]};
  echo ${myArray[2]}
  for (( ; $iterator <= ${myArray[2]}; iterator++ )); do
    sum=`expr $sum + $iterator`
  done
  echo "Suma wynosi $sum";
}
menu()
{
  OPTIONS="wektory przedzial wyjdz"
  select opt in $OPTIONS; do
    if [ "$opt" = "wektory" ]; then
      readFile;
      findVector;
    elif [ "$opt" = "przedzial" ]; then
      przedzial;
    elif [ "$opt" = "wyjdz" ]; then
      echo wyjdz
      echo done
      exit
    else
      clear
      echo "Zła opcja";
    fi
  done
}

readArguments;
checkVariables;
menu;
