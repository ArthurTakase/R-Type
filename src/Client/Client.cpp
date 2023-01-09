#include "Client.hpp"

Client::Client(int port)
{
    sockaddr_in addr;
    int         sckt     = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port        = htons(port);
    addr.sin_family      = AF_INET;
    int res              = bind(sckt, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
}
