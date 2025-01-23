# Library Management System

This is a **Library Management System** implemented in C++. It allows managing books and users in a library, including adding books, borrowing and returning books, and searching for books by prefix. The system also supports printing library information sorted by book ID or name and displaying users who borrowed specific books.

## Features
- **Add a book**: Add a new book to the library with its ID, name, and quantity.
- **Search books by prefix**: Search for books whose names start with a specific prefix.
- **Print who borrowed a book**: Display the names of users who borrowed a specific book.
- **Print library by ID**: Print all books in the library sorted by their ID.
- **Print library by name**: Print all books in the library sorted by their name.
- **Add a user**: Add a new user to the library with their name and ID.
- **User borrow a book**: Allow a user to borrow a book.
- **User return a book**: Allow a user to return a borrowed book.
- **Print users**: Display all users and the books they borrowed.

## How to Use
1. **Compile the code**: Use a C++ compiler (e.g., `g++`) to compile the program:
   ```bash
   g++ -o library.cpp
