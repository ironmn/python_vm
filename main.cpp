#include <stdio.h>
#include "spdlog/spdlog.h"
#include "arrayList.hpp"

int main(int argc, char **argv) {

    
    ArrayList<int> a;
    for (int i = 0; i < 10; i++) {
        a.add(1);
    }
    spdlog::info("The length is {}", a.length());
    printf("Hello world!\n");
    return 0;
}

