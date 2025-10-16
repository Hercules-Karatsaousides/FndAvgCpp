# FndAvgCpp

A small C++ console program to help you compute the average of numbers.

It supports two modes:
- Option 1: Enter exactly five double-precision numbers and get their average.
- Option 2: Choose a custom count (2–100), enter that many numbers, and get their average.

The app prints a banner, uses ANSI colors for nicer terminal output, and sets the console code page to UTF‑8 so symbols render correctly on Windows.


## Platform and prerequisites
- Windows (the program calls `SetConsoleOutputCP`, `SetConsoleCP`, and uses `system("cls")`).
- CMake and a C++ compiler (e.g., MinGW/GCC as configured by CLion in this project).
- CLion is recommended but optional.


## Build (with CLion)
This repository already contains a simple CMake project with a single executable target: `FndAvgCpp`.

1. Open the project folder in CLion.
2. Ensure the "Debug" profile (or any configured profile) is selected.
3. Build the target `FndAvgCpp`.

CLion will produce the executable in your configured build directory (e.g., `cmake-build-debug/FndAvgCpp.exe`).


## Run
- From CLion: Run the `FndAvgCpp` target.
- From a terminal: navigate to your build directory and run `FndAvgCpp.exe`.


## Usage
On start, you will see a menu:

- Press `1` to enter five numbers. The program prints the sum and divides by 5.
- Press `2` to choose how many numbers you want to average (between 2 and 100). You will then enter each number one by one, and the program prints the sum and the average.
- Press any other key + Enter to exit.

Notes:
- The prompt that asks for the count (in option 2) validates input and will re-prompt on invalid values.
- Individual number entries are read as doubles using standard input; make sure to use a dot as decimal separator unless your locale is configured otherwise.
- The console is cleared between screens using `cls` (Windows only).


## Project layout
- `main.cpp` — program source.
- `CMakeLists.txt` — build configuration for CMake.


## Credits
Based on code that credits: Eraklis Karatsaousides (shown in the program banner).


## License
No license specified. If you intend to distribute or modify, consider adding a LICENSE file.