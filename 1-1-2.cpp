#include <iostream>
#include <cmath>

using namespace std;

constexpr int counter() {
    int count = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 2; j <= sqrt(i); ++j) {
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