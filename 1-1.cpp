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
    cout << "‘f”‚©‚Ç‚¤‚©”»’è‚·‚éŽ©‘R”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B: " << endl;
    string input;
    cin >> input;
    cout << input << "‚Í";
    auto decision_num = stoull(input);
    for (auto i = 2ULL; i <= sqrt(decision_num); ++i) {
        if (decision_num % i == 0) {
            cout << "‘f”‚Å‚Í‚ ‚è‚Ü‚¹‚ñB" << endl;
            exit(0);
        }
    }
    cout << "‘f”‚Å‚·B" << endl;
    return 0;
}
