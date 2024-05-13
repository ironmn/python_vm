#include <stdio.h>
#include "spdlog/spdlog.h"
#include "arrayList.hpp"
#include "bufferInputStream.hpp"


int main(int argc, char **argv) {

    
    ArrayList<int> a;
    for (int i = 0; i < 10; i++) {
        a.add(1);
    }
    spdlog::info("The length is {}", a.length());
    printf("Hello world!\n");

    if (argc <= 1) {
        spdlog::error("Please provide a file name");
        return 1;
    }

    BufferInputStream stream(argv[1]);
    printf("magic number is 0x %x\n", stream.read_int());
    return 0;
}

