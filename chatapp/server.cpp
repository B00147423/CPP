#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include <algorithm>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

const int PORT = 12345;
const int BUFFER_SIZE = 1024;

std::vector<SOCKET> clients;
std::mutex clients_mutex;

void broadcastMessage(const std::string& message, SOCKET sender) {
    std::lock_guard<std::mutex> guard(clients_mutex);
    for (SOCKET client : clients) {
        if (client != sender) {
            int bytes_sent = send(client, message.c_str(), message.length(), 0);
            if (bytes_sent == SOCKET_ERROR) {
                std::cerr << "Error sending message to client: " << WSAGetLastError() << std::endl;
            } else {
                std::cout << "Sent to client " << client << ": " << message << std::endl;
            }
        }
    }
}

void handleClient(SOCKET client_socket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                std::cout << "Client disconnected." << std::endl;
            } else {
                std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
            }
            closesocket(client_socket);
            {
                std::lock_guard<std::mutex> guard(clients_mutex);
                clients.erase(std::remove(clients.begin(), clients.end(), client_socket), clients.end());
            }
            break;
        }
        buffer[bytes_received] = '\0';
        std::string message = buffer;
        std::cout << "Received from client " << client_socket << ": " << message << std::endl;
        broadcastMessage(message, client_socket);
    }
}

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "Socket creation error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    while (true) {
        SOCKET client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket == INVALID_SOCKET) {
            std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
            closesocket(server_socket);
            WSACleanup();
            return 1;
        }

        {
            std::lock_guard<std::mutex> guard(clients_mutex);
            clients.push_back(client_socket);
        }

        std::thread(handleClient, client_socket).detach();
    }

    closesocket(server_socket);
    WSACleanup();
    return 0;
}
