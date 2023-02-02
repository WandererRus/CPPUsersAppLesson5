// CPPUsersAppLesson5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Задание 3. Напишите функцию умножения матриц.Матрица представляет собой таблицу чисел.Произведением
//матрицы A размером M×N(M строк, N столбцов) на
//матрицу B размером N×K является матрица C размером
//N×K такая, что
//cij = ai1b1j + ai2b2j + … + aiNbNj, для
//1 <= i <= M и 1 <= j <= K, где
//■ axy — элемент, находящийся на пересечении строки
//x и столбца y матрицы A;
//■ bxy — элемент, находящийся на пересечении строки
//x и столбца y матрицы B;
//■ cxy — элемент, находящийся на пересечении строки
//x и столбца y матрицы C.

#include <iostream>

int** DeleteRow(int** source, int row, int col, int index)
{
    int** newMassive = new int* [row];
    for (int i = 0; i < row; i++)
    {
        newMassive[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < index)
            {
                newMassive[i][j] = source[i][j];
            }
            if (i > index)
            {
                newMassive[i-1][j] = source[i][j];
            }
        }
    }
    return newMassive;
}
int** MatrixPlusMatrix(int** source, int** source2, int row, int col)
{
    int** newMassive = new int* [row];
    for (int i = 0; i < row; i++)
    {
        newMassive[i] = new int[col];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            newMassive[i][j] = source[i][j] + source2[i][j];
        }
    }
    return newMassive;
}
int main()
{
    int rows = 10;
    int cols = 10;
    int** randomMassive = new int* [rows];
    int** Matrix1 = new int* [rows];
    int** Matrix2 = new int* [rows];
    int** Matrix3 = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        randomMassive[i] = new int[cols];
        Matrix1[i] = new int[cols];
        Matrix2[i] = new int[cols];
        Matrix3[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            randomMassive[i][j] = rand() % 50;
            Matrix1[i][j] = rand() % 50;
            Matrix2[i][j] = rand() % 50;
            Matrix3[i][j] = rand() % 50;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << randomMassive[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for (int i = rows-1; i >= 0; i--)
    {
        for (int j = 0; j < cols; j++)
        {
            if (randomMassive[i][j] == 0)
            {
                randomMassive = DeleteRow(randomMassive, rows, cols, i);
                rows--;
                break;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << randomMassive[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    rows = 10;
    Matrix3 = MatrixPlusMatrix(Matrix1, Matrix2, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << Matrix1[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << Matrix2[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << Matrix3[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
