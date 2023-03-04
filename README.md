# {EPITECH} | Third year | Network | OOP | R-Type

## About the project

This project aims to recreate the cross-platform video game R-Type with an online mutiplayer mode.
It required the implementation of a multithreaded server and a graphical client, using an engine of our own design.

- `Tools:`
    - Project made in `C++` version 20
    - use of the `SFML` graphical library to display game elements
    - Compiled with `CMake`, minimum version required : `3.17`
    - `Google Test` for unit tests
    - `Doxygen` for documentation
    - A `justfile` is provided to compile, run and test the project


- `Some of the features we implemented:`
    - A multithreaded server, to handle communication and game logic at the same time
    - A graphical client, to display the game and handle user input
    - A generic Entity Component System architecture and game engine
    - A encapsulated implementation of a UDP socket, compatible with Linux and Windows
    - A client-server communication UDP protocol

For further details about the implementation of these notions, you can click [here](https://arthurtakase.github.io/R-Type/) to be redirected to our documentation.

## Usage for Linux users

### Build
- Debug mode: `just debug`
- Release mode: `just build`

Be careful, if you want to use the `justfile`, you need to install [just](https://just.systems/man/en/), you can do it with the following command:
```bash
    cargo install just
```

### Run

/!\ If you want your game to launch, you need to have one server and at least one client running.

- Launch a client:

```bash
    cd build && ./r-type_client
```
or
```bash
    cd build && ./r-type_client [server port] [server ip] [client port]
```

- Launch the server:

```bash
    cd build && ./r-type_server
```

## Usage for Windows users

* Compile with `Cmake GUI`
* Use Visual Studio
* Launch .exe `r-type_client.exe` and `r-type_server.exe`

## Continuous integration/Continuous Deployment

* Automatic build on `main` and `develop` branches.
* Running Google Test unit tests on `main` and `develop` branches.
* Generating coverage on `main` and `develop` branches.
* Automatic generation of Doxygen documentation on `main` and `develop` branches accessible [here](!!!!!!d;q:d;q!d).
* Sending a discord message on push/merge on all branches.

## Highlights:

- ECS architecture graph : [documentation](docs/ECS.md)
- Client protocol graph : [documentation](docs/ClientProtocol.md)
- Server protocol graph : [documentation](docs/ServerProtocol.md)

Our complete documentation can be found [here](https://arthurtakase.github.io/R-Type/).

## Contributors

* [Arthur D.](https://github.com/ArthurTakase)
* [Corentin R.](https://github.com/roy-corentin)
* [Solène L.](https://github.com/slefeu)
* [Geoffrey L.](https://github.com/GeoffreyLabruyere)
* [Guillaume V.](https://github.com/GuillaumeVernizeau)

Want to become a contributor ? Check out our [Contributor's guide](docs/Contributor.md) !