#!/bin/bash

myArray=("$@")

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
  for (( i = 0; i < 3; i++ )); do
    case ${myArray[$i]} in
      ''|*[!0-9]*) echo "Argumenty nie spełniają założeń zadania" ;exit -1;;
    esac
  done
}
checkTriangle()
{
  if [[ $((${myArray[0]} + ${myArray[1]})) -gt ${myArray[2]} ]]; then
    if [[ $((${myArray[0]} + ${myArray[2]})) -gt ${myArray[1]} ]]; then
      if [[ $((${myArray[1]} + ${myArray[2]})) -gt ${myArray[0]} ]]; then
        echo "Z podanych długości można utworzyć trójkąt";
      else echo "Z podanych długości nie można utworzyć trójkąta";
      fi
    else echo "Z podanych długości nie można utworzyć trójkąta";
    fi
  else echo "Z podanych długości nie można utworzyć trójkąta";
  fi
}
readArguments;
checkVariables;
checkTriangle;
