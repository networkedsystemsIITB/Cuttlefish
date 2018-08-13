#ifndef UTILS_H
#define UTILS_H
#include <fcntl.h>
#include "utils.h"
#endif

class Client{
public:
	int tID;
	int client_socket;
        char client_buffer[BUFFER_SIZE];
        char write_client_buffer[BUFFER_SIZE];
	char write_client_byte_buffer[BUFFER_SIZE];
	int sock_raw; //To receive raw packets
	int saddr_size , data_size;
	struct sockaddr saddr;
	// Byte array in C++
	unsigned char client_byte_buffer[BUFFER_SIZE];	

	int server_port;
	const char *server_address;
	struct sockaddr_in server_sock_addr;
	struct sockaddr_in source,dest;
	//bool flag=false; //flag to test the right dest IP for rcv data 
	bool tflag=false; //flag to test dest UDP port for demux of packets
	

	// Constructor
	Client(int);

	// Socket methods
	void input_server_details(int,const char*);
	void read_data();
	void write_data(string);
	void read_byte();
	void write_byte();

	int sendUEData(int, string, string, int, int, int, string, size_t);

	// Utility functions
	string GetStdoutFromCommand(string cmd);
	string runIperfCommand(string cmd,string srcIp);	

	//Raw packet functions

	int ProcessPacket(unsigned char* , int);
	void print_ip_header(unsigned char* , int);
	//void print_tcp_packet(unsigned char * , int );
	void print_udp_packet(unsigned char * , int );
	//void print_icmp_packet(unsigned char* , int );
	//void PrintData (unsigned char* , int);
	//void PrintDataPayload (unsigned char* , int);
	//void print_ethernet_header(unsigned char*, int);

	// Destructor
	~Client();		
};
