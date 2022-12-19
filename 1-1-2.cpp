#include <iostream>

using namespace std;

constexpr double const_sqrt(double s) {
    double x = s / 2.0;
    double prev = 0.0;

    while (x != prev) {
        prev = x;
        x = (x + s / x) / 2.0;
    }
    return x;
}

constexpr int counter() {
    int count = 1;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 2; j <= const_sqrt(i); ++j) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
    }
    return 1000 - count;
}

int main() {
    const int ans = counter();
    cout << ans << endl;

}