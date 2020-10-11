#include "decreasedDecimal.hpp"

void next_perm_decreased(int data[], int size) {
    map<int, int> middle = get_middle(data, size);
    add(size, middle, size, -1);
    transfer(data, size, middle);
    return ;
}
