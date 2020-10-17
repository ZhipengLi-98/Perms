#include <iostream>

#include "increasedDecimal.hpp"
#include "decreasedDecimal.hpp"
#include "orthoTransposition.hpp"
#include "lexiOrder.hpp"
#include "shuffledOrder.hpp"

bool is_equal(int original[], int data[], int size) {
    for (int i = 0; i < size; i++) {
        if (original[i] != data[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int original[] = {0, 1, 2};
    int data[] = {0, 1, 2};
    const int size = 3;
    int cnt = 0;
    for (int step = 0; step < 6; step++) {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] + 1 << " ";
        }
        std::cout << std::endl;
        
        next_perm_increased_speedup(data, size);
        
        cnt++;
        // break;
    }
    std::cout << cnt << std::endl;
    return 0;
}
