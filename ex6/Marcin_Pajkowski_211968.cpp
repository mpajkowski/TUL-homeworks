#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 3
//////////////////////////////////////////////////////
const int NAME_ARR_SIZE = 15;
const int MARK_ARR_SIZE = 6;
//////////////////////////////////////////////////////
struct Student
{
    char nazwisko[ NAME_ARR_SIZE ] = { 0 };
    int nr_albumu;
    float ocena[ MARK_ARR_SIZE ] = { 0 };
    float srednia;
};
//////////////////////////////////////////////////////
float avg(float *tab, int N_tab);
Student addStudent();
void listStudentData(Student st);
/* void sortArr(Student *tab, int sortBy);
 *
 * sortBy == 0 - sort by name
 * sortBy == 1 - sort by avg
 *
 */
void sortArr(Student *tab, int sortBy);
//////////////////////////////////////////////////////
int main()
{
    srand(time(0));
    Student student[N];
    int state;
    fstream file;
    char name_from_input[NAME_ARR_SIZE];
    float given_avg;

    cout << "======= BAZA DANYCH STUDENTOW =======" << endl << endl;

    while (true)
    {
        cout << "1. Wprowadz studentow do bazy" << endl;
        cout << "2. Wypisz baze studentow" << endl;
        cout << "3. Sortuj wedlug nazwisk" << endl;
        cout << "4. Sortuj wedlug sredniej" << endl;
        cout << "5. Wypisz informacje o studencie X" << endl;
        cout << "6. Wypisz informacje o studentach Y ze srednia wyzsza niz Z" << endl;
        cout << "7. Zakoncz" << endl;
        cout << "Wybor: ";
        cin >> state;
        cout << endl;

        switch (state)
        {
            case 1:
                for (int i = 0; i < N; i++)
                {
                    student[ i ] = addStudent();
                }
                break;
            case 2:
                for (int i = 0; i < N; i++)
                {
                    listStudentData( student[ i ] );
                }
                break;
            case 3:
                sortArr(student, 0);
                break;
            case 4:
                sortArr(student, 1);
                file.open("srednia.txt", ios_base::out | ios_base::in);
                for (int i = 0; i < N; i++)
                {
                    file << student[ i ].nazwisko << endl;
                    file << student[ i ].nr_albumu << endl;
                    for (int j = 0; j < MARK_ARR_SIZE; j++)
                    {
                        file << student[ i ].ocena[ j ] << " ";
                    }
                    file << endl;
                    file << avg(student[ i ].ocena, MARK_ARR_SIZE) << endl;
                    file << endl;
                }
                file.close();
                cout << "Zapisano do pliku" << endl;
                break;
            case 5:
                cout << "Podaj nazwisko studenta: "; cin >> name_from_input;
                for (int i = 0; i < N; i++)
                {
                    if ( strcmp(name_from_input, student[ i ].nazwisko) == 0)
                    {
                        listStudentData(student[ i ]);
                    }
                }
                break;
            case 6:
                cout << "Podaj srednia: "; cin >> given_avg;
                for (int i = 0; i < N; i++)
                {
                    if (student[ i ].srednia > given_avg)
                    {
                        listStudentData(student[ i ]);
                    }
                }
                break;
            case 7:
                cout << "Dziekuje za wybor mojego oprogramowania." << endl;
                return 0;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
float avg(float *tab, int N_tab)
{
    float result = 0;

    for (int i = 0; i < N_tab; i++)
    {
        result += tab[ i ];
    }
    result /= N_tab;

    return result;
}

Student addStudent()
{
    Student st;
    float marks[] = { 3, 3.5, 4, 4.5, 5 }; //wektor ocen
    cout << "Podaj nazwisko: "; cin >> st.nazwisko;
    st.nr_albumu = (rand() % ( 213000 - 210000 + 1 ) + 210000);
    for (int i = 0; i < NAME_ARR_SIZE; i++)
    {
        st.ocena[ i ] = marks [ rand() % 5 ];
    }
    st.srednia = avg(st.ocena, MARK_ARR_SIZE);

    return st;
}

void listStudentData(Student st)
{
    cout << st.nazwisko << endl;
    cout << st.nr_albumu << endl;
    for (int i = 0; i < MARK_ARR_SIZE; i++)
    {
        cout << st.ocena[ i ] << " ";
    }
    cout << endl;
    cout << avg(st.ocena, MARK_ARR_SIZE) << endl;
    cout << endl;
}

void sortArr(Student *tab, int sortBy)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            switch (sortBy)
            {
                case 0:
                    if (strcmp(tab[ j ].nazwisko, tab[ j + 1 ].nazwisko) > 0)
                    {
                        swap(tab[ j ], tab[ j + 1 ]);
                    }
                    break;
                case 1:
                    if (tab[ j ].srednia > tab[ j + 1 ].srednia)
                    {
                        swap( tab[ j ], tab[ j + 1 ]);
                    }
                    break;
            }
        }
    }
}