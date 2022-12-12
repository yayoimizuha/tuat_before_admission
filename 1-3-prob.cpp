#include <iostream>
#include <random>

using namespace std;
auto variation = "ATGC";

signed main() {
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution<short> distribution(0, 3);

    for (int i = 0; i < 20000; ++i) {
        cout << variation[distribution(engine)];
    }
    cout << endl;
}