#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

void search(const string &text, const string &key);

signed main(int argc, char *argv[]) {
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
        if (input == "q")exit(0);
        for (auto &item: input) {
            item = static_cast<char>(toupper(item));
            if (string("ATGC*").find(item) == string::npos) {
                cout << "search text error" << endl;
                //break;
                goto LOOP_START;
            }
        }
        cout << input << endl;
        search(DNA, input);
    }
#pragma clang diagnostic pop
}

vector<string> automaton(string text, string key, string i, unsigned short incremental) {
    vector<string> ret, res;
    if (key.empty() && text.empty())return {i};
    if (key.empty()) return {i};
    if (text.empty() && key == "*") {
        return {i};
    } else if (text.empty())return {""};
    if (key.at(0) == text.at(0)) {
        ret = automaton(text.substr(1), key.substr(1), i + text.at(0), 0);
        for (auto &item: ret) {
            if (item.empty()) item.erase();
        }
        return ret;
    }
    if (key.starts_with('*')) {
        for (int j = incremental; j <= text.size(); ++j) {
            incremental = 0;
            if (j == 0)incremental = 1;
            res = automaton(text.substr(j), key.substr(1), i + text.substr(0, j), incremental);
            ret.insert(ret.end(), res.begin(), res.end());
        }
        return ret;
    }
    return {""};
}

void search(const string &text, const string &key) {
    for (int i = 0; i < text.size(); ++i) {
        auto a = automaton(text.substr(i), key, "", 0);
        for (const auto &t: a) {
            if (!t.empty()) {
                //string before = text.substr(max(0, i - 5), max(0, i - 4));

                cout << i << '~' << i + t.size() - 1 << '\t';
                for (int j = max(0, i - 5); j < i; ++j) {
                    cout << text.at(j);
                }
                cout << "\x1b[41m\x1b[1m" << t << "\x1b[0m\x1b[39m";
                for (int j = min(i + t.size(), text.size()); j < min(i + t.size() + 5, text.size()); ++j) {
                    cout << text.at(j);
                }
                cout << endl;
            }
        }
    }
}

