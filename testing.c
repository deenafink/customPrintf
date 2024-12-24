#include "./Unity/src/unity.h" // Include Unity
#include "./project.c" // Include your source file

void test_add_should_return_sum(void) {
    TEST_ASSERT_EQUAL(printf("%d\n", 7), my_printf("%d\n", 7));
}

int main(void) {
    UNITY_BEGIN(); // Start Unity Test Framework
    RUN_TEST(test_add_should_return_sum);
    return UNITY_END(); // End and report
}