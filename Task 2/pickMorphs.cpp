#include <algorithm>
#include "pickMorphs.h"

array<int, 4> pickMorphs(const vector<float> &weights) {
    array<int, 4> result{-1, -1, -1, -1};
    if (weights.size() < 4) return result;
    for (int i = 0; i < 4; i++) {
        float largest = 0.0;
        for (int j = 0; j < weights.size(); j++) {
            if (weights[j] >= largest && result[0] != j && result[1] != j && result[2] != j && result[3] != j) {
                largest = weights[j];
                result[i] = j;
            }
        }
    }
    return result;
}