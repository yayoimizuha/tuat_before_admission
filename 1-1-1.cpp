#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "�f�����ǂ������肷�鎩�R������͂��Ă��������B: " << endl;
    string input;
    cin >> input;
    cout << input << "��";
    auto decision_num = atoll(input.c_str());
    for (auto i = 2ULL; i <= sqrtl(decision_num); ++i) {
        if (decision_num % i == 0) {
            cout << "�f���ł͂���܂���B" << endl;
            exit(0);
        }
    }
    cout << "�f���ł��B" << endl;
    return 0;
}
