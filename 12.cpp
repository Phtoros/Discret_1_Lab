﻿#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

bool eqv(bool a, bool b)
{
    return (!(a ^ b));
}//эквивалентность <->
bool imp(bool a, bool b)
{
    return (!a || b);
}//импликация ->
bool aimp(bool a, bool b)
{
    return (!(!a || b));
}//антиимпликация !->
bool pl(bool a, bool b)
{
    return ((a + b) % 2);
}//сложение по модулю 2
bool adiz(bool a, bool b)
{
    return (!(a || b));
}//антидизъюнкция
bool akon(bool a, bool b)
{
    return (!(a && b));
}//антиконъюнкция
bool f1(bool x, bool y, bool z)
{
    bool l = x || (akon(y, z)); //первая функция
    return l;
}
bool f2(bool x, bool y, bool z)
{
    bool l = akon((x || y), (x || z));  //вторая функция
    return l;
}

void func()
{
    setlocale(LC_ALL, "Russian");
    bool x, y, z;
    cout << setw(3) << "x" << setw(3) << "y" << setw(3) << "z";
    cout << setw(3) << "f1" << setw(3) << "f2" << setw(3) << endl;
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            x = 0;
        }
        else {
            x = 1;
        }
        if ((i <= 1) || (i == 4) || (i == 5)) {
            y = 0;
        }
        else {
            y = 1;
        }
        if (i % 2) {
            z = 1;
        }
        else {
            z = 0;
        }
        cout << setw(3) << x << setw(3) << y << setw(3) << z << setw(3);
        cout << setw(3) << f1(x, y, z);
        cout << setw(3) << f2(x, y, z) << endl;
        if (f1(x, y, z) != f2(x, y, z)) {
            cout << " - функции не эквивалентны!" << endl;
            break;
        }
        else {
            if (i == 7) {
                cout << "f1 эквивалентна f2" << endl;
            }
            continue;
        }
    }
}

int main()
{
    func();
    return 0;
}
