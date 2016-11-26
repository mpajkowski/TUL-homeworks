#!/bin/bash
# fibo.sh - Marcin Pajkowski 211968

########################################################
declare -i nextFibo=1
########################################################

_help_()
{
    echo "Skrypt oblicza kolejne wartości ciągu Fibonacciego. Liczbę"
    echo "wyrazów ciągu należy wprowadzić w parametrze wejściowym. Przykład"
    echo -e "\tfibo.sh 10"
    echo "Jeśli tego nie uczynimy w momencie uruchamiania skryptu, zostaniemy"
    echo "poproszeni o to podczas jego działania." 
}

if [ $# != 0 ] ; then
    if [ "$1" != "--help" ] ; then
        istream="$1"
    else
        _help_
        echo
    fi
else
    echo -n "Wprowadz N: "
    read istream
fi

declare -i N="$istream"

fibo()
{
    tab[0]=0
    tab[1]=1

    if [ $N -eq 0 ] ; then
        echo "Podaj wartość większą od zera!"
        exit
    fi

    if [ $N -lt 2 ] ; then
        unset tab[1]
    else
        for((i=2; $i < $N; i++ )) ; do
            nextFibo=$nextFibo+${tab[i-2]}
            tab[i]=$nextFibo
        done
    fi
    return ${tab[N-1]}
}

fibo
echo "N: $N, n-ty wyraz ciągu - $?"
