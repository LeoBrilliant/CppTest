# build
```sh
# boost1.63 
$ sudo apt install boost1.63-all-dev

# google test
$ sudo apt install libgtest-dev
$ sudo apt install cmake
$ cd /usr/src/googletest/googletest
$ sudo mkdir mybuild && cd mybuild
$ sudo cmake ../
$ sudo make
$ sudo install libgtest.a /usr/lib
```