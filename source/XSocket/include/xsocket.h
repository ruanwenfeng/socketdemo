#ifndef XSOCKET_H
#define XSOCKET_H

//��׼��ͷ�ļ�
#include <iostream>


//windowsͷ�ļ�
#ifdef _WINDOWS

#include <Windows.h>
typedef int socklen_t;




#    ifdef XSOCKET_EXPORTS
/* We are building this library */
#      define XSOCKET_EXPORT __declspec(dllexport)
#    else
/* We are using this library */
#      define XSOCKET_EXPORT __declspec(dllimport)
#    endif

#endif






class XSOCKET_EXPORT XSocket {

public:
	XSocket();
	SOCKET createSocket();
	bool listen(unsigned short port);
	XSocket accept();
	int recv(char * buf, int bufsize);
	int send(const char * buf, int bufsize);
	void close();
	~XSocket();

public:
	SOCKET mSocket = 0;
	unsigned short mPort = 0;
	char* mIp;
};


#endif // !XSOCKET_H
