#include <iostream>
#include <bitset>
#include <bit>
#include <cmath>

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
    cout << "素数かどうか判定する自然数を入力してください。: " << endl;
    string input;
    cin >> input;
    cout << input << "は";
    auto decision_num = atoll(input.c_str());
    for (auto i = 2ULL; i <= sqrt(decision_num); ++i) {
        if (decision_num % i == 0) {
            cout << "素数ではありません。" << endl;
            exit(0);
        }
    }
    cout << "素数です。" << endl;
    return 0;
}
