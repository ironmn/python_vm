#include "basicTest.hpp"

#include <cstdint>

#ifndef DATA_STRUCTURE_TEST
#define DATA_STRUCTURE_TEST

TEST_CASE("ArrayList test", "[arrayList]") {
    ArrayList<int> a;
    REQUIRE(a.length() == 8);
    for (int i = 0; i < 10; i++) {
        a.add(1);
    }
    REQUIRE(a.size() == 10); 
    a.insert(0,2);
    REQUIRE(a.get(0) == 2);
    REQUIRE(a.get(1) == 1);
    REQUIRE(a.get(10) == 1);
    REQUIRE(a.size() == 11);   
}


#endif 