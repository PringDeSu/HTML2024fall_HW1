#pragma once

#include "vec.hpp"
#include <sstream>
#include <iostream>
using namespace std;

int convert_string_to_int(string s) {
    stringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
}

long double convert_string_to_long_double(string s) {
    stringstream ss(s);
    long double ans;
    ss >> ans;
    return ans;
}

void convert_string_to_TRAIN(string s, TRAIN &tr) {
    tr.x[0] = 1.0;
    stringstream ss(s);
    ss >> tr.y;
    string t;
    while (ss >> t) {
        int colon_pos = t.find(':');
        int id = convert_string_to_int(t.substr(0, colon_pos));
        long double num = convert_string_to_long_double(t.substr(colon_pos + 1, t.size() - colon_pos - 1));
        tr.x[id] = num;
    }
}
