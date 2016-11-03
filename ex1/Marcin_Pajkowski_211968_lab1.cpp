/* Zadania z przedmiotu Podstawy programowania
 * Marcin Pajkowski, nr albumu 211968
 */

#include <iostream>
#include <math.h>

using namespace std;

void zadanie1()
{
    float a,h,x;
    int n;

    auto funkcja = [](float arg) -> float
    {
        return ((1.0 / 3) * sin(M_PI * arg) + (1.0 / 7) + log10(arg));
    };

    cout << "====== ZADANIE 1 ======" << endl << endl;
    do
    {
        cout << "Wprowadz wartosc n (wartosc typu calkowitego wieksza od zera): "; //int
        cin >> n; //int
        if(n<=0)
        {
            cout << "BLAD!!! ";
        }
    }
    while (n<=0);

    cout << "Podaj wartosc dla h (wartosc typu rzeczywistego): "; //float
    cin >> h; //float

    cout << "Wprowadz wartosc dla a (wartosc typu rzeczywistego): "; //float
    cin >> a; //float

    for(int i = 0; i<=n; i++)
    {
        x = a + i * h;

        cout << i << ". x = " << x << ", y = " << funkcja(x) << endl;
    }

    cout << "Zadanie wykonal Marcin Pajkowski" << endl << endl;
}

void zadanie2()
{

    float a,b,c;
    char wybor;

    auto pierwiastki = [](float a, float b, float c) -> void //algorytm obliczania pierwiastkow trojmianu kwadratowego
    {
        float delta,x1,x2;

        cout << "DANE: a = " << a << ", b = " << b << ", c = " << c << endl;
        if(a==0)
        {
            if(b==0 && c==0)
            {
                cout << "Nieskonczenie wiele rozwiazan" << endl << endl;
                return;
            }
            else if(b==0 && c != 0)
            {
                cout << "Rownanie sprzeczne, nie posiada rozwiazan" << endl << endl;
                return;
            }
            else
            {
                x1 = (-c) / b;
                cout << "Nie jest to rownanie kwadratowe. Rownanie to posiada jedno rozwiazanie: " << x1 << endl << endl;
                return;
            }
        }

        delta = pow(b, 2) - 4 * a * c;

        if(delta < 0)
        {
            cout << "Brak rozwiazan w zbiorze liczb rzeczywistych" << endl << endl;
            return;
        }
        else if(delta == 0)
        {
            x1 = (-b / (2 * a));
            cout << "Jedno rozwiazanie w zbiorze liczb rzeczywistych: x = " << x1 << endl << endl;
            return;
        }
        else
        {
            x1 = (-b - sqrt(delta))/(2 * a);
            x2 = (-b + sqrt(delta))/(2 * a);
            cout << "Dwa rozwiazania w zbiorze liczb rzeczywistych: x1 = " << x1 << ", x2 = " << x2 << endl << endl;
        }
    };


    cout <<"====== ZADANIE 2 ======" << endl;
    cout <<"Rownania kwadratowe (zbior liczb rzeczywistych)" << endl;

wybor_zad2:
    cout << "A) Dane uzytkownika" << endl;
    cout << "B) Przyklady" << endl;
    cout << "Wybor (A/B)?: ";
    cin >> wybor;

    switch(wybor)
    {
        case 'A':
        case 'a':
            cout << "Wprowadz a: "; cin >> a;
            cout << "Wprowadz b: "; cin >> b;
            cout << "Wprowadz c: "; cin >> c;
            cout << "Prezentacja programu dla danych wprowadzonych przez uzytkownika: " << endl;
            pierwiastki(a,b,c);
            break;
        case 'B':
        case 'b':
            cout << "Program potrafi rozwiazac rownanie kwadratowe. Dowod: " << endl;
            pierwiastki(3,6,3);
            pierwiastki(2.5,6.6,1.5);
            pierwiastki(0.5,0.1,1.5);
            pierwiastki(0,2.5,7.5);
            pierwiastki(0,0,5.5);
            pierwiastki(0,0,0);
            break;
        default:
            cout << "Zly wybor" << endl;
            goto wybor_zad2;
    }

    cout << "Zadanie wykonal Marcin Pajkowski " << endl << endl;
}

void zadanie3()
{
    char wybor;
    float R,H,V; //R - promien kuli/podstawy stozka, H - wysokosc stozka, V - objetosc kuli/stozka

    cout << "====== ZADANIE 3 ======" << endl << endl;

wybor_zad3:
    cout << "K - V kuli" << endl;
    cout << "S - V stozka" << endl;
    cout << "Wybor? (K/S)?: ";

    cin >> wybor;
    switch (wybor)
    {
        case 'k':
        case 'K':
            cout << "Wprowadz promien: ";
            cin >> R;
            cout << "Objetosc kuli wynosi " << (4.0 / 3) * M_PI * pow(R, 3) << endl;
            break;
        case 's':
        case 'S':
            cout << "Wprowadz promien podstawy: ";
            cin >> R;
            cout << "Wprowadz wysokosc stozka: ";
            cin >> H;
            cout << "Objetosc stozka wynosi " << (1.0 / 3) * M_PI * pow(R, 2) * H << endl;
            break;
        default:
            cout << "Nie dokonano prawidlowego wyboru." << endl << endl;
            goto wybor_zad3;
        }
    cout << "Zadanie wykonal Marcin Pajkowski" << endl << endl;
}

void zadanie4()
{
    int K;
    float SUMA=0.0;

    cout << "====== ZADANIE 4 ======" << endl << endl;
    cout << "Wprowadz wartosc K: ";
    do
    {
        cin >> K;
    }
    while(K == 0);


    for(int j=1; j<=K; j++)
    {
        SUMA += (pow(j,2) + 1)/(2 * j);
    }

    cout << "SUMA : " << SUMA << endl;
    cout << "Zadanie wykonal Marcin Pajkowski" << endl << endl;
}

int main()
{
    int nr_zadania;
    /* MENU GLOWNE */
    cout << "Zadania z informatyki" << endl;
    cout << "1. Obliczanie wartosci funkcji" << endl;
    cout << "2. Rownania kwadratowe" << endl;
    cout << "3. Objetosc kuli/stozka" << endl;
    cout << "4. Suma" << endl;
    cout << "5. Wyjscie z programu" << endl;
    cout << "Wybor: ";

    cin >> nr_zadania;

    switch(nr_zadania)
    {
        case 1:
            zadanie1();
            main();
            break;
        case 2:
            zadanie2();
            main();
            break;
        case 3:
            zadanie3();
            main();
            break;
        case 4:
            zadanie4();
            main();
            break;
        case 5:
            return 0; //Program wykonal sie i poprawnie zakonczyl swoje dzialanie.
        default:
            main();
            break;
    }

    return 0;
}