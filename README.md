# `Tower-of-Hanoi` Visualized Solution

The **Tower-of-Hanoi** is a classic mathematical puzzle, and this C++ command-line application elegantly solves it while providing a dynamic visual representation of the moving disks on the Windows console. It calculates the optimal moves using an iterative algorithm and custom stack data structures, visually tracking the puzzle state in real-time.

![Tower of Hanoi Visualization](Tower_of_Hanoi%20(1).gif)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Notes](#notes)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

The Tower of Hanoi is a puzzle consisting of three rods and a number of disks of various diameters. The objective is to move the entire stack to another rod, obeying strict rules. Unlike typical recursive solutions, this project uses an efficient **iterative algorithm** paired with custom `Stack` classes to find the exact sequence of moves. It utilizes the Windows Console API to output a real-time visualization of the disks shifting.

## Features

- **Iterative Logic**: Implements an iterative approach to solve the Tower of Hanoi problem, determining the next valid move mathematically without recursion.
- **Custom Stack Implementation**: Manages the state of the three rods using a custom-built, object-oriented `Stack` class.
- **Console Visualization**: Graphically outputs the rods and disks moving in real-time in the terminal window.
- **Customizable**: Handles different amounts of disks natively based on user input.
- **Windows API Integration**: Uses standard Windows handlers (`<windows.h>`) to clear screen components and format ASCII art smoothly.

## Getting Started

To run the **Tower-of-Hanoi** locally, follow these steps:

1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler for Windows (e.g., MSVC or MinGW g++):
   ```bash
   g++ "Tower Of Hanoi.cpp" -o TowerHanoi
   ```
3. Run the compiled executable:
   ```bash
   ./TowerHanoi
   ```

Make sure you have a Windows environment, as the visualization uses `<windows.h>` specific functions like `Sleep()`.

## Usage

1. Launch the compiled executable.
2. The application will prompt you to enter the number of rings.
3. Once entered, it will initialize the disks on the starting rod.
4. It will automatically begin solving the puzzle iteratively, drawing the current state of the rods until the disks are successfully transferred to the target rod.

## Notes

- This program uses `<windows.h>` and ANSI escape sequences to clear and update the terminal efficiently. It may not compile or render properly on Linux or macOS systems without modifications.
- The total number of moves will be $2^n - 1$. Entering a very large number of disks will result in a lengthy visualization.

## Contributing

Contributions are welcome! If you find any issues, want to add cross-platform support, or have suggestions for improvements, feel free to create a pull request.

## License

*This project is licensed under the [MIT License](https://choosealicense.com/licenses/mit/)*.

## Contact

For any questions or inquiries, please contact [aliwahaj393](https://github.com/aliwahaj393).
