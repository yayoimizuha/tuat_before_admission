#include <bits/stdc++.h>

using namespace std;
#define GNUPLOT_PATH "C:\\Progra~1\\gnuplot\\bin\\gnuplot.exe -persist"

double leibniz(size_t order);

int main() {
    FILE *gnuplot;
    if ((gnuplot = popen(GNUPLOT_PATH, "w")) == nullptr) {
        cerr << "Can't execute gnuplot. " << GNUPLOT_PATH << endl;
        return EXIT_FAILURE;
    }
    fprintf(gnuplot, "set terminal windows color\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set logscale x\n");
    fprintf(gnuplot, "plot sin(x)\n");
    fprintf(gnuplot, "plot '-' using 1:2 w lp\n");
    auto range = 1;
    for (int i = 0; i < 3; ++i) {
        range *= 10;
        fprintf(gnuplot, "%d %lf\n", range, leibniz(range));
        cout << range << ' ' << leibniz(range) << endl;
    }
    fprintf(gnuplot, "e\n");
    pclose(gnuplot);

}

double leibniz(size_t order) {
    double pi = 0.0;
    bool square = true;
    for (size_t i = 0; i < order; ++i) {
        pi += static_cast<double>(square * 2 - 1) / static_cast<double>(2 * i + 1);
        square = !square;
    }
    return pi * 4;
}