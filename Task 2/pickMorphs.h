#ifndef NOVOMATIC_PICKMORPHS_H
#define NOVOMATIC_PICKMORPHS_H

#include <array>
#include <vector>

using namespace std;

/* Zdecydowałam się na implementację funkcji o złożoności O(4n) = O(n).
 * Mogę zaobserwować, że: nlogn < 4n <=> n<16, gdzie log to logarytm dwójkowy
 * Zatem skoro w skrajnych przypadkach weights może zawierać około 100 elementów, zdecydowałam, że złożność O(4n)
 * będzie najlepsza.
 */

array<int, 4> pickMorphs(const vector<float> &weights);

#endif
