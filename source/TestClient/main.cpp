#include <iostream>
#include <thread>
#include "xsocket.h"
int main(int arg, char*agrv[]) {

	XSocket client;
	client.connect("192.168.5.2", 8888);
	return 0;
}