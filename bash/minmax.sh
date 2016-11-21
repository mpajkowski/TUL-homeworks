#!/bin/bash
# minmax.sh - Marcin Pajkowski 211968

########################################################
declare -i SUMA=""
maxVal=0
minVal=0
INPUT_FILE=""
########################################################

if [ "$#" == 1 ]; then
   INPUT_FILE="$1"
fi

function minMax {
    if [ "$INPUT_FILE" == "" ]; then
        echo -n "Podaj nazwę pliku: "
        read INPUT_FILE
    fi
    
    LEN=`cat "$INPUT_FILE" | awk -F';' '{print NF; exit}'`

    for (( i=1; $i <= LEN; i++ )) ; do
	    tab[i-1]=`cat "$INPUT_FILE" | awk -v iterator="$i" -F';' '{print $iterator}'`
    done
    
    
    for (( j=0; $j < LEN; j++ )) ; do
	    if (( "${tab[j]}" > "$maxVal" )); then
		    maxVal="${tab[j]}"
	    fi
    done

    minVal=$maxVal
    for ((k=0; $k < LEN; k++)) ; do
        if (( "${tab[k]}" < "$minVal" )); then
		    minVal="${tab[k]}"
	    fi
    done
}

function sumaPrzedzialu {
echo -n "Podaj p: "
read p
echo -n "Podaj k: "
read k

for (( i=$p; i <= $k; i++)) ; do
	SUMA=$SUMA+$i
done
echo "Wartość sumy: $SUMA"
}

PS3='Wybierz jedną z opcji: '
options=("Minimalna" "Maksymalna" "Suma" "Koniec")
select opt in "${options[@]}"
do
    case $opt in
        "Minimalna")
		echo
            minMax
            echo "Wartość minimalna to $minVal"
            ;;
        "Maksymalna")
            minMax
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
