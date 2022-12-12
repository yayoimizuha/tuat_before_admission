#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<size_t> search(const string &text, const string &key);

signed main1(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "usage: " << argv[0] << " input_file" << endl;
        return EXIT_FAILURE;
    }
    ifstream ifs(argv[1]);
    if (ifs.fail()) {
        cout << "Failed to open file: " << argv[1] << endl;
        return EXIT_FAILURE;
    }
    string DNA;
    getline(ifs, DNA);
    cout << DNA << endl;
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    for (;;) {
        LOOP_START:
        string input;
        cout << "please input search text: " << flush;
        cin >> input;
        for (auto &item: input) {
            item = static_cast<char>(toupper(item));
            if (string("ATGC").find(item) == string::npos) {
                cout << "search text error" << endl;
                //break;
                goto LOOP_START;
            }
        }
        cout << input << endl;
        system("pause");
    }
#pragma clang diagnostic pop
}

vector<size_t> automaton(string text, string key, size_t i);

int main() {
    automaton("asdjkasgsagfjkadsfhasjf", "asd", 1);
}

vector<size_t> automaton(string text, string key, size_t i) {
    cout << text << endl;
    cout << key << endl;
    if (key.empty() || text.empty()) {
        return {i};
    }
    if (key.starts_with('*')) {
        for (int j = 1; j < text.size(); ++j) {
            //res= automaton(text.substr(j), key.substr(1), i + 1);
        }
    } else if (key[0] == text[0]) {
        automaton(text.substr(1), key.substr(1), i + 1);
    }
    return {1};
}

vector<size_t> search(const string &text, const string &key) {
    size_t index = 0;
    for (int i = 0; i < text.size() - key.size(); ++i) {
        for (int j = i; j < i + key.size(); ++j) {

        }
    }
}

