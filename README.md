# so_long

## Description
`so_long` is a simple 2D game implemented in C using the MinilibX library. The game involves guiding a character through a map while collecting collectibles and avoiding obstacles.

## Features
- Renders a window using MinilibX library for graphics.
- Supports movement of the player character using keyboard inputs.
- Generates maps from text files, allowing for easy creation and modification of levels.
- Handles collision detection with walls and collectibles.
- Tracks player's score and displays it on the screen.
- Implements basic game logic for win and lose conditions.

## Getting Started
To play `so_long`, follow these steps:

1. Clone the repository to your local machine:
```shell
git@github.com:wzakkabi/so_long.git
```
2. Compile the source files:
```shell
make
```
3. Run the executable:
```shell
./so_long maps/mp.ber
```

## Controls
- Use the arrow keys to move the player character (w, s, a, d).
- Press ESC or close the window to exit the game.

## Map Format
Maps are stored in `.ber` files and consist of the following characters:
- `1`: Wall (obstacle)
- `0`: Empty space
- `C`: Collectible
- `E`: Exit (goal)
- `P`: Player character

Example map:
11111111111111111111
10C001C1000000000001
10010100100010000C01
1000000000001000E0P1
11111111111111111111

## Credits
The `so_long` project was created by [walid zakkabi]. Special thanks to (https://www.1337.ma/en/) and (https://www.42network.org)] for their contributions and support.

## Contact
If you have any questions, suggestions, or issues regarding `so_long`, feel free to contact [wzakkabi@gmail.com] or open an issue on the GitHub repository.
