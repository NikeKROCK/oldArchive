﻿// aerflame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <windows.h>
#include <iostream>
using namespace std;

inline void tell() {
    cout << "Купи"<<'\n';
}
int main()
{
    
    setlocale(LC_ALL, "Russian");
    tell();
    bool stopit=false;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    system("color 2");
    string a;
    while (!stopit) {
        
        cout << "что ответить?" << '\n';
        if (cin >> a) {
            goto en;
        }
        else {}cin.
    
       
    }
en:cout << "you got it";
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