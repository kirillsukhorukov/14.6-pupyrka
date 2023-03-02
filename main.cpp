#include <iostream>

using namespace std;

//Объявление глобальной переменной размерности поля пупырки
int N=12;
//Объявление глобального двумерного массива поля пупырки
bool field[12][12];

//Процедура инициализации массива пупырки
void init_array()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) field[i][j] = true;
    }
}


//Функция вывода и проверки двумерного массива
bool check_array (const bool (&array) [12][12])
{
    bool result = false;
    cout << '\t';
    for (int x=1; x<N+1; x++) cout << x << '\t';
    cout << endl;
    for (int i=0; i<N; i++)
    {
        cout << i+1 << '\t';
        for (int j=0; j<N; j++)
        {
            if (array[i][j])
            {
                cout << "O" << '\t';
                result = true;
            }
            else cout << "X" << '\t';
        }
        cout << endl;
    }
    cout << endl;
    return result;
}

//Функция проверки введенных координат
bool coordinate_check (int x1, int y1, int x2, int y2)
{
    if (x1<1 || x1>N || y1<1 || y1>N)
    {
        cout << "Incorrectly entered coordinates of the upper left corner of the region!"<< endl;
        return true;
    }
    if (x2<1 || x2>N || y2<1 || y2>N)
    {
        cout << "Incorrectly entered coordinates of the lower right corner of the region!"<< endl;
        return true;
    }
    if (x1>x2 || y1>y2)
    {
        cout << "Incorrectly entered coordinates of the corners of the region!"<< endl;
        return true;
    }
    return false;
}
//Процедура лопания региона пузырей
void bubble_bursting (int x1, int y1, int x2, int y2)
{
   for (int i=y1-1; i<y2; i++)
    {
        for (int j=x1-1; j<x2; j++)
        {
            if (field[i][j])
            {

                cout << "Pop!" << '\t';
                field[i][j] = false;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    cout << "------------Pupyrka------------\n\n";

    //Инициализация массива пупырки с помощью процедуры
    init_array();

    //Инициализация флага наличия целых пузырей и вывод массива пупырки
    bool wholeBubble = check_array(field);

    //Инициализация координат региона для лопания пузырей
    int x1, y1, x2, y2;

    //Организация цикла лопания пузырей пока они не закончатся
    while (wholeBubble)
    {
        //Ввод координат региона
        do
        {
            cout << "Enter the coordinates of the upper left corner of the region: ";
            cin >> x1 >> y1;
            cout << "Enter the coordinates of the lower right corner of the region: ";
            cin >> x2 >> y2;
        } while(coordinate_check(x1, y1, x2, y2));

        //Лопаем регион пузырей
        bubble_bursting(x1, y1, x2, y2);

        //Выводим и проверяем массив пупырки
        wholeBubble = check_array(field);

    }

    cout << "GAME OVER!";

    return 0;
}
