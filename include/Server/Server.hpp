#ifndef SERVER_H_
#define SERVER_H_

class Server
{
  public:
    //! Default constructor
    Server();

    //! Copy constructor
    Server(const Server& other) = delete;

    //! Move constructor
    Server(Server&& other) noexcept = default;

    //! Destructor
    virtual ~Server() noexcept = default;

    //! Copy assignment operator
    Server& operator=(const Server& other) = delete;

    //! Move assignment operator
    Server& operator=(Server&& other) noexcept = default;

  protected:
  private:
};

#endif // SERVER_H_
