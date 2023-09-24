
#include "CUnit/Basic.h"
#include "test_suite.h"
#include "../src/utils.h"


// Define a test suite and initialize it
CU_pSuite suite = NULL;

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main() {
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Set up the suite and test functions
    suite = CU_add_suite("TestSuite", init_suite, clean_suite);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add test cases to the suite
    CU_add_test(suite, "testWriteDataCallback", testWriteDataCallback);
    CU_add_test(suite, "testPerformCurlRequest", testPerformCurlRequest);
    CU_add_test(suite, "testInputPrompt", testInputPrompt);

    // Set up the basic run mode and run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}


