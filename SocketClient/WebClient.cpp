/*
Created on Mon Oct 31 13:25:45 2016
Propose: Create a simple network client to request remote server
Enviroment: C++ (VS 2008)
@author: kevin source from http://www.binarytides.com/code-tcp-socket-server-winsock/
*/

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<winsock2.h> //the header file to be included for winsock functions
using namespace std;

#pragma comment(lib,"ws2_32.lib") //Winsock Library
 
int main(int argc , char *argv[])
{
    WSADATA wsa; //hold additional information after winsock has been loaded
     
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) // start or initialise winsock library
    {
        printf("Failed. Error Code : %d",WSAGetLastError()); //get more information about what error happened
        return 1;
    }
     
    printf("Initialised.");
 
	/*
    Create a TCP socket
    */
	SOCKET s;
	// creates a socket and returns a socket descriptor which can be used in other network commands
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
 
    printf("Socket created.\n");

	/*
     Connect to remote server, www.google.com 
    */
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8887 );
 
    //Connect to remote server 
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
     
    puts("Connected");

	/*
     Send data to the remote server
	*/
    char *message;
    message = "GET / HTTP/1.1\r\n\r\n"; //The message is actually a http command to fetch the mainpage of a website.
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");

     /*
     Receive data from the remote server
	*/
	char server_reply[2000];
    int recv_size;
	if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }
     
    puts("Reply received\n");
 
    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts("server_reply");

	system("pause");
	closesocket(s);
    WSACleanup();
    return 0;
}

