#include <iostream>
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
    return ((a+b)%2);
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
    bool l = eqv((imp(!z,x)),(akon(!x,y))); //первая функция
    return l;
}

void func()
{
    setlocale(LC_ALL, "Russian");
    cout << "Таблица истиности\n" << endl;
    string SKNF, SDNF;
    SDNF = "(";
    SKNF = "(";
    bool x, y, z, fun;
    cout << setw(3) << "x" << setw(3) << "y" << setw(3) << "z";
    cout << setw(3) << "f1" << setw(3) << endl;
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
        cout << setw(3) << f1(x, y, z) << endl;
        fun = f1(x, y, z);
        if (fun == 0) {
            if (x == 0) {
                SKNF = SKNF + "x+";
            }
            else {
                SKNF = SKNF + "!x+";
            }
            if (y == 0) {
                SKNF = SKNF + "y";
            }
            else {
                SKNF = SKNF + "!y";
            }
            if (z == 0) {
                SKNF = SKNF + "+z";
            }
            else {
                SKNF = SKNF + "+!z";
            }
            SKNF = SKNF + ")+(";

        }

        if (fun == 1) {

            if (x == 1) {
                SDNF = SDNF + "x";
            }
            else {
                SDNF = SDNF + "!x";
            }
            if (y == 1) {
                SDNF = SDNF + "y";
            }
            else {
                SDNF = SDNF + "!y";
            }
            if (z == 1) {
                SDNF = SDNF + "z";
            }
            else {
                SDNF = SDNF + "!z";
            }

            SDNF = SDNF + ")+(";

        }
    }
    SDNF = SDNF.substr(0, SDNF.size() - 2);
    SKNF = SKNF.substr(0, SKNF.size() - 2);
    cout << endl << "SDNF: " << SDNF << endl << "SKNF: " << SKNF << endl << endl;
}
string P_J() {
    cout << "Полином Жегалкина" << endl;
    bool s8[8], s7[7], s6[6], s5[5], s4[4], s3[3], s2[2], s;
    bool a, b, x, y, z;
    string c = "(";
    for (int i = 0; i < 8; i++) {
        {
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
        }
        for (int i = 0; i <= 7; i++)
            a = f1(x, y, z);
        if (a == 1) {
            s8[i] = true;
        }
        else {
            s8[i] = false;
        };
        b = s8[0];
        cout << s8[i];
    }
        if (a == 1) {
            c = c + "1)+(";
        }
        cout << endl;
        for (int i = 0; i < 7; i++) {
            s7[i] = s8[i] ^ s8[i + 1];
            cout << s7[i];
        }
        if (s7[0] == 1) {
            c = c + "z" + ")+(";

        }
        cout << endl;
        for (int i = 0; i < 6; i++) {
            s6[i] = s7[i] ^ s7[i + 1];
            cout << s6[i];
        }
        if (s6[0] == 1) {
            c = c + "y" + ")+(";
        }
        cout << endl;
        for (int i = 0; i < 5; i++) {
            s5[i] = s6[i] ^ s6[i + 1];
            cout << s5[i];
        }
        if (s5[0] == 1) {
            c = c + "yz" + ")+(";
        }
        cout << endl;
        for (int i = 0; i < 4; i++) {
            s4[i] = s5[i] ^ s5[i + 1];
            cout << s4[i];
        }
        if (s4[0] == 1) {
            c = c + "x" + ")+(";
        }
        cout << endl;
        for (int i = 0; i < 3; i++) {
            s3[i] = s4[i] ^ s4[i + 1];
            cout << s3[i];
        }
        if (s3[0] == 1) {
            c = c + "xz" + ")+(";
        }
        cout << endl;
        for (int i = 0; i < 2; i++) {
            s2[i] = s3[i] ^ s3[i + 1];
            cout << s2[i];
        }
        if (s2[0] == 1) {
            c = c + "xy" + ")+(";

        }
        cout << endl;
        s = s2[0] ^ s2[1];
        if (s == 1) {
            c = c + "xyz" + ")+(";
        }
cout << s << endl;
c = c.substr(0, c.size() - 2);
    cout << c << endl;
return c;
    }

int main()
{
    func();
    P_J();
    return 0;
}
