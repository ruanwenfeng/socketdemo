#include "xsocket.h"

//标准库头文件
#include <stdlib.h>




XSocket::XSocket() {
#ifdef _WINDOWS
	static bool flag = true;
	if (flag) { 
		WSADATA ws;
		WSAStartup(MAKEWORD(2, 2), &ws);
		flag = false;;
	}
#endif
}

SOCKET XSocket::createSocket() {
	mSocket = ::socket(AF_INET, SOCK_STREAM , 0);
	if (-1 == mSocket) {
		std::cout << "createSocket failed!" << std::endl;
	}
	return mSocket;
}

bool XSocket::listen(unsigned short port) {

	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = htonl(0);
	
	//绑定端口
	int ret = ::bind(mSocket, reinterpret_cast<sockaddr*>(&saddr), sizeof(saddr));
	if (0 != ret) {
		std::cout << "bind port " << port << " failed!" << std::endl;
		return false;
	}

	//监听端口
	std::cout << "bind port " << port << " success!" << std::endl;
	::listen(mSocket, port);

	return false;
}

XSocket XSocket::accept() {

	XSocket xsocket;

	sockaddr_in caddr;
	socklen_t len = sizeof(caddr);

	//accept
	SOCKET client = ::accept(mSocket, reinterpret_cast<sockaddr*>(&caddr), &len);
	if (0 > client) {
		std::cout << "accept failed" << std::endl;
		return xsocket;
	}


	xsocket.mIp = inet_ntoa(caddr.sin_addr);
	xsocket.mPort = ntohs(caddr.sin_port);
	xsocket.mSocket = client;
	std::cout << "accept client " << client << " !" << std::endl;
	std::cout << "client " << client << " ip is " << xsocket.mSocket
		<< ",port is " << xsocket.mPort << " !"
		<< std::endl;
	return xsocket;
}

int XSocket::recv(char * buf, int bufsize) {
	return ::recv(mSocket, buf, bufsize, 0);
}

int XSocket::send(const char * buf, int bufsize) {

	int sendSize = 0;
	while (sendSize != bufsize){
		int len = ::send(mSocket, buf + sendSize, bufsize - sendSize, 0);
		if (len < 0) {
			break;
		}
		sendSize += len;
	}

	return sendSize;
}

void XSocket::close() {
	if (0 < mSocket)
		::closesocket(mSocket);
}

XSocket::~XSocket() {
}
