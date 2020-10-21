#include "shuffledOrder.hpp"

int step = 0, fact = 1;

inline bool is_prime(const int& n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

inline void init(const int& size) {
    for (int i = 2; i <= size; i++) fact *= i;
    int p;
    for (p = size + 1; !is_prime(p); p++);
    step = 1;
    int thr = fact / (p + 1);
    for (step = 1; step < thr; step *= p);
}

void next_perm_shuffled(int data[], int size) {
    if (!step) {
        init(size);
    }
    
    int rank = dec2inc(get_rank(data, size), size);
    rank = (rank + step) % fact;
    gen_perm(inc2dec(rank, size), size, data);
    
    // gen_perm((get_rank(data, size) + step) % fact, size, data);
}