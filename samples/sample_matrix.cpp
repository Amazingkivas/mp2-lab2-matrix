// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------
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
    cin >> M1;
    cout << "\nПервая матрица: " << endl << M1 << endl;

    switch (select)
    {
    case ADD_MATRICES:
    {
        TDynamicMatrix<double> M2(size);
        cout << "\nЗаполнение второй матрицы: " << endl;
        cin >> M2;
        cout << "\nВторая матрица: " << endl << M2 << endl;
        cout << "\nРезультат: " << endl << M1 + M2 << endl;
        break;
    }
    case SUBTRACT_MATRICES:
    {
        TDynamicMatrix<double> M2(size);
        cout << "\nЗаполнение второй матрицы (вычитаемой): " << endl;
        cin >> M2;
        cout << "\nВторая матрица: " << endl << M2 << endl;
        cout << "\nРезультат: " << endl << M1 - M2 << endl;
        break;
    }
    case MULTIPLY_MATRICES:
    {
        TDynamicMatrix<double> M2(size);
        cout << "\nЗаполнение второй матрицы: " << endl;
        cin >> M2;
        cout << "\nВторая матрица: " << endl << M2 << endl;
        cout << "\nРезультат: " << endl << M1 * M2 << endl;
        break;
    }
    case MULTIPLY_MATRIX_AND_VECTOR:
    {
        TDynamicVector<double> V(size);
        cout << "\nЗаполнение вектора: " << endl;
        cin >> V;
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
