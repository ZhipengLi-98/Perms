#include "increasedDecimal.hpp"

void next_perm_increased(int data[], int size) {
    for (int i = 0; i < size; i++) ++data[i];
    std::map<int, int> middle = get_middle(data, size);
    add(size, middle, 2, 1);
    transfer(data, size, middle);
    for (int i = 0; i < size; i++) --data[i];
    return ;
}
