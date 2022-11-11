// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <ctime>
#include "tmatrix.h"
//---------------------------------------------------------------------------
void fill(TDynamicMatrix<double>& matrix, int matrix_size)
{
    int select_fill, i, j;
    cout << "\nСпособ заполнения:\n" << endl;
    cout << "1 - ручное заполнение" << endl;
    cout << "2 - рандомное заполнение" << endl;
    cout << "\nНомер: ";
    cin >> select_fill;

    if (select_fill == 1)  // Manual filling
    {
        cin >> matrix;
    }
    else if (select_fill == 2)  // Random filling
    {
        for (i = 0; i < matrix_size; i++)
        {
            for (j = 0; j < matrix_size; j++)
            {
                matrix[i][j] = rand() % 100;
            }
        }
    }
    else
    {
        cout << "ERROR: invalid number of filling method" << endl;
        exit(1);
    }
}

void main()
{
    int  size, select;
    enum operations {
        ADD_MATRICES = 1,
        SUBTRACT_MATRICES,
        MULTIPLY_MATRICES,
        MULTIPLY_MATRIX_AND_VECTOR,
        MULTIPLY_MATRIX_AND_SCALAR
    };
    srand(static_cast<unsigned>(time(0)));

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование класс работы с матрицами" << endl;
    
    cout << "\nРазмер матрицы: ";
    cin >> size;

    cout << "Выберите операцию:\n" << endl;
    cout << "1 - Сложение матриц" << endl;
    cout << "2 - Разность матриц" << endl;
    cout << "3 - Умножение матриц" << endl;
    cout << "4 - Умножение матрицы на вектор" << endl;
    cout << "5 - Умножение матрицы на скаляр" << endl;
    cout << "\nНомер: ";
    cin >> select;

    if (select > 5 || select < 1)
    {
        cout << "\nERROR: Invalid operation number" << endl;
        exit(1);
    }

    TDynamicMatrix<double> M1(size);
    cout << "\nЗаполнение первой матрицы: " << endl;
    fill(M1, size);
    cout << "\nПервая матрица: " << endl << M1 << endl;

    switch (select)
    {
    case ADD_MATRICES:
    {
        TDynamicMatrix<double> M2(size);
        cout << "\nЗаполнение второй матрицы: " << endl;
        fill(M2, size);
        cout << "\nВторая матрица: " << endl << M2 << endl;
        cout << "\nРезультат: " << endl << M1 + M2 << endl;
        break;
    }
    case SUBTRACT_MATRICES:
    {
        TDynamicMatrix<double> M2(size);
        cout << "\nЗаполнение второй матрицы (вычитаемой): " << endl;
        fill(M2, size);
        cout << "\nВторая матрица: " << endl << M2 << endl;
        cout << "\nРезультат: " << endl << M1 - M2 << endl;
        break;
    }
    case MULTIPLY_MATRICES:
    {
        TDynamicMatrix<double> M2(size);
        cout << "\nЗаполнение второй матрицы: " << endl;
        fill(M2, size);
        cout << "\nВторая матрица: " << endl << M2 << endl;
        cout << "\nРезультат: " << endl << M1 * M2 << endl;
        break;
    }
    case MULTIPLY_MATRIX_AND_VECTOR:
    {
        int select_method, ind;
        TDynamicVector<double> V(size);

        cout << "\nЗаполнение вектора: " << endl;
        cout << "\nСпособ заполнения:\n" << endl;
        cout << "1 - ручное заполнение" << endl;
        cout << "2 - рандомное заполнение" << endl;
        cout << "\nНомер: ";
        cin >> select_method;

        if (select_method == 1)  // Manual filling
        {
            cin >> V;
        }
        else if (select_method == 2)  // Random filling
        {
            for (ind = 0; ind < size; ind++)
            {
                V[ind] = rand() % 100;
            }
        }
        else
        {
            cout << "ERROR: invalid number of filling method" << endl;
            exit(1);
        }
        cout << "Вектор: " << V << endl;
        cout << "\nРезультат: " << endl << M1 * V << endl;
        break;
    }
    case MULTIPLY_MATRIX_AND_SCALAR:
    {
        double SCAL;
        cout << "\nЗначение скаляра: ";
        cin >> SCAL;
        cout << "\nРезультат: " << endl << M1 * SCAL << endl;
        break;
    }
    default:
    {
        cout << "\nUNEXPECTED ERROR" << endl;
        exit(1);
        break;
    }
    }
}
//---------------------------------------------------------------------------
