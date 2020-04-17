// example adapted from https://www.geeksforgeeks.org/socket-programming-cc/

/**
 * Echo client that sets up a TCP connection, sends a message, and prints out a reply
 */

#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <string>

#define ADDRESS "127.0.0.1"  // the client needs to know the IP address of the server
                             // here the address of the local host
#define PORT 8080            // the client needs to know on what port the server is listening on

int main(int argc, char const *argv[])
{


   // Create socket file descriptor
   // AF_INET - IP socket
   // SOCK_STREAM - TCP socket
   // protocol = 0 - IP protocol
   int sock = socket(AF_INET, SOCK_STREAM, 0);
   if(sock < 0){
      printf("Socket creation failed");
      return EXIT_FAILURE;
   }

   // Set up an address for the connection to the server
   struct sockaddr_in address;
   address.sin_family = AF_INET;
   address.sin_port = htons(PORT);
   // Convert IPv4 and IPv6 addresses from text to binary form
   if(inet_pton(AF_INET, ADDRESS, &address.sin_addr) <= 0){
      printf("Invalid address or address not supported");
      return EXIT_FAILURE;
   }

   // Connect to the server
   if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0){
      printf("Connection failed");
      return EXIT_FAILURE;
   }

   // Send data to server
   std::string msg = "Hello from client";
   send(sock , msg.c_str() , msg.length(), 0 ); // not using flags https://linux.die.net/man/2/send
   printf("Sending: %s\n", msg.c_str());

   // Get reply from server
   char buffer[1024] = {0}; //set up a buffer of memory into which we can read data
   int bytes_read = read( sock , buffer, sizeof(buffer)); //read up to the number of bytes in buffer
   printf("Number of bytes received from server: %d\n", bytes_read);
   printf("Echo from server: %s\n", buffer );
   return 0;
}


