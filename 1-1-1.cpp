#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "‘f”‚©‚Ç‚¤‚©”»’è‚·‚éŽ©‘R”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B: " << endl;
    string input;
    cin >> input;
    cout << input << "‚Í";
    auto decision_num = atoll(input.c_str());
    for (auto i = 2ULL; i <= sqrtl(decision_num); ++i) {
        if (decision_num % i == 0) {
            cout << "‘f”‚Å‚Í‚ ‚è‚Ü‚¹‚ñB" << endl;
            exit(0);
        }
    }
    cout << "‘f”‚Å‚·B" << endl;
    return 0;
}
