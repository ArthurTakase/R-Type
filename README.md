# R-TYPE

Implementation of a multithreaded server and a graphical client for a game called R-Type, using an engine of our own design.

## Team

* Arthur Decaen (arthur.decaen@epitech.eu)
* Corentin Roy (corentin.roy@epitech.eu)
* Solène Lefeu (solene.lefeu@epitech.eu)
* Guillaume Vernizeau (guillaume.vernizeau@epitech.eu)
* Geoffrey Labruyère (geoffrey.labruyere@epitech.eu)

## Usage

### Linux

* Build

    ```bash
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. -GNinja && ninja && cd ..
    ```

* Launch Client

    ```bash
    cd build && ./r-type_client 
    ```

    or

    ```bash
    cd build && ./r-type_client [server port] [server ip] [client port]
    ```

* Launch Server

    ```bash
    cd build && ./r-type_server
    ```

### Window

* Compile with Cmake GUI
* Use Visual Studio
* Launch .exe (r-type_client.exe and r-type_server.exe)

## Dev Infos

### ECS

![ECS](docs/ECS.png)

### Commit norm

Exemples :

* **ADD:** good ECS
* **FIX:** no collision on same entity
* **UP:** remove useless print

| Name | Explanation                                                            |
| ---- | ---------------------------------------------------------------------- |
| ADD  | If you add files, features...                                          |
| FIX  | If you were working on a bug or any form of default that you corrected |
| DEL  | If you removed files, features...                                      |
| UP   | If you change something without adding any features or content         |

### CI/CD

* Automatic build on main and dev branches.
* Running Google Test unit tests on main and dev branches.
* Generating coverage on main and dev branches.
* Automatic generation of Doxygen documentation on main and dev branches accessible here.
* Sending a discord message on push/merge on all branches.

### Doxygen

For proper documentation generation, please put comments above your functions using the following format.

```cpp
/**
 * @brief Description of the function's behavior
 * 
 * @param parameter1 description of the parameter
 * @param parameter2 description of the parameter
 * 
 * @return explanation of the return value
 */
```

### Google Test

Every function must have at least one unit test. The tests work with Google Test, documentation is here.
