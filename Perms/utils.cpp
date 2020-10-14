#include "utils.hpp"

int count_smaller_right(int data[], int begin, int end, int target) {
    int res = 0;
    for (int i = begin; i < end; i++) {
        if (data[i] < target) {
            res++;
        }
    }
    return res;
}

map<int, int> get_middle(int data[], int size) {
    map<int, int> pos, middle;
    for (int i = 0; i < size; i++) {
        pos.insert({data[i], i});
    }
    for (int i = 2; i <= size; i++) {
        middle.insert({i, count_smaller_right(data, pos[i], size, i)});
    }
    return middle;
}

// stride = 1 for incresedDecimal and -1 for decreasedDecimal
void add(int size, map<int, int>& middle, int index, int stride, bool lexi) {
    int cnt = 0;
    while (true) {
        if (cnt == size - 1) {
            break;
        }
        middle[index]++;
        if (middle[index] == (lexi ? size - index + 2 : index)) {
            middle[index] = 0;
            index += stride;
            cnt++;
        }
        else {
            break;
        }
    }
    return ;
}

void transfer(int data[], int size, map<int, int> middle) {
    int *result = new int[size];
    memset(result, -1, size * sizeof(int));
    for (int i = size; i > 1; i--) {
        int cnt = 0;
        for (int j = 0; j < size; j++) {
            if (result[j] == -1) {
                cnt++;
            }
            if (cnt == middle[i] + 1) {
                result[j] = i;
                break;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (result[i] == -1) {
            result[i] = 1;
            break;
        }
    }
    
    for (int i = 0; i < size; i++) {
        data[i] = result[size - i - 1];
    }
    delete[] result;
}