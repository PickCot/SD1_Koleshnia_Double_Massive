﻿#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** BuildMassive(int n, int m);
void initialize(int** A, int n, int m); 
void sum(int** A, int n, int m);
int main()
{

    int n(0), m(0);
    cout << " Введите кол-во строк в массиве" << endl;
    cin >> n;
    cout << " \nВведите кол-во столбцов в массиве" << endl;
    cin >> m;
    cout << endl;
    int** A;

    A = BuildMassive(n, m);
    initialize(A, n, m);
    sum(A, n, m);


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
void sum(int** A, int n, int m)
{
    int result(0);
    for (int i = 0; i < n; i++)
    {
        if(i % 2 == 1)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[i][j] < 0)
                {
                    for (int count = 0; count < m; count++)
                    {
                        result += A[i][count];
                    }
                    cout << "\n Сумма элементов на " << i + 1 << " строке равна " << result << endl;
                    j = m;
                    result = 0;
                }
            }
        }
    }
}