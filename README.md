# so_long

## Description
**so_long** is a 42 project that involves creating a small 2D game using the **MiniLibX** graphics library. The goal is to move a character through a simple map while collecting collectibles and reaching an exit.

## Features
- **Player Movement**: Move the character using arrow keys or WASD.
- **Collectibles**: The player must collect all items before exiting.
- **Exit Condition**: The game ends when all collectibles are gathered and the player reaches the exit.
- **Map Validation**: The game ensures that the map follows the correct format and is enclosed by walls.

## Mandatory Requirements
- The game must read a map from a `.ber` file.
- The player must collect all items before reaching the exit.
- The map must have at least one exit, one collectible, and one player starting position.
- Walls must surround the map completely.

## Bonus
- **Enemy AI**: Add moving enemies that challenge the player.
- **Animations**: Smooth transitions for player movement.
- **More Interactions**: Additional mechanics like doors, keys, or traps.

## Compilation
Compile the project with:
```bash
make
```
To clean object files:
```bash
make clean
```
To remove binaries:
```bash
make fclean
```
To recompile:
```bash
make re
```

## Usage
Run the game with:
```bash
./so_long maps/map.ber
```
Example:
```bash
./so_long maps/level1.ber
```

## Controls
- **W / ↑**: Move up
- **A / ←**: Move left
- **S / ↓**: Move down
- **D / →**: Move right
- **ESC**: Quit the game

## Error Handling
- Invalid maps (incorrect format, missing elements, or unplayable layouts) should trigger errors.
- The program should handle incorrect file inputs gracefully.

## Dependencies
- **MiniLibX**: The project uses MiniLibX for graphics rendering.
- **GNU Make & GCC**: Required for compilation.

## Author
El Mehdi Belfkih

