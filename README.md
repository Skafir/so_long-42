# so_long 🕹️

**so_long** is a small 2D graphical game developed as part of the 42 curriculum. The goal is to move a player through a closed map, collect all the collectibles, and reach the exit.

## 📸 Preview

![image](https://github.com/user-attachments/assets/bac2924c-e972-41c0-9223-cd5365a616d2)


## ✨ Features

- Move the player using keyboard arrows or WASD.
- Collect all collectibles to unlock the exit.
- Simple 2D rendering using MiniLibX.
- Full map validation and error handling.

## 🧱 Structure

- `srcs/`: Source files (display, movement, validations...).
- `libft/`: Personal C library.
- `assets/`: Game textures.
- `map/`: Sample maps in `.ber` format.

## 🛠️ Prerequisites

- Linux
- `gcc` or `clang`
- MiniLibX

## 🚀 Installation

Clone the repository and compile the project:

```bash
make
```

## 🕹️ Usage

Run the game with a `.ber` map file:

```bash
./so_long maps/map1.ber
```

## 🎮 Controls

- `W`, `A`, `S`, `D` or Arrow keys: Move the player
- `ESC`: Quit the game

## 📄 Map Format

Maps must:
- Be rectangular
- Contain exactly one player (`P`)
- Contain at least one exit (`E`)
- Contain at least one collectible (`C`)
- Be fully surrounded by walls (`1`)

## 🧪 Example Map

```
111111
1P0C01
100001
1C0E01
111111
```

## 🔄 Cleaning

```bash
make clean      # Remove object files
make fclean     # Remove object files and binary
make re         # Rebuild everything
```
