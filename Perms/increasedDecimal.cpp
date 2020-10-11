#include "increasedDecimal.hpp"

void next_perm_increased(int data[], int size) {
    map<int, int> middle = get_middle(data, size);
    add(size, middle, 2, 1);
    transfer(data, size, middle);
    return ;
}
