#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int silnia(int n)
{
    int s;
    s = 1;

    for(int i=1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}

inline int losuj(int a, int b)
{
    return rand()%(b-a+1) + a;
}

double symbolNewtona(int n, int k)
{
    return silnia(n)/((silnia(k))*silnia(n-k));
}

double suma(int arg)
{
    double wynik = 0;

    for (int i = 1; i <= arg; i++)
    {
        wynik += ((2.0 * i) + 3.0)/((3.0 * i) + 2.0);
    }
    return wynik;
}

void zmien1(int w)
{
    int losowa=losuj(3,16);

    cout << "Jestesmy wewnatrz funkcji zmien1." << endl;
    cout << "Wartosc parametru: " << w << ". Parametr zostal przekazany przez wartosc" << endl;
    cout << "Wartosc wylosowana: " << losowa << endl;
    w += losowa;
    cout << "Parametr zsumowany z wartoscia losowa: " << w << endl;
}

void zmien2(int &w)
{
    int losowa=losuj(3,16);

    cout << "Jestesmy wewnatrz funkcji zmien2." << endl;
    cout << "Wartosc parametru: " << w << ". Parametr zostal przekazany przez referencje" << endl;
    cout << "Wartosc wylosowana: " << losowa << endl;
    w += losowa;
    cout << "Parametr zsumowany z wartoscia losowa: " << w << endl;
}

double funkcja(double arg)
{
    if(arg >= -3.3 && arg <= 15)
        return ((arg + 1) / 2);
    else if(arg > 15)
        return (double) (sin(arg));
    else
        return ((2.2 * arg) - 3);
}

inline double trojkat_pole(double a, double b, double c)
{
    double pole;
    double pol_obw;

    pol_obw = (a + b + c) / 2.0;
    pole = (double) sqrt(pol_obw * (pol_obw - a) * (pol_obw - b) * (pol_obw - c)); //wzor Herona

    return pole;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zadanie1()
{
    int N;
    cout << "Wprowadz n: "; cin >> N;
    cout << N <<"! = " << silnia(N) << endl;
    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

void zadanie2()
{
    int N,K;
    cout << "Wprowadz n: "; cin >> N;
    cout << "Wprowadz k: "; cin >> K;
    cout << "Wynik operacji dla n = " << N << " i k = " << K << ": " << symbolNewtona(N,K) << endl;
    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

void zadanie3()
{
    int k;

    cout << "Wprowadz K: "; cin >> k;
    cout << "SUMA: " << suma(k) << endl;
    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

void zadanie4()
{
    int parametr;

    cout << "Wprowadz parametr: "; cin >> parametr;
    zmien1(parametr);
    cout << "Wyszlismy z funkcji zmien1" << endl;
    cout << "Wartosc parametru: " << parametr << ". Wartosc parametru nie ulegla zmianie" << endl;
    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

void zadanie5()
{
    int parametr;

    cout << "Wprowadz parametr: "; cin >> parametr;
    zmien2(parametr);
    cout << "Wyszlismy z funkcji zmien2" << endl;
    cout << "Wartosc parametru: " << parametr << ". Wartosc parametru ulegla zmianie" << endl;
    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

void zadanie6()
{
    float a,h,x,M;
    cout << "Wprowadz a (typ rzeczywisty): "; cin >> a;
    cout << "Wprowadz h (typ rzeczywisty): "; cin >> h;
    cout << "Wprowadz M (typ rzeczywisty): "; cin >> M;

    for(float i=0.1; i<M; i += 0.1)
    {
        x = a + i * h;                      //generowany nowy x

        cout << "i = " << i << ", x = " << x << ", f(x) = " << funkcja(x) << endl;
    }

    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

void zadanie7()
{
    double bok1,bok2,bok3;

    cout << "Podaj dlugosc pierwszego boku: "; cin >> bok1;
    cout << "Podaj dlugosc drugiego boku: "; cin >> bok2;
    cout << "Podaj dlugosc trzeciego boku: "; cin >> bok3;

    if(bok1+bok2>bok3 && bok1+bok3>bok2 && bok2+bok3>bok1)
    {
        cout << "Pole trojkata majacego boki dlugosci " << bok1 << "j, " << bok2 << "j, " << bok3
             << "j wynosi " << trojkat_pole(bok1,bok2,bok3) << " jednostek kwadratowych" << endl;
    }
    else
    {
        cout << "Nie mozna zbudowac trojkata z podanych bokow." << endl;
    }

    cout << "Zadanie wykonal Marcin Pajkowski. Nr albumu: 211968." << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    int wybor;

    srand(time(0)); // do zadan z liczbami losowymi

    cout << "Zadania z programowania" << endl;
    do {
        cout << "=============================================" << endl;
        cout << "1. Silnia" << endl;
        cout << "2. Znak Newtona" << endl;
        cout << "3. Suma" << endl;
        cout << "4. Funkcja - przekazywanie przez wartosc" << endl;
        cout << "5. Funkcja - przekazywanie przez referencje" << endl;
        cout << "6. Funkcja matematyczna" << endl;
        cout << "7. Pole trojkata" << endl;
        cout << "8. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;
    } while (wybor < 1 || wybor > 8);

    switch (wybor) {
        case 1:
            cout << endl;
            zadanie1();
            cout << endl;
            break;
        case 2:
            cout << endl;
            zadanie2();
            cout << endl;
            break;
        case 3:
            cout << endl;
            zadanie3();
            cout << endl;
            break;
        case 4:
            cout << endl;
            zadanie4();
            cout << endl;
            break;
        case 5:
            cout << endl;
            zadanie5();
            cout << endl;
            break;
        case 6:
            cout << endl;
            zadanie6();
            cout << endl;
            break;
        case 7:
            cout << endl;
            zadanie7();
            cout << endl;
            break;
        case 8:
            cout << "Dziekuje za skorzystanie z programu." << endl;
            return 0;
        default:
            cout << "Nie wybrano zadnej z opcji" << endl << endl;
            break;
    }

    main(); //po wykonaniu zadan wroc do poczatku
}