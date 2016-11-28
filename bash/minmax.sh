#!/bin/bash
# minmax.sh - Marcin Pajkowski 211968

########################################################
declare -i SUMA=0
maxVal=0
minVal=0
VAR_COUNT=$#
FILE=""
########################################################

_help_()
{
    echo "Skrypt znajduje minimalną i maksymalną wartość n-elementowego"
    echo "wyrażenia, oblicza także sumę wartości z przedziału (p,k)."
    echo "Aby pobrać plik z wektorem do obliczeń należy wprowadzić jego ścieżkę"
    echo "w argumencie wejściowym funkcji. Przykład:"
    echo -e "\tminmax.sh wektor"
    echo "Jeśli tego nie uczynimy w momencie uruchamiania skryptu, zostaniemy"
    echo "poproszeni o to podczas jego działania." 
}
	
checkFile()
{
    if [ "$FILE" -eq "" ] ; then
        echo -n "Wprowadz nazwe pliku: "
        read FILE
    fi
}

max()
{
    LEN=`cat "$FILE" | awk -F';' '{print NF; exit}'`

    for (( i=1; $i <= LEN; i++ )) ; do
	    tab[i-1]=`cat "$FILE" | awk -v iterator="$i" -F';' '{print $iterator}'`
    done
    
    
    for (( j=0; $j < LEN; j++ )) ; do
	    if [ "${tab[j]}" -gt "$maxVal" ]; then
		    maxVal="${tab[j]}"
	    fi
    done
}

min()
{

    minVal=$maxVal
    for ((k=0; $k < LEN; k++)) ; do
        if [ "${tab[k]}" -lt "$minVal" ]; then
		    minVal="${tab[k]}"
	    fi
    done
}

sumaPrzedzialu()
{
    echo -n "Podaj p: "
    read p
    echo -n "Podaj k: "
    read k

    for (( i=$p; i <= $k; i++)) ; do
	    SUMA=$SUMA+$i
    done
    echo "Wartość sumy: $SUMA"
}
########################################################
if [ $# -gt 0 ] ; then
    if [ "$1" != "--help" ] ; then
        FILE="$1"
    else
        _help_
        echo
    fi
fi


PS3='Wybierz jedną z opcji: '
opcje=("Minimalna" "Maksymalna" "Suma" "Koniec")
select wybor in "${opcje[@]}"
do
    case $wybor in
        "Minimalna")
            checkFile
            max
	        min
            echo "Wartość minimalna to $minVal"
            ;;
        "Maksymalna")
            checkFile
            max
            echo "Wartość maksymalna to $maxVal"
            ;;
        "Suma")
            sumaPrzedzialu
            ;;
        "Koniec")
            break
            ;;
        *) echo "zła opcja";;
    esac
done
########################################################
