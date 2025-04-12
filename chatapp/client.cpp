#include <iostream>
#include <thread>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

const int BUFFER_SIZE = 1024;

void receiveMessages(SOCKET socket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        int bytes_received = recv(socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            std::cout << "Received: " << buffer << std::endl;
        } else if (bytes_received == 0) {
            std::cout << "Server disconnected." << std::endl;
            break;
        } else {
            std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
            break;
        }
    }
}

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    SOCKET client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket == INVALID_SOCKET) {
        std::cerr << "Socket creation error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    server_address.sin_port = htons(12345);

    if (connect(client_socket, (sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        std::cerr << "Connect failed: " << WSAGetLastError() << std::endl;
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    std::thread(receiveMessages, client_socket).detach();

    std::string message;
    while (true) {
        std::getline(std::cin, message);
        int bytes_sent = send(client_socket, message.c_str(), message.length(), 0);
        if (bytes_sent == SOCKET_ERROR) {
            std::cerr << "send failed with error: " << WSAGetLastError() << std::endl;
            break;
        }
    }

    closesocket(client_socket);
    WSACleanup();
    return 0;
}
