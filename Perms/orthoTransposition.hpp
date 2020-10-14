#ifndef orthoTransposition_hpp
#define orthoTransposition_hpp

#include <stdio.h>

#include "utils.hpp"

bool get_direction(int index, std::map<int, int> middle);
void next_perm_ortho(int data[], int size);

#endif /* orthoTransposition_hpp */
