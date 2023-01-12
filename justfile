format:
    find . -type f -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
build:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. -GNinja && ninja && cd ..
debug:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. -GNinja && ninja && cd ..
compile:
    mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. -GNinja && ninja && cd ..
launch:
    just debug && clear && ./build/R-Type
valgrind:
    just build && valgrind --leak-check=full ./build/R-Type
tests:
    just debug && ./build/runTests
coverage:
    just tests && gcovr -r . --exclude "build/" --exclude "tests/"
clear:
    rm -rf build/