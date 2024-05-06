[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/WybXpzNk)
# UnitTestPractice

## Getting Started

Prerequisites:
* Docker (\*nix) or Docker Desktop (Windows/Mac)
* \*nix-based Command Line Environment (i.e. WSL2 on Windows)

With Docker running, execute the following commands in order.

This will generate the container image. It needs to be run each time the
container configuration changes.

`docker build -t cpp-container .`

This will use the current code, attempt to build it, and run its tests
within the container. If you change the code (and not the container
configuration), you only need to repeat this command.

`docker run -v "$(pwd)":/usr/src -it cpp-container`

To run commands within the container interactively, use:

`docker run -v "$(pwd)":/usr/src -it cpp-container sh`

and then type commands (e.g. `make`, `./GuesserTest`, `gcov`, etc.) at the `#` prompt.