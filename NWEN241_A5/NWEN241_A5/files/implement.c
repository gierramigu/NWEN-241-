#include "header.h"

int loadFile(const char* in){

  movies = (mov*) calloc(25, sizeof(mov)); //allocate memory for 25 records 

  FILE *csv;
  csv = fopen(in, "r");

  //checks for worse case
  if(csv == NULL || !csv){
    printf("Failed to load file\n");
    return 0;
  }

   int i = 0;
   while (!feof(csv) && i < 25){ //going through 25 records
           fscanf(csv, "%lu,%[^,],%hd,%[^\n]%*c", movies[i].title, movies[i].director, &movies[i].year, &movies[i].oscar, movies[i].country); 
           i++;
    }

  //close
  fclose(csv);
  return 1;

}



int main() {

	loadFile("scifi.csv");
	char sendMsg[DEFAULT_STRLEN] = "sup g\n";
	char buffer[DEFAULT_STRLEN];
	char clientMsg[DEFAULT_STRLEN];
	int sockfd, bindret, rowNum; 

	ssize_t sen, rec;

	/*creating the socket*/
    //Note: Socket is an end connection point for communication
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 

	if(sockfd == -1){ //same as < 0 
		printf("Error: Unable to open socket\n");
		exit(0); //it just quits
	}

	//define server address
	struct sockaddr_in serv_addr; 
	serv_addr.sin_family = AF_INET; //IPv4
	serv_addr.sin_addr.s_addr = INADDR_ANY; // any address
	serv_addr.sin_port = htons(12354); // defined port in the header file

	//binding the socket which means reserving a port number for use by the socket 
	bindret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if( bindret < 0){
		printf("Error: Unable to bind socket\n");
		exit(0);
	} 

	//connect the socket to the address of the server using connect() sys call
	// if(connect(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr))< 0){
	// 	printf("Error: Unable to connect\n");
	// 	exit(0);
	// }

	//listen() system call: listens for connections 
	//SOMAXCONN: the maximum connections that the server can handle at a time
	if(listen(sockfd, SOMAXCONN) < 0){
		printf("Error listening for connections\n");
		exit(0);
	}

	//define client adrress for accept() system call
	struct sockaddr_in client_addr; 
	socklen_t clientLen; 
	
	clientLen = sizeof(client_addr);
	
	//accept() system call: accept a connection from the server
	int client_fd = accept(sockfd, (struct sockaddr*) &client_addr, (socklen_t*) &clientLen);
	if(client_fd < 0){
		printf("Error: Unable to accept\n");
		exit(0);
	}


	/*sending and recieving data*/

	//send: send a message to a client once the connection has been made 
	//send() used for TCP and sendto() used for UDP 
	sen = send(client_fd, sendMsg, strlen(sendMsg), 0 );
	if(sen < 0){
		printf("Error: Unable to write to socket\n");
		close(client_fd); //stops anything anymore from being sent to the client
		exit(0);
	}

	while(1){ //while it is true

	int rowNum = 0;

	/*resetting the buffer*/
	memset(clientMsg,0, DEFAULT_STRLEN); //everytime the client sends a message it will be a new one 

	//receive: accepts the messsage from the client 
	//char incoming[100]; 
	rec = recv(client_fd, clientMsg, DEFAULT_STRLEN, 0);
	if(rec <=0 ){
		printf("Error recieving message");
		close(client_fd);
		exit(0);
	}
	sscanf(clientMsg,"%s %d",buffer, &rowNum);

	//Print the receiving message from the client
	printf("Recieved message: %s", clientMsg);


    if (strcasecmp("BYE", buffer) == 0){ //case sensitive 
        printf("Port Closed\n");
        close(cSocket);
        exit(0);
    } else if (strcasecmp("GET",buffer) == 0){ //case sensitive 
    	char row[DEFAULT_STRLEN];
    	char year[40];
    	char oscar[40];

    	if(rowNum > 0 && rowNum < 26 ){

    	//casting the integer into string 
    	sprintf(year, "%d", movies[rowNum - 1].year);
    	sprintf(oscar, "%d", movies[rowNum - 1].oscar);

    	//concatenate as one string 
    	snprintf(row, DEFAULT_STRLEN, "Title: %s Direction: %s Oscar: %s Country: %s\n", movies[rowNum -1].title,
    		movies[rowNum - 1].director, year, oscar, movies[rowNum - 1].country);
    	ssize_t s = send(client_fd, row, strlen(row), 0);
    	}
    	else {
    		int i = 0; 
    		while(i < 25){
    		//casting the integer into string 
	    	sprintf(year, "%d", movies[i].year);
	    	sprintf(oscar, "%d", movies[i].oscar);

	    	snprintf(row, DEFAULT_STRLEN,"Title: %s Direction: %s Oscar: %s Country: %s\n", movies[i].title, movies[i].director,
	    		year,oscar, movies[i].country);
	    	ssize_t s = send(client_fd, row, strlen(row), 0);
	    	i++;
    		}
    	}

    }



	// ssize_t shut = shutdown(client_fd, int how);
	// if(shut  <= 0){
	// 	printf("Shutdown error"); 
	// 	close(client_fd);
	// 	exit(0);
	// }


	}
	close(sockfd);
	// if (close(sockfd) < 0){
	// 	fprintf(stderr, "Error closing socket.\n");
	// 	exit(0);
	// }

	return 0;

 }