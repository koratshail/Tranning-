Link list assignment

## Overview

A static library is created for the list operations. An application program use this library api for list operations.

## Description

A link list application meets following aspects.
1. A static library for link list operations is developed.
2. A proper menu-driven test application is developed to test all features (all APIs) of the library
3. There is a clean interface between test application an library. There isn't any shared global variables (no externs) in this test application or in library


## Link list library provides api for the following operations

1. Add a node in the Linked-list at top
2. Insert a node at specific location
3. Retrieve a node from top of the list
4. Retrieve a node from specific location
5. Remove the top node from list
6. Remove Nth node from Linked-list
7. Remove a node containing a value 'n'
8. Sort a list
9. Return size of Linked-list
10. Return position of the node containing data 'n'
11. Print Linked-list on specified output stream (i.e. stdout / stderr / filestream)
12. Delete a Linked-list and make head pointer NULL
13. Check whether the Linked-list is empty or not

## Library has below feutures

1. Library implements a singly linked list
2. It supports UINT32 (Unsigned int) data-type
3. Functions returning a pointer returns a NULL on error
4. Functions returns appropriate error codes or success
5. Functions contains validation of input arguments and error checking
6. This library will be linked with a test application. Test application is a menu driven and provide all options to the user. Application prints the errors if any on stderr console.
7. Proper error codes & function prototypes are defined in a library header file. Test application includes this header file. Application and library is not share anything except this header file. There is a clear abstraction between application and library
8. Memory allocation for nodes is done by library and not by application
9. Library is compiled using a makefile

## Run the program

Using make fie:
$make run

Using binary file
$./bin/linkList.out

## Author

Gaurang Rathod
