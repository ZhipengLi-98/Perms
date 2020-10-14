#include "orthoTransposition.hpp"

bool get_direction(int index, std::map<int, int> middle) {
    if (index != 2) {
        if (index % 2 == 0) {
            if ((middle[index - 1] + middle[index - 2]) % 2 == 1) {
                return true;
            }
        }
        else {
            if (middle[index - 1] % 2 == 1) {
                return true;
            }
        }
    }
    return false;
}

void next_perm_ortho(int data[], int size) {
    for (int i = 0; i < size; i++) ++data[i];
    std::map<int, int> pos, middle;
    for (int i = 0; i < size; i++) {
        pos.insert({data[i], i});
    }
    for (int i = 2; i <= size; i++) {
        middle.insert({i, 0});
    }
    for (int i = 2; i <= size; i++) {
        bool direction = get_direction(i, middle);
        if (direction == 0) {
            middle[i] = count_smaller_right(data, pos[i], size, i);
        }
        else {
            middle[i] = count_smaller_right(data, 0, pos[i], i);
        }
    }
    add(size, middle, size, -1);
    memset(data, -1, size * sizeof(int));
    for (int i = size; i > 1; i--) {
        bool direction = get_direction(i, middle);
        int cnt = 0;
        if (direction == 0) {
            for (int j = size - 1; j >= 0; j--) {
                if (data[j] == -1) {
                    cnt++;
                }
                if (cnt == middle[i] + 1) {
                    data[j] = i;
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < size; j++) {
                if (data[j] == -1) {
                    cnt++;
                }
                if (cnt == middle[i] + 1) {
                    data[j] = i;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (data[i] == -1) {
            data[i] = 1;
            break;
        }
    }
    for (int i = 0; i < size; i++) --data[i];
    return;
}
