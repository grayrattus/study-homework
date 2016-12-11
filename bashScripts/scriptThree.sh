#!/bin/bash

myArray=("$@")

readArguments()
{
  for (( i = 0; i < 1; i++ )); do
    if [[ ${#myArray[*]} -le $i ]]; then
      tempI=$i;
      echo "Nie podales argumentu $tempI. Wprowadz go teraz"
      read myArray[$tempI];
    fi
  done
}
checkVariables()
{
  for (( i = 0; i < 1; i++ )); do
    case ${myArray[$i]} in
      ''|*[!0-9]*) echo "Argumenty nie spełniają założeń zadania" ;exit -1;;
    esac
  done
}

fib2() {
    local f
    ((f=$1+$2))
    printf '%i %i\n' "$f" "$1"
}

fib()
{
    local i j
    j=$1
    shift
    for((i=1; i<j; ++i)); do
        set -- $(fib2 ${1-1} ${2-0})
    done
    printf 'Ciąg wynosi:%s\n' "${1-$i}"
}

readArguments
checkVariables
fib "${myArray[0]}"
