#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

inline int losuj ( int a, int b );
void hist ( int *tab, int N, int *hist );
float srednia ( int *tab, int N );
void sortowanie ( int *tab, int nhist, int *hist );
float mediana ( int *tab, int N );
int * dominanta ( int *hist, int nhist, int &mod );
void rysowanie ( int *hist, int N );
void separator ( );

/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    const int TAB_MAX = 100;
    const int TAB_OCENY = 6;
    int ndom = 0;
    int *wsk_med;
    int *wsk_dom;
    int student[ TAB_MAX ]; for ( int i = 0; i < TAB_MAX; i++ ) student[ i ] = 0;
    int ocena[ TAB_OCENY ]; for ( int i = 0; i < TAB_OCENY; i++ ) ocena[ i ] = 0;

    srand ( time ( NULL ) );

    cout << "---------------------- Marcin Pajkowski ---------------------" << endl;
    //Zadanie 1
    for ( int i = 0; i < TAB_MAX; i++ ) {
        student[ i ] = losuj ( 0, TAB_OCENY - 1 );
    }

    for ( int i = 0; i < TAB_MAX; ) {
        for ( int j = 0; j < 4; j++ ) {
            cout << "Student ";
            if ( i < 10 ) cout << "0";
            cout << i << ": " << student[ i ] << "\t";
            i++;
        }
        cout << endl;
    }

    separator ( );
    //zadanie 2
    hist( student, TAB_MAX, ocena );

    for ( int i = 0; i < TAB_OCENY; i++ ) {
        cout << "Ocena " << i << ": " << ocena[ i ] << endl;
    }

    separator ( );
    //zadanie 3
    cout << "Srednia: " << srednia ( student, TAB_MAX ) << endl;

    separator ( );

    //zadanie 4

    wsk_med = new int[ TAB_MAX ];           // Nie chcemy nadpisywac ocen

    for ( int i = 0; i < TAB_MAX; i++ ) {
        wsk_med[ i ] = student [ i ];
    }

    sortowanie ( wsk_med, TAB_OCENY, ocena );

    cout << "Mediana: " << mediana ( wsk_med, TAB_MAX ) << endl;

    delete[] wsk_med;
    separator ( );

    //zadanie 5
    wsk_dom = dominanta ( ocena, TAB_OCENY, ndom );

    if( ndom > 1 ) {
        for ( int i = 0; i < ndom; i++ ) {
            cout << "Dominanta " << i + 1 << ": " << wsk_dom[ i ] << endl;
        }
    }
    else
    {
        cout << "Dominanta: " << *wsk_dom << endl;
    }

    separator ( );

    //zadanie 6
    rysowanie ( ocena, TAB_OCENY );

    return 0;
}

inline int losuj ( int a, int b )
{
    return ( rand () % ( b - a + 1) + a );
}

void hist ( int *tab, int N, int *hist )
{
    for ( int i = 0; i < N; i++ ) {
        hist[ tab[ i ] ]++;
    }
}

float srednia ( int *tab, int N )
{
    float wynik = 0;

    for ( int i = 0; i < N; i++ ) {
        wynik += tab[ i ];
    }
    wynik /= N;

    return wynik;
}

float mediana ( int *tab, int N )
{
    float mediana = 0;

    if ( ( N % 2 ) == 0 ) {
        mediana = ( ( tab[ N / 2 ] + tab[ ( N - 1) / 2 ] ) / 2 );
    }
    else {
        mediana = ( tab[ N / 2 ] );
    }

    return mediana;
}


void rysowanie ( int *hist, int nhist )
{
    for ( int i = 0; i < nhist; i++ ) {
        cout << "Ocena " << i << ": ";
        for ( int j = 0; j < hist[i]; j++ ) {
            cout << "#";
        }
        cout << endl;
    }
}

void separator ( )
{
    cout << "-------------------------------------------------------------" << endl;
}

int * dominanta ( int *hist, int nhist, int &mod )
{
    static int wynik[6]; //tablica wynikow
    int maxVal = 0;


    for ( int i = 0; i < nhist; i++ ) {
        if ( hist[ i ] > maxVal) {
            maxVal = hist [ i ];
        }
    }

    for ( int i = 0; i < nhist; i++ ) {
        if ( hist[ i ] == maxVal ) {
            wynik[ mod ] = i;
            mod++;                      // w razie wiekszej liczby wystapien
        }                               // dodaj kolejny element
    }

    return wynik;
}

void sortowanie ( int *tab, int nhist, int *hist )
{
    int j = 0;
    for ( int i = 0; i < nhist; i++ ) {
        for ( int k = 0; k < hist[ i ]; k++ ) {
            tab[ j ] = i; j++;
        }
    }
}