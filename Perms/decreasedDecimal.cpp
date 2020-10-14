#include "decreasedDecimal.hpp"

void next_perm_decreased(int data[], int size) {
    for (int i = 0; i < size; i++) ++data[i];
    std::map<int, int> middle = get_middle(data, size);
    add(size, middle, size, -1);
    transfer(data, size, middle);
    for (int i = 0; i < size; i++) --data[i];
    return ;
}

// for 0...n-1 only
void next_perm_decreased_speedup(int data[], int size) {
    gen_perm(get_rank(data, size) + 1, size, data);
}
