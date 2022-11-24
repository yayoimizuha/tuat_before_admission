#include <iostream>

using namespace std;

constexpr int sqrt_int(int x) {
    int return_num = 0;
    while (return_num * return_num < x) {
        return_num++;
    }
    return return_num;
}

constexpr int counter() {
    int count = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 2; j <= sqrt_int(i); ++j) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
    }
    return 1000 - count;
}

int main() {
    cout << counter() << endl;
}