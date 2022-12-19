#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct {
    char FamilyName[32];
    char FirstName[32];
    int Score[5];
} Student;

struct NameComp {
    bool operator()(const Student &a, const Student &b) const noexcept {
        return string(a.FamilyName) < string(b.FamilyName);
    }
};

signed main() {
    int len;
    cout << "l”‚ð“ü—Í:";
    cin >> len;
    ifstream score_file;
    score_file.open("tensu.txt", ios_base::in);
    ofstream aggregate_file;
    aggregate_file.open("syukei.txt", ios_base::out);
    cout.rdbuf(aggregate_file.rdbuf());
    vector<Student> record(len, {"", "", {0, 0, 0, 0, 0}});

    for (auto &student: record) {
        score_file >> student.FirstName;
        score_file >> student.FamilyName;
        for (auto &c: student.FirstName) {
            c = static_cast<char>( tolower(c));
        }
        for (auto &c: student.FamilyName) {
            c = static_cast<char>( tolower(c));
        }
        student.FamilyName[0] = static_cast<char>(toupper(student.FamilyName[0]));
        for (auto &score: student.Score) {
            score_file >> score;
        }
    }

    sort(record.begin(), record.end(), NameComp{});
    array<pair<double, double>, 5> data;

    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        for (auto item: record) {
            sum += item.Score[i];
        }
        auto average = sum * 1.0 / len;
        cout << "‹³‰È" << i << "  •½‹Ï:" << average << '\t';
        double standard_deviation = 0;
        for (auto item: record) {
            standard_deviation += pow(average - item.Score[i], 2.0);
        }
        standard_deviation = sqrt(standard_deviation / len);
        cout << "•W€•Î·: " << standard_deviation << endl;
        data[i] = make_pair(average, standard_deviation);
    }

    for (const auto &item: record) {
        cout << item.FamilyName << ' ' << item.FirstName << '\t';
        for (int i = 0; i < 5; ++i) {
            cout << ((item.Score[i] - data.at(i).first) / data.at(i).second) * 10 + 50 << ' ';
        }
        cout << endl;
    }
}