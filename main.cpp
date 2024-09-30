#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "io.hpp"
#ifdef PLA_MODIFIED
#include "PLA_MODIFIED.hpp"
#else
#include "PLA.hpp"
#endif
using namespace std;

ifstream file_input("input.txt");

const int N = 200, ITERATION_TIME = 1000;
vector<TRAIN> vtr(N, TRAIN());

int main(int argc, char *argv[]) {
    ofstream file_iteration_count(argv[1]), file_lengths(argv[2]);
    // input training data
    string s;
    for (int i = 0; i < N; i++) {
        getline(file_input, s);
        convert_string_to_TRAIN(s, vtr[i]);
    }
    // expirement 1000 times
    mt19937 rnd(time(NULL));
    for (int i = 1; i <= ITERATION_TIME; i++) {
        PLA::change_random_seed(rnd());
        chrono::system_clock::time_point before = chrono::system_clock::now();
        PLA::LOG result = PLA::train(vtr);
        chrono::system_clock::time_point after = chrono::system_clock::now();
        file_iteration_count << result.iteration_count << '\n';
        for (auto len : result.lengths) file_lengths << len << ' ';
        file_lengths << '\n';
        #ifdef PRINT
        cout << "iteration #" << i << ": " << result.iteration_count << endl;
        cout << "took " << chrono::duration_cast<chrono::seconds>(after - before).count() << " seconds" << endl;
        #endif
    }
    return 0;
}
