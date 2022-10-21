//
// Created by frank on 2022/10/21.
//

#include <iostream>
#include <vector>
#include <random>

void malloc(std::vector<uint8_t*>& array, uint16_t length);
void  free(std::vector<uint8_t*>& array);

int main() {
    printf("hello gperftools\n");

    std::vector<uint8_t*> array;

    malloc(array, 16);
    free(array);

    return 0;
}

void malloc(std::vector<uint8_t*>& array, uint16_t length) {
    for (int i = 0; i < length; ++i) {
        std::default_random_engine e;
        std::uniform_int_distribution<unsigned> u(2, 256);
        uint8_t* p = new uint8_t[u(e)];
        array.push_back(p);
    }
}

void  free(std::vector<uint8_t*>& array) {
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(1, array.size());

    int count = u(e);

    for (int i = 0; i < count; ++i) {
        std::default_random_engine e1;
        std::uniform_int_distribution<unsigned> u1(0, array.size());
        int index = u1(e1);

        if(array[index] != nullptr) {
            delete [] array[index];
            array[index] = nullptr;
        }
    }
}

