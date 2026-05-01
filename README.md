# CodeAlpha_Task-LoginRegistrationSystem-
# 🔐 Login & Registration System (C++)
A simple console-based Login and Registration System built in C++ using file handling. This project allows users to securely register and log in using a username and password stored in a local file.

##  Overview

This project demonstrates the implementation of a basic authentication system using C++. It uses file handling to store and retrieve user credentials, making it a practical example of working with persistent data.
##  Features

 1) User Registration with username and password  
 2) Login Authentication system  
 3) File handling using `users.txt`  
 4) Prevents duplicate usernames  
 5) Input validation for empty fields  
 6) Menu-driven interface (Register, Login, Exit)  


##  Technologies Used

C++
Standard Libraries:
*`iostream`
* `fstream`
* `string`


##  How It Works

### 1. Registration
- User enters a username and password  
- System checks if username already exists  
- If not, credentials are stored in `users.txt`  

### 2. Login
- User enters username and password  
- System verifies credentials from file  
- Displays success or error message  

##  File Structure
- main.cpp
- users.txt (auto-created when users register)
## Sample Output
===== Login System =====
1. Register
2. Login
0. Exit
Enter choice: 1

Enter username: user1
Enter password: 1234
Registration successful
## 👨‍💻 Author

Laraib Qadeer
BS Software Engineering Student
