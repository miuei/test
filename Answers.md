Technical Questions

Please answer the following questions in a markdown file called Answers to technical questions.md.

### 1. How long did you spend on the coding test? What would you add to your solution if you had more time? If you didn't spend much time on the coding test, use this as an opportunity to explain what you would add.

3 hours. 

Not because of the time, but because the code must be uploaded to a public repository, I didn't include the user and the password in a config file or hardcoded in the code, and I included a function to ask it to the user.

I could have added more tests

### 2. What was the most useful feature added to the latest version of your chosen language? Please include a snippet of code that shows how you've used it.

I used standard C, so didn't use any special feature. I used the very well known and vastly used Curl library for the HTTP requests, and cJSON for formatting the JSON in a more readable way.

### 3. How would you track down a performance issue in production? Have you ever had to do this?
I've never had to do this

### 4. How would you improve the Lantek API that you just used?
For this task, a really simple API is enough, so I don't really know all the features of the API. However, some possible improvements are:
- Include other authentication methods appart from user/password, such as using tokens or certificates.
- When testing, I realised that using wrong credentials result in an empty response, with no indication that the credentials are not correct
- Other types of filtering the machines, for example, manufacturers.