#include <iostream>
#include <thread>
#include "xsocket.h"
int main(int arg, char*agrv[]) {

	XSocket server;
	server.listen(8888);
	while (true) {
		XSocket client = server.accept();
		std::thread sth([client]() {
			char buffer[1024];
			while (true) {
				int len = client.recv(buffer, _countof(buffer));
				if (0 > len) {
					break;
				}
				buffer[len] = '\0';
				if (0 == strcmp(buffer, "quit")) {
					char re[] = "quit success!\n";
					client.send(re, _countof(re));
					break;
				}
				int sendlen = client.send("ok\r\n", 4);
				std::cout << "recv " << buffer;
			}
			client.close();
		});
		sth.detach();
	}
	return 0;
}