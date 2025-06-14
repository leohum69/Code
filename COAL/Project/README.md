# Candy Crush Game - Assembly Language Project

This project is a semester project for the course **EL2003 - Computer Organization and Assembly Language - Lab** at FAST-NUCES Islamabad. The game mimics the functionality of the classic *Candy Crush* game, written entirely in **x86 Assembly Language** for DOS.

---

## 👨‍💻 Authors

- Mirza Humayun Masood (I22-1749)
- Saif-Ur-Rehman (I22-1697)
- Mustafa Zain (I22-4948)

## 📚 Project Structure

The code is modular and divided into the following files:

- `macros.asm`: Contains reusable macros like `clsscreen`, `pushreg`, `popreg`, `calsleep`, `setcurs`, etc.
- `constants.asm`: Contains constants and data structures such as levels, candy types, screen dimensions, etc.
- `main.asm`: Main game logic and functions

## 🕹️ Features

- Mouse input using BIOS interrupts
- Score tracking for 3 levels
- File writing support for storing user scores
- Randomized candy drop with visual feedback
- 7x7 board with candy swap and combo detection (horizontal, vertical, and diagonal)
- Candy crush animations and sound messages
- Supports basic file I/O using DOS interrupts

## 🎮 Game Mechanics

- Each level has a score threshold and limited moves:
  - Level 1: 15 moves, score ≥ 50
  - Level 2: score ≥ 100
  - Level 3: score ≥ 150
- Bomb candies, combos, and visual messages enrich the game.
- Score, name, and progress are stored in a file after each game.

## 🏗️ Procedures Overview

### System-Level Procedures

- `startmouse`, `hidemouse`, `showmouse`: Control mouse visibility and input
- `mkscreen`, `clsscreen`: Initialize and clear screen using video interrupt
- `exit`: Saves scores and cleanly exits the program

### Game Initialization

- `startgame`: Displays rules, initializes board, and loads UI
- `makeboard`: Builds game board and places candies

### Game Loop

- `GameLoop`: Runs core gameplay loop, including user input, combo detection, and progression
- `mousehandling`, `leftmousepressed`: Handles interactions with candies

### Candy Drawing

- `drawcandyX`, `drawbomb`, `drawblankcandy`: Render candies using pixel drawing via interrupt 10h

### Logic Operations

- `candyswap`, `chkcandyneighbour`: Validate and perform swaps
- `balanceboard`, `dropcandy`, `pushdown`: Maintain game state
- `findallcombos`, `findcomboo`: Detect match patterns

## 💾 Score Saving

- Scores are saved using `savescores.asm` using DOS interrupt 21h.
- Username input is stored in a buffer and validated.
- High score is calculated from three levels.

## 📋 Input/Output

- All printing and I/O use `coutstr`, `coutnum`, `IntToStr`, and DOS interrupts for string and number output.
- Supports keyboard input for name and uses BIOS for real-time screen updates.

## 🔧 Build & Run Instructions

This project was designed for **DOSBox** or a real DOS environment.

1. Assemble the `.asm` files using **MASM**.
2. Link object files to generate `.exe` file.
3. Run using DOSBox:
    ```bash
    mount c your_folder_path
    c:
    game.exe
    ```

---


## 📜 License

This project was built for educational purposes under FAST-NUCES Islamabad. Free to use with proper attribution.