#pragma once

#ifndef WINVER
	#define WINVER 0x0500
#endif

#include <windows.h>
#include <winsock.h>

#define IP INADDR_ANY
#define PORT 8888

enum NET_COMMANDS {
	CONNECT,
	KEYS,
};

struct packet {
	unsigned char command;
	
	unsigned int keys;
	
	struct {
		short x;
		short y;
	} cstick;
	
	struct {
		unsigned short x;
		unsigned short y;
	} touch;
};

extern SOCKET listener;
extern SOCKET client;

extern struct sockaddr_in client_in;

extern int sockaddr_in_sizePtr;

extern char buffer[sizeof(struct packet)];
extern char hostName[80];

void initNetwork(void);
void startListening(void);
void sendBuffer(int length);
int receiveBuffer(int length);
