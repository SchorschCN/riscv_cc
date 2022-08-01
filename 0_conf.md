# Environment Preparation for developing a RISC-V Compiler

## Prerequisites
1. gcc, g++ on host platform (with the same version)
2. following packages installed:
```bash
    $ sudo apt install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev #maybe libexpat1-dev
```
## Compile riscv-gnu-toolchain
1. clone toolchain repository
```bash
    $ git clone git@github.com:riscv-collab/riscv-gnu-toolchain.git # no need to add --recursive before clone 
    $ cd riscv-gnu-toolchain
    $ git rm qemu   #qemu configured later separately
```
2. configure and make
```bash
    $ mkdir build && cd build
    $ ../riscv-gnu-toolchain/configure --prefix=$YOUR_PREFIX
    $ make linux -j $(nproc)
```


## Compile qemu for RISC-V
1. clone qemu repository:
```bash
    git clone https://git.qemu.org/git/qemu.git
```
2. configure and make(only riscv64)
```bash
    cd qemu
    mkdir build && cd build
    ../configure --target-list=riscv64-linux-user,riscv64-softmmu --prefix=$YOUR_PREFIX
    make -j $(nproc)
    make install
```
## Set environment variables
```bash
    vi ~/.profile
    #Recommend adding path of toolchain and qemu before $PATH!
    PATH=$PATH_OF_TOOLCHAIN:$PATH_OF_QEMU:$PATH
    #save and quit
    source ~/.profile
```
1. If all prerequisites are done but riscv64-unknown-linux-gnu-gcc can't work with "execvp not found: no such ...", move path of toolchain and qemu before $PATH and source again
2. If qemu-riscv64 --version works, but can't run binaries, reporting:

    Could not open '/lib/ld-linux-riscv64-lp64d.so.1': No such file or directory

    This may be the result of wrong path of dynamic library. In my machine, ld-linux-riscv64-lp64d.so.1 is actually under /usr/riscv-linux-gnu/lib.

    use -L  to set the elf interpreter prefix to 'path', in my machine, that is qemu-riscv64 -L /usr/riscv-gnu-toolchain 
## References
1. https://gitee.com/aosp-riscv/working-group/blob/master/articles/20220721-riscv-gcc.md
2. https://github.com/riscvarchive/riscv-qemu/issues/151
3. https://blog.csdn.net/weixin_39871788/article/details/119698806
4. https://www.bilibili.com/video/BV1D54y1m78G?vd_source=bf8a6ac3b3c13db9ce6384cbbac5f823
    
