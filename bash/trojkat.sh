#!/bin/bash
# trojkat.sh

declare -i bok1=$1
declare -i bok2=$2
declare -i bok3=$3
declare -i warunek

function jestCalkowita {
if [ $(($1+0)) != 0 ]
	then 
		return 0
	else 
		return 1
fi
}

ustawWarunek() {
if jestCalkowita "$bok1" && jestCalkowita "$bok2" && jestCalkowita "$bok3" ; then
		warunek=2
	else
		warunek=1
fi
}

######################################

if [ "$#" != 3 ]; then
	echo -n "Wprowadz a: "
	read bok1
	echo -n "Wprowadz b: "
	read bok2
	echo -n "Wprowadz c: "
	read bok3
fi

ustawWarunek	

case "$warunek" in
1) echo "Podane nieprawidłowe dane. Proszę wprowadzić jako parametry liczby całkowite." ;;
2) if( "$bok1" + "$bok2" > "$bok3" && "$bok3" + "$bok2" > "$bok1" && "$bok1" + "$bok3" > "$bok2" )
	then 
		echo "Z podanych odcinków można utworzyć trójkąt."
	else
		echo "Z podanych długości odcinków nie jest możliwe utworzenie trójkąta."
	fi
esac
