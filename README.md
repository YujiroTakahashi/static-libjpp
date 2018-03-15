# static-libjpp
Using Juman++ V2 from C++

## Building from a Juman++

Download the package from [Releases](https://github.com/ku-nlp/jumanpp/releases)

```bash
$ tar xf jumanpp-<version>.tar.xz # decompress the package
$ cd jumanpp-<version> # move into the directory
$ mkdir build # make a subdirectory for build
$ cd build
$ cmake .. 
$ sudo make install
```

## Create a libjpp
```bash
$ git clone https://github.com/YujiroTakahashi/static-libjpp.git
$ cd static-libjpp/lib
$ ./build.sh
```

## Copy the Include files
```bash
$ git clone https://github.com/YujiroTakahashi/static-libjpp.git
$ cd static-libjpp/include/jumanpp
$ ./copy.sh
```
