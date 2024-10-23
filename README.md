<img alt="Abnormal Day logo" src="data/tr1/logo.png"/>

This is a mod for Tomb Raider (1996)  
Powered by [TRIX](https://github.com/LostArtefacts/TRX) engine

## Compiling
### For windows

1) Install [msys2](https://www.msys2.org/)
2) Download [ffmpeg-6.1.2.tar.xz](https://www.ffmpeg.org/releases/ffmpeg-6.1.2.tar.xz) archive
3) Extract it to `C:\Users\<username>\ffmpeg-src\`
4) Download [libbacktrace-master.zip](https://github.com/ianlancetaylor/libbacktrace/archive/refs/heads/master.zip) archive
5) Extract it to `C:\Users\<username>\libbacktrace-src\`
6) Run `msys2 mingw32` terminal
7) Update `msys2` core packages
```
$ pacman -Suy
```
Package manager will prompt you to proceed, confirm

In some cases, certain core packages will get updated and package manager will prompt you to close all terminals, confirm

8) Run `msys2 mingw32` terminal again
9) Update `msys2` base packages
 ```
$ pacman -Suy
```
10) Install required `msys2` packages
```
$ pacman -S mingw-w64-i686-gcc git mingw-w64-i686-ca-certificates mingw-w64-i686-python-pip mingw-w64-i686-meson make mingw-w64-i686-diffutils mingw-w64-i686-yasm mingw-w64-i686-SDL2 mingw-w64-i686-pcre2
```
11) Install required `python` packages
```
$ pip install pyjson5
```
12) Configure `ffmpeg` build script
```
$ cd /c/Users/<username>/ffmpeg-src/
$ ./configure --prefix=/mingw32 --enable-gpl --enable-decoder=pcx --enable-decoder=png --enable-decoder=gif --enable-decoder=mjpeg --enable-decoder=mpeg4 --enable-decoder=mdec --enable-decoder=mp3 --enable-decoder=h264 --enable-decoder=h264_qsv --enable-decoder=libopenh264 --enable-demuxer=mov --enable-demuxer=mp3 --enable-demuxer=avi --enable-demuxer=h264 --enable-demuxer=str --enable-demuxer=image2 --enable-parser=mpegaudio --enable-zlib --enable-small --disable-debug --disable-ffplay --disable-ffprobe --disable-doc --disable-network --disable-htmlpages --disable-manpages --disable-podpages --disable-txtpages --disable-asm
```
13) Build `ffmpeg`
```
$ make
```
14) Install `ffmpeg`
```
$ make install
```
15) Configure `libbacktrace` build script
```
$ cd /c/Users/<username>/libbactrace-src/
$ ./configure --prefix=/mingw32
```
16) Build `libbacktrace`
```
$ make
```
17) Install `libbacktrace`
```
$ make install
```
18) Clone the repository
```
$ cd /c/Users/<username>/
$ git clone https://github.com/izarif/abnormal_day --recursive
```
19) Copy `C:\Users\<username>\abnormal_day\src\libtrx\` directory to `C:\Users\<username>\abnormal_day\src\tr1\subprojects\libtrx\`
20) Copy `C:\Users\<username>\abnormal_day\tools\shared\` directory to `C:\Users\<username>\abnormal_day\tools\tr1\shared\`
21) Configure `abnormal_day` build script
```
$ cd /c/Users/<username>/abnormal_day/src/tr1/
$ meson build
```
22) Build `abnormal_day`
```
$ cd build
$ meson compile
```

## License

This project is licensed under the GNU General Public License - see the
[COPYING.md](COPYING.md) file for details.