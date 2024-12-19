# 🛠️ Separated Compilation of Source Code

### 📂 File Organization
- The single program file has been split into multiple C-files and corresponding header files for better maintainability.

### 📜 Responsibility-Based Structure
- The codebase is now divided according to specific responsibilities:
  - **`prep.*`**: Handles the basic preparation of the application (e.g., initializing curses).
  - **`worm_model.*`**: Manages worm data structures and related manipulation functions.
  - **`board_model.*`**:
    - Places items on the game board.
    - Checks dimensions of the game board.
    - Lays groundwork for future improvements, such as tracking cell occupation.
  - **`worm.*`**: Contains the main game logic and execution.

### 🛠️ Build Process Improvements
- Introduced a more complex and robust `Makefile` to streamline the compilation and build process.

