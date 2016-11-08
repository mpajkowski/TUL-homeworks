#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

inline int losuj ( int a, int b );
void hist ( int *tab, int N, int *hist );
float srednia ( int *tab, int N );
void sortowanie ( int *tab, int lewy, int prawy );
float mediana ( int *tab, int N, int *hist );
void rysowanie ( int *hist, int N );
void separator ( );

/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    const int TAB_MAX = 100;
    const int TAB_OCENY = 6;
    int student[ TAB_MAX ]; for ( int i = 0; i < TAB_MAX; i++ ) student[ i ] = 0;
    int ocena[ TAB_OCENY ]; for ( int i = 0; i < TAB_OCENY; i++ ) ocena[ i ] = 0;

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

    hist( student, TAB_MAX, ocena );

    for ( int i = 0; i < TAB_OCENY; i++ ) {
        cout << "Ocena " << i << ": " << ocena[ i ] << endl;
    }

    separator ( );

    cout << "Srednia: " << srednia ( student, TAB_MAX ) << endl;

    separator ( );

    cout << "Mediana: " << mediana ( student , 5, ocena ) << endl;

    separator ( );

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

void sortowanie ( int *tab, int N, int *hist )
{
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < hist[ i ]; j++ ) {
            tab[ j ] = i;
        }
    }
}

float mediana ( int *tab, int N, int *hist )
{
    float mediana = 0;

    sortowanie ( tab, N, hist );

    if ( ( N % 2 ) == 0 ) {
        mediana = ( tab[ N ] + tab [ N - 1] / 2 );
    }
    else {
        mediana = ( tab [ N ] );
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