#ifndef XSOCKET_H
#define XSOCKET_H

//标准库头文件
#include <iostream>


//windows头文件
#ifdef _WINDOWS

#include <Windows.h>
typedef int socklen_t;

#    ifdef XSOCKET_EXPORTS
/* We are building this library */
#      define XSOCKET_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define XSOCKET_EXPORT /*__declspec(dllimport)*/
#    endif

#endif






class XSOCKET_EXPORT XSocket {

public:
	XSocket();
	SOCKET createSocket();
	bool listen(unsigned short port);
	XSocket accept();
	int recv(char * buf, int bufsize) const;
	int send(const char * buf, int bufsize) const;
	bool connect(const char *ip, unsigned short port);
	void close() const;
	~XSocket();

public:
	SOCKET mSocket = 0;
	unsigned short mPort = 0;
	char* mIp;
};


#endif // !XSOCKET_H
