#include <vector>
#include "../../std_lib_facilities.h"
#include <iostream>

int main()
{
    int a;
    vector <int> col(1000);
    cout << "what's is first value?\n";
    cin >> a;
    cout << "1 " << a<<'\n';
    col[0] = a;
    int now;




    for (int i = 1; col[i] != 1; i++) {
        if (col[i - 1] % 2 == 0) {
            col[i] = col[i - 1] / 2;
            cout << i + 1 << " " << col[i]<<'\n';
        }
        else {
            col[i] = col[i - 1] * 3 + 1 ;
            cout << i + 1 << " " << col[i] << '\n';
        }
    }
    keep_window_open();
}

