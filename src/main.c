#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"
#include "utils.h"

int main() {
    char username[100];
    char password[100];

    char *responseDataAll = NULL;
    char *responseData2d = NULL;
    char *responseData3d = NULL;
    
    // Get credentials from the user
    getCredentials(username, password);
    char credentials[200];
    snprintf(credentials, sizeof(credentials), "%s:%s", username, password);

    int request_code;
    while (1) {
        request_code = inputPrompt();
        
        switch (request_code) {
        case 1:
            // If it's the first time for all machines, request from the server
            if (responseDataAll == NULL) {
                // Request and handle all machines
                CURLcode resAll = performCurlRequest("https://app-academy-neu-codechallenge.azurewebsites.net/api/cut", credentials, &responseDataAll);

                if (resAll != CURLE_OK) {
                    fprintf(stderr, "Failed to retrieve all machines.\n");
                }
            }
            
            // Print all technology machines if there are any
            if (responseDataAll) {
                printf("All technology machines:\n");
                printJSON(responseDataAll);
            } else {
                printf("There are no machines.\n");
            }
            break;

        case 2:
            // If it's the first time for all machines, request from the server
            if (responseData2d == NULL) {
                // Request and handle 2D machines
                CURLcode res2d = performCurlRequest("https://app-academy-neu-codechallenge.azurewebsites.net/api/cut/2", credentials, &responseData2d);

                if (res2d != CURLE_OK) {
                    fprintf(stderr, "Failed to retrieve 2D machines.\n");
                }
            }
            // Print 2d technology machines if there are
            if (responseData2d) {
                printf("2d cutting technology machines:\n");
                printJSON(responseData2d);
            } else {
                printf("There is not any 2D technology machine.\n");
            }
            break;

        case 3:
            // If it's the first time for all machines, request from the server
            if (responseData3d == NULL) {
                 // Request and handle 3D machines
                CURLcode res3d = performCurlRequest("https://app-academy-neu-codechallenge.azurewebsites.net/api/cut/3", credentials, &responseData3d);

                if (res3d != CURLE_OK) {
                    fprintf(stderr, "Failed to retrieve 3D machines.\n");
                }
            }
            // Print 3d technology machines if there are
            if (responseData3d) {
                printf("3d cutting technology machines:\n");
                printJSON(responseData3d);
            } else {
                printf("There is not any 3D technology machine.\n");
            }
            break;

        case 0:
            printf("Exiting the program...\n");
            // Cleanup
            free(responseDataAll); 
            free(responseData2d); 
            free(responseData3d);
            
            // Exit the program
            return 0; 

        default:
            printf("You did not select a valid option.\n");
            break;
        }
    }    
    return 0;
}
