#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

const int iA = 5;
const int jA = 8;

using namespace std;
inline int losuj ( int a, int b );
void przydziel ( int tab[ ][ jA ] , int iWymiar, int pPrzedzial, int kPrzedzial );
void wypisz ( int tab[ ][ jA ], int iWymiar );
void wypiszJednowymiarowa ( int tab[ ], int wymiar );
void sumujWiersz ( int tab[ ][ jA ], int iWymiar, int tab2[ ] );
int * dominanta ( int tab[ ], int ntab, int &mod );
void swap ( int tab[ ][ jA ], int iWymiar, int kZam1, int kZam2 );
//////////////////////////////////////////////////////////////////////////////////
int main ( void )
{
    int p, k, kolumna1, kolumna2;
    int A[ iA ][ jA ];
    int B[ iA ] = { 0 };
    int *wsk_dom;
    int ndom = 0;

    srand ( time ( 0 ) );

    cout << "Wprowadz p:"; cin >> p;
    cout << "Wprowadz k: "; cin >> k;

    przydziel ( A, iA, p, k );
    wypisz( A, iA );
    sumujWiersz ( A, iA, B );
    wypiszJednowymiarowa( B, iA );

    cout << endl;

    wsk_dom = dominanta ( B, iA, ndom );
    if( ndom > 1 ) {
        for ( int i = 0; i < ndom; i++ ) {
            cout << "Dominanta " << i + 1 << ": " << wsk_dom[ i ] << endl;
        }
    }
    else
    {
        cout << "Dominanta: " << *wsk_dom << endl;
    }

    cout << endl;

    cout << "Ktore kolumny zamienic? "
         << endl
         << "kolumna 1: "; cin >> kolumna1;
    cout << "kolumna 2: "; cin >> kolumna2;

    swap ( A, iA, kolumna1, kolumna2 );
    cout << endl;
    cout << "(Liczymy od zera) Zamieniono kolumny " << kolumna1 << " i " << kolumna2 << endl;
    wypisz( A, iA );

    return 0;
}

inline int losuj ( int a, int b )
{
    return rand () % ( b - a + 1 ) + a;
}

void przydziel ( int tab[ ][ jA ] , int iWymiar, int pPrzedzial, int kPrzedzial )
{
    for ( int i = 0; i < iWymiar; i++ )
        for ( int j = 0; j < jA; j++ )
            tab[ i ][ j ] = losuj( pPrzedzial, kPrzedzial );
}

void wypisz ( int tab[ ][ jA ], int iWymiar )
{
    for ( int i = 0; i < iWymiar; i++ ) {
        for ( int j = 0; j < jA; j++ ) {
            cout << setw ( 4 ) << tab [ i ][ j ];
        }
        cout << endl;
    }

    cout << endl;
}

void wypiszJednowymiarowa ( int tab[ ], int wymiar )
{
    for ( int i = 0; i < wymiar; i++ )
    {
        cout << "Suma wiersza " << i << ": " << tab[i] << endl;
    }
}

void sumujWiersz ( int tab[ ][ jA ], int iWymiar, int tab2[ ] )
{
    for ( int i = 0; i < iWymiar; i++ ) {
        for ( int j = 0; j < jA; j++ ) {
            tab2[ i ] += tab[ i ][ j ];
        }
    }
}

int * dominanta ( int tab[ ], int ntab, int &mod )
{
    static int wynik[iA]; //tablica wynikow
    int maxVal = 0;


    for ( int i = 0; i < ntab; i++ ) {
        if ( tab[ i ] > maxVal) {
            maxVal = tab [ i ];
        }
    }

    for ( int i = 0; i < ntab; i++ ) {
        if ( tab[ i ] == maxVal ) {
            wynik[ mod ] = i;
            mod++;                      // w razie wiekszej liczby wystapien
        }                               // dodaj kolejny element
    }

    return wynik;
}

void swap ( int tab[ ][ jA ], int iWymiar, int kZam1, int kZam2 )
{
    int temp[ iA ] = {0};
    for ( int i = 0; i < iWymiar; i++ ) {
        temp[ i ] = tab[ i ][ kZam1 ];
    }

    for ( int i = 0; i < iWymiar; i++ ) {
        tab[ i ][ kZam1 ] = tab[ i ][ kZam2 ];
    }

    for ( int i = 0; i < iWymiar; i++ ) {
        tab[ i ][ kZam2 ] = temp[ i ];
    }
}
