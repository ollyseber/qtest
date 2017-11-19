# qtest
qtest is a small test framework library for C. It provides methods for creating a suite of unit 
tests which in turn contain a set of testcases.

## Building
The project is currently configured with [cmake](https://cmake.org/). To build, navigate to the
directory you would like to build to (ie. `/build/`), and run cmake, pointing to the qtest repo.

### Example
This example assumes cmake is available on the command line:
```
> cd path/to/qtest-repo
> mkdir build && cd build
> cmake ../
```