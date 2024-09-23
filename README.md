# Ghostscript API Test

A simple program to use `ghostscript` from C++. Taken from the C examples in the [documentation](https://ghostscript.com/docs/9.55.0/API.htm#Example_usage).

### Dependencies
Requires the `gs` headers/shared object. To install them, either:

    sudo apt install libgs-dev

This will install the headers in `/usr/include/ghostscript` and the so file in `/usr/lib/libgs.so`.

Or build ghostscript from source (to get the latest version). Download from [here](https://ghostscript.com/releases/gsdnld.html) - make sure you choose __source__ and build:

    ./configure
    make so
    sudo make soinstall

    # optionally to build/install the gs executable as well
    sudo make install

This will install the headers in `/usr/local/include/ghostscript` and the so file in `/usr/local/lib/libgs.so`.

### Building
Use the IDE or:

    mkdir build && cd build
    cmake ..
    make

### Running
The PDF filename is hardcoded for now. In the `build` dir:

    ./ghostscript_api_test