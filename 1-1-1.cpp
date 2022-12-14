#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "素数かどうか判定する自然数を入力してください。: " << endl;
    string input;
    cin >> input;
    cout << input << "は";
    auto decision_num = atoll(input.c_str());
    for (auto i = 2ULL; i <= sqrtl(decision_num); ++i) {
        if (decision_num % i == 0) {
            cout << "素数ではありません。" << endl;
            exit(0);
        }
    }
    cout << "素数です。" << endl;
    return 0;
}
