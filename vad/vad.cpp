﻿// vad.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;
float funk(float last,int toch,int nwtoch,float ch) 
{
    if (nwtoch >= toch) {
        return (last + ch / last) / 2.0f;
    }
    else {
        return funk((last + ch / last) / 2.0f, toch, nwtoch+1, ch);
    }
}
int main()
{
    SetConsoleOutputCP(1251);
    cout << "введите уровень точности далее число\n" ;
    int tc;
    if (cin >> tc) {
        float ch;
        if (cin >> ch) {
                cout<<funk((1.0f+ch)/2.0f,tc,0,ch)<<"\n";
                return 0;
        }
        else { 
            return 1;
        }
    }
    else {
        return 1;
    }
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
