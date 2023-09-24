#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "../src/utils.h"


void testWriteDataCallback() {
    // Define test data
    char *buffer = NULL;
    size_t size = 5;
    size_t nmemb = 4;
    size_t totalSize = size * nmemb;
    char *contents = "Test content";

    // Call the writeDataCallback function
    size_t result = writeDataCallback(contents, size, nmemb, &buffer);

     // Verify that the buffer is not NULL
    CU_ASSERT_PTR_NOT_NULL(buffer);
    // Verify that the buffer contains the correct data
    CU_ASSERT_STRING_EQUAL(buffer, contents);
    // Verify that the total size matches the expected value
    CU_ASSERT_EQUAL(result, totalSize);

    // Clean up
    free(buffer);
}

void testPerformCurlRequest() {
    // Define test data
    const char *url = "https://app-academy-neu-codechallenge.azurewebsites.net/api/cut";
    const char *credentials = "username:password";
    char *responseData = NULL;

    // Call the function to test
    CURLcode result = performCurlRequest(url, credentials, &responseData);


    CU_ASSERT_EQUAL(CURLE_OK, result);

    // Clean up allocated memory if needed
    if (responseData != NULL) {
        free(responseData);
    }
}

void testInputPrompt() {
    // Define test data (redirected input)
    char input[] = "2\n"; // Simulate user entering '2'
    FILE *input_file = fopen("prompt-input.txt", "w");
    fprintf(input_file, "%s", input);
    fclose(input_file);

    // Redirect stdin to read from the input file
    freopen("prompt-input.txt", "r", stdin);

    // Call the inputPrompt function
    int result = inputPrompt();

    // Replace with appropriate assertions
    CU_ASSERT_EQUAL(2, result);
}


