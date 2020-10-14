#include <iostream>

#include "increasedDecimal.hpp"
#include "decreasedDecimal.hpp"
#include "orthoTransposition.hpp"
#include "lexiOrder.hpp"

bool is_equal(int original[], int data[], int size) {
    for (int i = 0; i < size; i++) {
        if (original[i] != data[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int original[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int size = 9;
    int data[size];
    memcpy(data, original, size * sizeof(int));
    int cnt = 0;
    do {
        next_perm_ortho(data, size);
        /*
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        */
        cnt++;
        // break;
    } while (!is_equal(original, data, size));
    std::cout << cnt << endl;
    return 0;
}
