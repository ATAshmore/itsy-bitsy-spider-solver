# itsy-bitsy-spider-solver

This repository contains a C++ program to solve the "Itsy Bitsy Spider" maze problem, which is part of COT 4400's Project 3 for Fall 2022. The objective of this project is to model a maze as a graph and utilize a known graph algorithm to find a path from the entrance to the exit of the maze. Below, you will find information on how to compile and run the program.

## Problem Description

The "Itsy Bitsy Spider" maze problem involves helping a spider find its way through a complex maze. The maze consists of multiple levels, each containing a grid of cells. The spider can move in various directions (north, east, south, west, up, or down) depending on the configuration of each cell. The goal is to find a path from the entrance at Level E to the water spout at Level A.

## Repository Contents

- **main.cpp**: The C++ source code that reads the maze input, models it as a graph, and finds a path for the spider.
- **input.txt**: An example input file with maze configurations.
- **output.txt**: The output file where the program writes the solution path.
- **README.md**: This file, providing instructions on compiling and running the program.

## Compilation and Execution

To compile and run the Itsy Bitsy Spider Maze Solver, follow these steps:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your-username/Itsy-Bitsy-Spider-Maze-Solver.git
   ```

   Replace `your-username` with your GitHub username.

2. **Navigate to the Project Directory:**

   ```bash
   cd Itsy-Bitsy-Spider-Maze-Solver
   ```

3. **Compile the Code:**

   Use the g++ compiler to compile the program:

   ```bash
   g++ main.cpp -o spider_solver
   ```

4. **Create or Modify the Input File:**

   You can create your own input file in the same directory as `input.txt` or modify the existing one following the provided format.

5. **Run the Program:**

   Execute the program by running:

   ```bash
   ./spider_solver
   ```

6. **View the Solution:**

   The program will calculate a path through the maze and display it on the console. Additionally, it will save the solution to the `output.txt` file.

7. **Check the Output:**

   Open the `output.txt` file to view the spider's path through the maze.
