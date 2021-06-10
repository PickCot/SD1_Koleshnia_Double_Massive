#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
int** BuildMassive(int n, int m);
void initialize(int** A, int n, int m);
int main()
{
    int n(0), m(0);
    cout << "Введіть кількість рядків в матриці" << endl;
    cin >> n;
    cout << " \nВведіть кількість стобчиків в матриці" << endl;
    cin >> m;
    cout << endl;
    int** A;

    A = BuildMassive(n, m);
    initialize(A, n, m);

    for (int i = 0; i < n; i++)
    {
    delete[] A[i];
    }

    delete[] A;
    return 0;
}
int** BuildMassive(int n, int m)
{
    int** A;
    A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
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
            A[i][j] = rand() % 11 - 5;
            cout << A[i][j] << "     ";

        }
        cout << endl;
    }
}