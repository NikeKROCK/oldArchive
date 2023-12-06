// шаблон решателя плюсы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<Windows.h>
#include <iostream>
using namespace std;
int main()
{
    
    setlocale(LC_ALL, "rus");
    std::cout << "введите количество уравнений\n";
    int k;
    cin >> k;
    double* res = new double[k];
    double** matr = new double*[k];
    for (int i = 0; i < k; i++) {
        matr[i] = new double[k];
        cout << "введите уравнение "<<i<<'\n';
        std::string ur;
        cin >> ur;
        std::string checker;
        int number_of_var = k;
        bool isnxtposit = true;
        bool isanswer = false;
        for (int j = 0; j <ur.size(); j++) {
            switch (ur[j]) {
            case '+':{
                if (!isanswer) {
                    matr[i][k - number_of_var] = isnxtposit ? atof(checker.c_str()) : -atof(checker.c_str());
                    number_of_var -= 1;
                    checker = "";
                }
                isnxtposit = true;
                break;
            }
            case '-': {
                if (!isanswer) {
                    matr[i][k - number_of_var] = isnxtposit ? atof(checker.c_str()) : -atof(checker.c_str());
                    number_of_var -= 1;
                    checker = "";
                }
                isnxtposit = false;
                break;
            }
            case '=': {
                matr[i][k - number_of_var] = isnxtposit ? atof(checker.c_str()) : -atof(checker.c_str());
                checker = "";
                isanswer = true;
                isnxtposit = true;
                break;
            }
            default: {
                checker += ur[j];
            }
            }
        }
        res[i]= isnxtposit ? atof(checker.c_str()) : -atof(checker.c_str());
    }
    
    /*if (matr[0][0] == 0) {
        for (int i = 0; i < k; i++) {
            if (matr[0][i] != 0) {
                for (int j = 0; j < k; j++) {
                    double buf = matr[j][i];
                    matr[j][i]=matr[0][]
                }
            }
        }
    }*/
    //обработка
    int* swappers = new int [k];
    for (int i = 0; i < k; i++) {
        swappers[i] = -1;
    }
    int lim = k;
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            if (matr[i][i] == 0 && lim==k) {
                //пройтись по оставшимся элементам
                for (int jc = i; jc < k && matr[i][i]==0; jc++) {
                    for (int ic = i; ic < k && matr[i][i] == 0; ic++) {
                        //если не нуль, то заменяем
                        if (matr[ic][jc] != 0) {
                            double buf = res[i];
                            res[i] = res[ic];
                            res[ic] = buf;
                            double* bf = matr[i];
                            matr[i] = matr[ic];
                            matr[ic] = bf;
                           if (jc != i) {
                                swappers[i] = jc;
                                for (int iv = 0; iv < k; iv++) {
                                   double buf = matr[iv][jc];
                                   matr[iv][jc] = matr[iv][i];
                                   matr[iv][i] = buf;
                                }
                           //     for (int iv = 0; iv < k; iv++) {
                           //        double buf = matr[iv][jc];
                           //         matr[iv][jc] = matr[iv][i];
                           //         matr[iv][i] = buf;
                           //     }
                           }
                        }
                    }
                }
            }
            if (matr[i][i] != 0) {
                double mod = matr[j][i] / matr[i][i];
                for (int kz = i; kz < k; kz++) {
                    matr[j][kz] -= matr[i][kz] * mod;
                }
                res[j] -= res[i] * mod;
            }
            else {
                if (lim == k) {
                    lim = i;
                }
            }
        }

    }
    //анализ неопредилимости
  /*  bool* isundef = new bool[k];
    for (int i = 0; i < k; i++) {
        isundef[i] = false;
    }

    double** mayhaserr = new double*[k];
    for (int i = 0; i < k; i++) {
        mayhaserr[i] = new double[k + 1];
    }

    for (int i = 0; i < k; i++) {
        if (matr[i][i] == 0) {
            isundef[i] = true;
            for (int j = 0; j < k; j++) {
                mayhaserr[i][j] = matr[i][j];
            }
            mayhaserr[i][k] = res[i];
        }
    }*/
    //продолжение расчёта
    for (int i = lim-2; i > -1; i--) {
        for (int j = i - 1; j > -1 ; j--) {
            //if (!isundef[i]) {
                double mod = matr[j][i] / matr[i][i];
                matr[j][i] = 0;
                res[j] -= res[i] * mod;
         //   }
        }
    }
    for (int i = 0; i < lim-1; i++) {
        //if (!isundef[i]) {
            res[i] /= matr[i][i];
        //}
    }
   /* std::cout << "{";
    for (int i = 0; i < k; i++) {
        std::cout << '\n';
        for (int j = 0; j < k; j++) {
            std::cout << matr[i][j]<<' ';
        }
    }
    std::cout << " \n}\n";
    */
    
    for (int i = 0; i < lim-1; i++) {
        //if (!isundef[i]) {
        if (swappers[i] == -1) {
            std::cout <<"переменная "<<i+1<<'='<<res[i] << '\n';
        }
        else {
            std::cout << "переменная " << swappers[i]+1 << '=' << res[swappers[i]] << '\n';
        }
        //}
        //else {
          //  std::cout << "переменная " << i + 1 << " не определима\n";
        //}
    }
    std::cout << lim << '\n';
    //поиск ошибок
    /*
    for (int i = 0; i < k; i++) {
        double sm=0;
        for (int j = 0; j < k; j++) {
            if (!isundef[j]) {
                sm += mayhaserr[i][j] * res[j];
            }
        }
        if (sm != mayhaserr[i][k]) {
            std::cout << "уравнение " << i << " с ошибкой " << sm<<"!="<<mayhaserr[i][k]<< "\n";
        }
    }*/
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
