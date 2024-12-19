## 🛠️ Separated Compilation of Source Code

- **📂 File Organization**:
  - Split the single program file into multiple C-files and corresponding header files.
- **📜 Code and Responsibility Separation**:
  - Organized files by their respective functionalities:
    - **`prep.*`**: Basic preparation of the application (curses).
    - **`worm_model.*`**: Worm data structures and manipulation functions.
    - **`board_model.*`**: 
      - Place items onto the game board.
      - Check dimensions of the game board.
      - Future expansion: Manage cell occupation for better motivation.
    - **`worm.*`**: Main code of the game.
- **🛠️ Enhanced Build Process**:
  - Added a more complex `Makefile` for easier compilation and build management.
