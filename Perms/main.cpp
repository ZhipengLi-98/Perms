#include <iostream>

#include "increasedDecimal.hpp"
#include "decreasedDecimal.hpp"
#include "orthoTransposition.hpp"
#include "lexiOrder.hpp"

using namespace std;

bool is_equal(int original[], discreteNode dis[], int data[], int size) {
    for (int i = 0; i < size; i++) {
        if (original[i] != dis[data[i] - 1].data) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int original[] = {0, 1, 2, 7, 8, 9};
    const int size = 6;
    discreteNode dis[size];
    for (int i = 0; i < size; i++) {
        dis[i].data = original[i];
        dis[i].id = i;
    }
    sort(dis, dis + size);
    int data[size];
    for (int i = 0; i < size; i++) {
        data[dis[i].id] = i + 1;
    }
    int cnt = 0;
    do {
        next_perm_ortho(data, size);
        
        for (int i = 0; i < size; i++) {
            cout << dis[data[i] - 1].data << " ";
        }
        cout << endl;
        
        cnt++;
        // break;
    } while (!is_equal(original, dis, data, size));
    cout << cnt << endl;
    return 0;
}
