# Tetris Clone in C++

## Overview

This project represents a work-in-progress implementation of the classic Tetris game, built from the ground up in C++. It showcases a strong foundation in object-oriented design, game logic implementation, and event-driven programming. While still under active development, the core mechanics of grid management and dynamic piece manipulation have been established. This project demonstrates a commitment to building robust and engaging interactive applications.

## Key Features (Currently Implemented)

* **Modular C++ Architecture:** The codebase is structured around well-defined classes (`Cell`, `Grid`, `TetrisPiece`) promoting code reusability, maintainability, and a clear separation of concerns.
* **Dynamic Piece Generation and Control:** Currently implements the generation and full control of the "L" shaped Tetris piece (`LPiece`). This includes movement (left, right, down) and rotation, demonstrating core game interaction logic.
* **Grid Management:** The `Grid` class effectively manages the game board, handling cell states and piece placement within the grid boundaries.
* **Event-Driven Input Handling:** Utilizes an `EventHandler` system to process user input, enabling real-time control over the active Tetris piece.

## Planned Features (Under Development)

The following features are planned for future implementation:

* **Full Suite of Tetris Pieces:** Implementation of all seven classic Tetris shapes (I, O, T, S, Z, J, L).
* **Scoring System:** Development of a scoring mechanism based on lines cleared.
* **Hold Functionality:** Implementation of the ability to hold a piece and swap it with the currently active piece.
* **Classic Tetris Mechanics:** Inclusion of standard Tetris gameplay elements such as line clearing, game over conditions, and potentially increasing game speed.

## Technical Highlights

* **Language:** C++
* **Libraries:** SFML
* **Key Classes:** `Cell`, `Grid`, `TetrisPiece`, `LPiece`, `EventHandler`
* **Design Principles:** Object-Oriented Programming (OOP), Event-Driven Architecture

## Project Status

This project is currently in active development. The fundamental game loop and core piece manipulation are functional. Future updates will focus on expanding the variety of pieces, implementing scoring, and refining the overall gameplay experience to match the classic Tetris game.

## Demonstration

If you would like to run this project on your owm machine, you can build it with cmake. Keep in mind that if you are running linux, other dependencies may be required since I am using the SFML library. You can reference the required dependencies at the following URL: https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/

## Contact

* **Email:** crapocolton@gmail.com
