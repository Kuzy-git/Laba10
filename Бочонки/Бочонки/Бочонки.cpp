#include <iostream>
#include <vector> 
#include <fstream> 
#include <stdlib.h> 
#include <time.h> 

using namespace std;

int main()
{
    vector <int> number;//вектор бочонков
    int N;//кол-во бочноков
    int addit;//вспомогательная переменная
    bool check;//переменная для проверки
    setlocale(LC_ALL, "rus");
    ofstream file;
    file.open("log.txt", ios::app);
    cout << "Введите количество бочонков. N = ";
    cin >> N;
    if (!file.is_open())
        cout << "Файл не открыт" << endl;
    else
    {
        file << "\nПрограмма запущена:\n" << "Кол-во бочонков. N =" << N << "\n";
        number.resize(N);//динамический масссив длинны N 
        srand(time(NULL));
        for (int i = 0; i < N; i++)//присвавает каждому бонченку номер
        {
            cin.get();
            do
            {
                check = 0;
                addit = (1 + rand() % (N));//рандомайзер от 1 до N
                for (int j = 0; j < N; j++)
                {
                    if (addit == number[j])//если боченок с таким номером уже есть, то переменная присваивает значение 1
                        check = 1;
                }
                if (check == false)
                {
                    number[i] = addit;//если номер боченка не использовался, то элемент вектора присваивает значение себе
                    cout << "Вытащен бочонок №" << i + 1 << ": " << number[i];
                }
            } while (check);//если номер бочонка уже использовался, то цикл повторяется, пока не найдется не занятый номер броченка
            if (file.is_open())
                file << "Вытащен бочонок №" << i + 1 << ": " << number[i] << "\n";
        }
        cout << "\nБочонки закончились!" << endl;
        if (file.is_open())
            file << "Программа завершена.\n";
        file.close();
    }
    return 0;
}


