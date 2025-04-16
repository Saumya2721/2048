# 🎯 Investigation & Enhancement of the 2048 Game Project

A **deep-dive investigation** into the 2048 Game and our comprehensive improvements—covering functionality, limitations, and future possibilities.

---

## 🔍 Original Project Overview

The original **2048 game** is a console-based puzzle where the player slides numbered tiles on a grid to combine them and eventually reach the value **2048**. It uses simple text output enriched with ANSI color codes for vibrant visual feedback.

---

## ⚙️ Key Features & Mechanics

### 🗺️ Board Setup & Initialization
- **Grid Structure:** Uses a 2D grid (usually 4×4) where empty cells are represented as `0`.
- **Starting Tiles:** Begins with one or two randomly placed tiles (typically, 2's).

---

### 🔄 Tile Movement & Merging
- **Movement:**  
  Tiles shift in the chosen direction (**W/A/S/D** or arrow keys) until they hit an obstacle.
- **Combination:**  
  When two adjacent tiles with the same value meet, they merge into one (doubling the value) and update the score.
- **Two-Phase Approach:**  
  First *move* then *combine* — ensuring the game logic remains predictable.

---

### ✨ New Tile Generation
- **Dynamic Spawning:**  
  After each valid move, a new tile (2 or 4, based on a set probability) is added randomly.

---

### 🎮 Input Handling & Game Flow
- **Supported Commands:**  
  - **WASD / Arrow Keys:** For directional moves  
  - **Pause:** `p`  
  - **Undo:** `u`  
  - **Restart:** `r`  
  - **Quit:** `q`
  
- **Smooth Flow:**  
  Seamless transitions between input commands and game state updates.

---

### 🎨 Visual Feedback
- **ANSI Color Coding:**  
  Provides clear visual differentiation for tiles.
- **On-Screen Indicators:**  
  A prominent score display and turn counter.

---

### 🏆 Leaderboard
- **Score Persistence:**  
  Game scores are saved in `leaderboard.txt` for historical tracking.

> **References:**  
> - **Game logic & rendering:** `game.cpp`  
> - **Class structure:** `game.h`  
> - **Leaderboard:** `leaderboard.txt`  
> - **Input & main loop:** `main.cpp`

---

## 🚧 Limitations of the Original Code

- **Basic Visuals:**  
  Lacks advanced animations and dynamic transitions.

- **Input Handling Robustness:**  
  Rapid inputs or ambiguous commands may lead to unexpected behavior.

- **Limited Undo Feature:**  
  The hard-coded undo limit (5 moves) can restrict the user experience.

- **Code Structure:**  
  Mixing of game logic, rendering, and control flow complicates future expansion.

- **Extensibility:**  
  Monolithic design restricts integration of features like sound effects, enhanced UI, or networked play.

---

## 🔧 Our Code Improvements Explained

Our modifications address these limitations by refining functionality, robustness, and the overall developer/user experience.

### ✅ Enhanced Game State Management
- **Robust Undo System:**  
  - Before every move, the entire game state (board, score, turn) is saved into an **undo stack**.  
  - Seamless rollback reduces the risk of state corruption.  
  *(Implementation details in `game.cpp`.)*

---

### ✅ Refined Input Handling & Control Flow
- **Structured Command Processing:**  
  - Commands such as pause, undo, restart, and quit are clearly handled.  
  - Improved checks ensure rapid or multiple inputs do not disrupt game state.
- **User Feedback Enhancements:**  
  - Auditory cues (a beep) confirm valid moves.  
  - Clear on-screen notifications indicate events like pause or restart.  
  *(See `main.cpp` for details.)*

---

### ✅ Improved Code Organization & Readability
- **Separation of Concerns:**  
  - Better modularity between game logic and UI rendering allows independent modifications.
- **Clear Function Responsibilities:**  
  - Methods like `move()` and `combine()` have been refactored for clarity.
- **Comprehensive Documentation:**  
  - Enhanced inline comments and naming conventions aid future maintenance.

---

### ✅ Leaderboard & Persistence Enhancements
- **Score Tracking:**  
  - Scores are appended to and sorted from `leaderboard.txt` to maintain a history.
- **Visual Clarity:**  
  - The leaderboard display makes high scores easy to interpret.

---

### ✅ Future-Proofing & Extensibility
- **Modular Design:**  
  - Lays the groundwork for transitioning to GUI-based implementations (e.g., using SDL or SFML).
- **Feature Expansion:**  
  - Ready for future additions like sound effects, animations, advanced control options, and even online play.
- **Dynamic Options:**  
  - Possibility to implement dynamic difficulty settings or alternate board sizes.

---


## An overview of how our game works 
![Image](https://github.com/user-attachments/assets/4e13de36-486e-4791-87b2-3d204f1d136f)

## How to compile and run the game? Don't fret!! Here's how to do it...
https://github.com/user-attachments/assets/cb4942b4-ebdc-496c-8477-d5a535db89f2


## 🎉 Future Roadmap
- **🎨 Graphical User Interface (GUI):**  
  Transition to a GUI for smoother animations and a richer user experience.
- **🔊 Sound & Effects:**  
  Integrate custom sound effects and background music.
- **🔁 Flexible Undo/Replay:**  
  Implement a dynamic undo mechanism or a replay feature.
- **⚙️ Expanded Game Modes:**  
  Offer multiple board sizes, various difficulty levels, or even a competitive networked version.
- **📈 Enhanced Persistence:**  
  Migrate from a text file to a database or online leaderboard system.

---

## 🏆 Conclusion
The original 2048 game laid a solid foundation with its minimalist design. Our improvements focus on:

- **Robust State Management:**  
  Enabling a reliable undo system.
- **Refined Input Handling:**  
  Delivering a smoother, more intuitive experience.
- **Separation of Concerns:**  
  Enhancing maintainability and paving the way for future feature integration.
- **Future-Ready Enhancements:**  
  Preparing the codebase for GUI transitions, advanced animations, sound, and online capabilities.

---

**Prepared by [Your Name/Group] — [Date]**

*Thank you for exploring our enhanced 2048 game project! We welcome your feedback and contributions to further refine this classic game.*

