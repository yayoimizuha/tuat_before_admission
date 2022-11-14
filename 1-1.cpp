#include <iostream>
#include <bitset>
#include <bit>

using namespace std;

template<class T>
void print_b(T arg) {
    bitset<sizeof(T) * 8> bit(arg);
    for (int i = 0; i < bit.to_string().size(); ++i) {
        if (i % 8 == 0)cout << ' ';
        cout << bit.to_string()[i];
    }
    cout << ' ' << popcount(arg);
    cout << endl;
}

int main() {
    cout << "�f�����ǂ������肷�鐔����͂��Ă��������B: " << endl;
    string input;
    cout << sizeof(long long) << '\t' << sizeof(int) << '\t' << sizeof(short) << endl;
    //cin >> input;
    for (uint8_t i = 0; i < 100; ++i) {
        cout << +i;
        if (i % 3 == 0)cout << " *";
        cout << '\t';
        print_b(i);
    }
    return 0;
}
