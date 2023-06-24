# Fourier-Series-and-SFML
## sfml-vscode-boilerplate

I used andrew r king's sfml boilerplate to work with SFML and visual studio code:
https://github.com/andrew-r-king/sfml-vscode-boilerplate

## The repo
### Description

This repository allows playing around with the Fourier Series.
I wrote the code with the help of the coding train video about Fourier Series:
https://www.youtube.com/watch?v=Mm2eYfj0SgA&t=1373s

### Build instructions

SFML and make are required. You can use the `build.sh` script according to the following commands :

```bash
./build.sh build [Debug, Release]    # build upon current work
./build.sh rebuild [Debug, Release]  # clean current work and buld from scratch
./build.sh buildrun [Debug, Release] # build and run the program
./build.sh run [Debug, Release]      # run the program
```