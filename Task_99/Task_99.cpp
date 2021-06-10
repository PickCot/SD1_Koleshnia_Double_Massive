#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** BuildMassive(int n);
void initialize(int** A, int n);
int main()
{
    int n(0);
    cout << "Введіть кількість рядків в матриці" << endl;
    cin >> n;
    cout << endl;
    int** A;
    A = BuildMassive(n);
    initialize(A, n);


    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }

    delete[] A;
    return 0;
}
int** BuildMassive(int n)
{
    int** A;
    A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    return A;
}

void initialize(int** A, int n, int m)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = 10 + rand() % 100;
            cout << A[i][j] << "     ";

        }
        cout << endl;
    }
}
