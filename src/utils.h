#ifndef UTILS_H_
#define UTILS_H_

#include <curl/curl.h>

void getCredentials(char *username, char *password);
size_t writeDataCallback(void *contents, size_t size, size_t nmemb, void *userdata);
CURLcode performCurlRequest(const char *url, const char *credentials, char **responseData);
int printJSON(const char *json);
int inputPrompt() ;


#endif  /* UTILS_H_ */