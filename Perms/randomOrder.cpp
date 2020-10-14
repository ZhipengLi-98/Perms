#include "randomOrder.hpp"

#ifndef NODE_CNT
#define NODE_CNT 10
#endif /* NODE_CNT */

int *shuffled, *shuffled_rev;

int factorial(const int& x) {
    int s = 1;
    for (int i = 2; i <= x; i++) s *= i;
    return s;
}
inline void init() {
    int f = factorial(NODE_CNT);
    shuffled = new int[f];
    shuffled_rev = new int[f];
    for (int i = 0; i < f; i++) shuffled[i] = i;
    std::random_shuffle(shuffled + 1, shuffled + f);
    for (int i = 0; i < f; i++) shuffled_rev[shuffled[i]] = i;
}

void next_perm_random(int data[], int size) {
    if (!shuffled) init();
    gen_perm(shuffled[shuffled_rev[get_rank(data, size)] + 1], size, data);
}