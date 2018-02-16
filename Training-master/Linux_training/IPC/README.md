Client-Server program using socket programming in C

## Overview

This is a simple client and server written in C using the socket API. Server is
multithreaded. Multiple client can simulate simultanous connections to the
server, which will create a new thread at server side for every incoming
connection from client. Server perform lowercase to uppercase conversion for
the data sent by client. Client take a word file as input and send its chuncks
of 1K bytes data to server for uppercase conversion. Client also stores the
converted uppercase data into new file named "converted_file.txt".

## Description

A TCP client-server application which meets following aspects.
1.	Both server and clients are separate applications written in separate
source files
2.	Server application takes IP address of interface and port address to
listen on as command line arguments
3.	Client application takes IP address of server to connect as command line
argument
4.	Server allows multiple connection simultaneously by spawning separate
request handler thread for each client
5.	On, successful connection establishment client starts reading a text
file and sends it to server in 1KB chunks. On receiving each chunk, server
converts the text into all capital letter and sends it back to client. Client
writes the received data in output file. When whole file is converted to capital
letters, client exits gracefully by closing the connection. On this event, the
request handler thread on server for the client also terminates gracefully.


## Compilation

Server proram:
$gcc server.c -lpthread -o server.out -Wall

Client program:
$gcc client.c -o client.out -Wall

## Run the program

Server program:
$./server.out server_machine_IP_address port_number

client side a file require for which server convert it to lowercase letter
Client program:

$./client.out server_machine_IP_address file_name_to_convert

## How to use application

Client side a file is given as input for its contains' conversion of lowercase
to uppercase. The converted file is stored in bin folder at client side.

## Author

Gaurang Rathod

## Acknowledgment

* Hemant Parikh for reviewing and suggestions.
* man pages of socket
