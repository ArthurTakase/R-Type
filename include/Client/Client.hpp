#ifndef CLIENT_H_
#define CLIENT_H_

#include <arpa/inet.h>
#include <sys/socket.h>

class Client
{
  public:
    //! Default constructor
    Client(int port);

    //! Copy constructor
    Client(const Client& other) = delete;

    //! Move constructor
    Client(Client&& other) noexcept = default;

    //! Destructor
    virtual ~Client() noexcept = default;

    //! Copy assignment operator
    Client& operator=(const Client& other) = delete;

    //! Move assignment operator
    Client& operator=(Client&& other) noexcept = default;

  protected:
  private:
};

#endif // CLIENT_H_
