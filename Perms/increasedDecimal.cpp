#include "increasedDecimal.hpp"

void next_perm_increased(int data[], int size) {
    for (int i = 0; i < size; i++) ++data[i];
    std::map<int, int> middle = get_middle(data, size);
    add(size, middle, 2, 1);
    transfer(data, size, middle);
    for (int i = 0; i < size; i++) --data[i];
    return ;
}

// for 0...n-1 only
void next_perm_increased_speedup(int data[], int size) {
    gen_perm(inc2dec(dec2inc(get_rank(data, size), size) + 1, size), size, data);
}
