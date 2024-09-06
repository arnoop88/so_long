# so_long

**so_long** is a project that involves creating a simple 2D game using the MiniLibX library in C. The game requires the player to navigate a map, collect items, and reach the exit to win. This project helps understand basic graphics rendering, window management, and event handling in C.

## Features

- Render a game window using the MiniLibX library.
- Control a character using keyboard input.
- Collect collectibles scattered across the map.
- Reach the exit to complete the level.
- Supports different map sizes and designs, read from a `.ber` file.

## Getting Started

### Prerequisites

- MiniLibX library
- A Unix-based system (Linux or macOS)
- `gcc` compiler and `make`

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/arnoop88/so_long.git
   cd so_long
2. Compile the project:
   ```bash
   make
3. Run the game:

   To run the game, execute the program with a valid `.ber` map file:
   ```bash
   ./so_long maps/your_map.ber

## Controls

- `W`/ : Move Up
- `A`/ : Move Left
- `S`/ : Move Down
- `D`/ : Move Right
- `ESC`/`Q` : Exit the game

## Map file format

Maps should be stored in `.ber` format and meet specific criteria:
- Surrounded by walls
- Contains at least one collectible, one exit, and one starting position

Feel free to contribute, report issues, or suggest enhancements!
