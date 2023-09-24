#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

// Function to get the username and password from the user
void getCredentials(char *username, char *password) {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
}

// Callback function to write the received data to a buffer
size_t writeDataCallback(void *contents, size_t size, size_t nmemb, void *userdata) {
    size_t totalSize = size * nmemb;
    char **buffer = (char **)userdata;

    // Allocate memory for the buffer and copy data
    *buffer = (char *)realloc(*buffer, totalSize + 1); // +1 for null-terminator
    if (*buffer) {
        memcpy(*buffer, contents, totalSize);
        (*buffer)[totalSize] = '\0'; // Null-terminate the string
    }

    return totalSize;
}

// Function to perform a CURL request
CURLcode performCurlRequest(const char *url, const char *credentials, char **responseData) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL.\n");
        return CURLE_FAILED_INIT;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_USERPWD, credentials);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeDataCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, responseData);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "CURL request failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
    return res;
}

int printJSON(const char *json) {
    cJSON *root = cJSON_Parse(json);
    if (root == NULL) {
        fprintf(stderr, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        return 1;
    }

    // Convert the parsed JSON object to a formatted JSON string
    char *prettyJsonString = cJSON_Print(root);

    // Print the formatted JSON string
    printf("%s\n", prettyJsonString);

    // Free the parsed JSON object and the generated JSON string
    cJSON_Delete(root);
    free(prettyJsonString);
    return 0;
}



// Get selection from user
int inputPrompt() {
    int request_code;
    int input_result;
    printf("Enter a number for listing machines: \n");
    printf("[1] for all machines\n");
    printf("[2] for 2D machines\n");
    printf("[3] for 3D machines\n");
    printf("[0] to exit\n");

    input_result = scanf("%d", &request_code);

    // Clear the input buffer to handle invalid inputs
    while (getchar() != '\n');

    return request_code;
}
