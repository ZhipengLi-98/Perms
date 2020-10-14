#include "lexiOrder.hpp"

void next_perm_lexi_swap(int data[], int size) {
    int last = -1, break_index = -1;
    for (int i = size - 1; i >= 0; i--) {
        if (data[i] < last) {
            break_index = i;
            break;
        }
        last = data[i];
    }
    if (last == data[0]) {
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }
    }
    else {
        int index = -1;
        for (int i = break_index; i < size; i++) {
            if (data[i] > data[break_index]) {
                index = i;
            }
        }
        std::swap(data[break_index], data[index]);
        int first = break_index + 1, last = size - 1;
        while (first < last) {
            std::swap(data[first], data[last]);
            first++, last--;
        }
    }
}

void next_perm_lexi(int data[], const int size) {
    for (int i = 0; i < size; i++) ++data[i];
    std::map<int, int> middle;
    for (int i = 1; i < size; i++) {
        middle.insert({i + 1, count_smaller_right(data, i - 1, size, data[i - 1])});
    }
    add(size, middle, size, -1, true);
    bool* used;
    used = new bool[size + 1];
    memset(data, -1, size * sizeof(int));
    memset(used, 0, (size + 1) * sizeof(bool));
    for (int j = size; j > 1; j--) {
        int temp = data[size - 1] == -1 ? 0 : 1;
        int last = -1;
        for (int i = size; i >= 2; i--) {
            if (used[i]) {
                temp++;
                continue;
            }
            if (middle[i] == size - i + 1 - temp) {
                last = i;
            }
        }
        if (last == -1) {
            data[size - 1] = j;
        }
        else {
            data[last - 2] = j;
            used[last] = 1;
        }
    }
    for (int i = 0; i < size; i++) {
        if (data[i] == -1) {
            data[i] = 1;
            break;
        }
    }
    delete[] used;
    for (int i = 0; i < size; i++) --data[i];
    return ;
}
