#pragma once

#include <vector>
#include <random>
#include "vec.hpp"
using namespace std;


namespace PLA {
    mt19937 rnd(time(NULL));

    struct LOG {
        vec w_result;
        int iteration_count;
        vector<long double> lengths;
        LOG() {}
        LOG(vec w, int it, vector<long double> len) : w_result(w), iteration_count(it), lengths(len) {}
    };

    void change_random_seed(unsigned int _seed) {
        rnd.seed(_seed);
    }

    int pick_id(int l, int r) {
        unsigned int len = r - l;
        unsigned int big = UINT32_MAX / len * len;
        unsigned int x;
        do {
            x = rnd();
        } while (x >= big);
        return l + x % len;
    }

    int sign(long double x) {
        return (x > 0.0 ? 1 : -1);
    }

    LOG train(vector<TRAIN> &training_dataset) {
        int n = training_dataset.size();
        vec w;
        for (int i = 0; i <= DIM; i++) w[i] = 0.0;
        vector<long double> len;
        len.push_back(0);
        int cnt = 0;
        while (true) {
            bool found_mistake = false;
            for (int $ = 0; $ < 5 * n; $++) {
                int id = pick_id(0, n);
                TRAIN &tr = training_dataset[id];
                if (sign(w * tr.x) == tr.y) continue;
                found_mistake = true;
                cnt++;
                w += (tr.x * tr.y);
                len.push_back(sqrt(w * w));
                break;
            }
            if (!found_mistake) break;
        }
        return LOG(w, cnt, len);
    }
}
