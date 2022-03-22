#include "acutest.hpp"
#include "Dataframe.hpp"

void test_add(void) {
    // TEST_CHECK_(add(2,2)==4, "add(%d,%d)==%d", 2, 2, (2+2));
}

TEST_LIST = {
    {"int add(int, int);", test_add},
    {0} /*Terminate with {0}*/
};