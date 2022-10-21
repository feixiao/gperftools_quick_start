//
// Created by frank on 2022/10/21.
//

#include <iostream>
#include <vector>
#include <random>
#include <gperftools/heap-profiler.h>

void malloc(std::vector<uint8_t*>& array, uint16_t length);
void  free(std::vector<uint8_t*>& array);


// export LD_PRELOAD=/usr/local/Cellar/gperftools/2.9.1_1/lib/libtcmalloc.dylib
// env HEAPPROFILE=/Users/frank/workspace/github/gperftools_quick_start/mem HEAPCHECK=normal ./cmake-build-debug/memory/memory


// /usr/local/Cellar/gperftools/2.9.1_1/bin/pprof 需要对应好
//  pprof --pdf  ./cmake-build-debug/memory/memory mem.0001.heap > 1.pdf
// pprof --text  ./cmake-build-debug/memory/memory mem.0001.heap > 1.txt
int main() {
    printf("hello gperftools\n");

    HeapProfilerStart("memory");
    std::vector<uint8_t*> array;

    for (int i = 0; i < 500; ++i) {
        printf("****** %d ******\n", i);
        malloc(array, 16);
        free(array);
        array.clear();
    }
    HeapProfilerDump("END");

    HeapProfilerStop();
    return 0;
}

void mallocAAA(std::vector<uint8_t*>& array, uint16_t length) {
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

