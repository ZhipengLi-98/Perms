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
    int original[] = {0, 1, 2, 3, 4};
    int data[] = {0, 1, 2, 3, 4};
    const int size = 5;
    int cnt = 0;
    do {
        next_perm_decreased(data, size);
        
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        
        cnt++;
        // break;
    } while (!is_equal(original, data, size));
    std::cout << cnt << std::endl;
    return 0;
}
