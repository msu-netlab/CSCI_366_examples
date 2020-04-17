// example adapted from https://www.geeksforgeeks.org/socket-programming-cc/

/**
 * Echo server that accepts a TCP connection and replies with whatever the client sends
 */

#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#define PORT 8080          // to run without root permissions, we need a port number above 1024

int main(int argc, char const *argv[])
{
   // Create socket file descriptor
   // AF_INET - IP socket
   // SOCK_STREAM - TCP socket
   // protocol = 0 - IP protocol
   int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
   if(listen_sock == 0){
      perror("Opening a listening socket failed");
      exit(EXIT_FAILURE);
   }

   // Enable forceful attach to address and port
   // This is optional, but will prevent errors such as "address already in use"
   int opt = 1; // set the options to true
   if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
      perror("Setting socket options failed");
      exit(EXIT_FAILURE);
   }

   // Bind the socket to an address and port
   struct sockaddr_in address;
   address.sin_family = AF_INET;          // using an IP address
   address.sin_addr.s_addr = INADDR_ANY;  // accepting connections from any IP
   address.sin_port = htons( PORT );      // accepting connection to PORT
   if(bind(listen_sock, (struct sockaddr *)&address, sizeof(address)) < 0){
      perror("Binding the socket failed");
      exit(EXIT_FAILURE);
   }

   // Listen for a new connection
   // Listen will block until a client tries to connect
   if (listen(listen_sock, 3) < 0){
      perror("Failure during listen");
      exit(EXIT_FAILURE);
   }

   // Accept a connection from client and creating a new socket for that connection
   int addrlen = sizeof(address);
   int conn_sock = accept(listen_sock, (struct sockaddr *)&address, (socklen_t*)&addrlen);
   if(conn_sock < 0){
      perror("Failure accepting a connection");
      exit(EXIT_FAILURE);
   }

   // Read data from client
   char buffer[1024] = {0}; //set up a buffer of memory into which we can read data
   int bytes_read = read(conn_sock , buffer, sizeof(buffer)); //read up to the number of bytes in buffer
   printf("Number of bytes received from client: %d\n", bytes_read);
   printf("Message from client: %s\n", buffer);


   // todo: Be careful when sending replies. The server has no guarantee that what it received from client is zero terminated (ends in \n). Below we are using strlen function to determine how many bytes should be sent. For strlen to work correctly, the data in the buffer needs to be zero terminated. When sending binary data, you can simply specify the length of the buffer in the send function.

   // Send the message back to the client
   send(conn_sock , buffer , strlen(buffer) , 0 ); // not using flags https://linux.die.net/man/2/send
   printf("Echo sent to client\n");

   return 0;
}
