#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

typedef struct {
    char FamilyName[32];
    char FirstName[32];
    int Score[5];
} Student;

signed main() {
    int len;
    cout << "人数を入力:";
    cin >> len;
    ifstream score_file;
    score_file.open("/home/tomokazu/CLionProjects/tuat_before_admission/tensu.txt");
    vector<Student> record(len, {"", "", 0});
    for (auto &student: record) {
        score_file >> student.FamilyName;
        for (auto &c: student.FamilyName) {
            c = tolower(c);
        }
        student.FamilyName[0] = toupper(student.FamilyName[0]);
        score_file >> student.FirstName;
        for (auto &c: student.FirstName) {
            c = toupper(c);
        }
        for (auto &score: student.Score) {
            score_file >> score;
        }
    }
    for (const auto &item: record) {
        cout << item.FamilyName << '\t' << item.FirstName << endl;
        for (const auto i: item.Score) {
            cout << i << ' ';
        }
        cout << endl;
    }


}