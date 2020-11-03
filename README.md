# Lazymake
Compile and run your simple C/C++ projects with a single command without needing a Makefile.<br/>
Currently the project only works with g++ on MacOS and Linux.

Installation
------------

``` bash
$ git clone https://github.com/derinozon/lazymake.git
$ cd lazymake
$ make
$ make install
```
(You might need to use sudo in `make install` process)

Usage
--------

This program has two optional arguments :

- `path`: Specify a path to compile
- `version`: Choose compiler version

``` bash
$ lazymake path/to/your/project 17
```

Version arguments usage :
- `11`: -std=c++11
- `14`: -std=c++14
- `17`: -std=c++17
- `2a`: -std=c++2a
