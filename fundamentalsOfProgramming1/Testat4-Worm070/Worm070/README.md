# 🐍 Changelog

## ✨ New Features in This Version

### `board_model.c`
- **🛡️ Board Structure for Collision Detection**:
  - Added functionality to detect collisions with:
    - Barriers
    - The worm itself
- **🍎 Food Items**:
  - Introduced food items for gameplay.
- **📏 Level Design**:
  - Added a fixed level with barriers (currently hardcoded, not from a file).

### `worm_model.c`
- **🌱 Worm Growth**:
  - Worm now grows upon consuming food.
- **🎨 Enhanced Display**:
  - Improved visualization of the worm:
    - Distinct symbols for the head
    - Inner body segments
    - Tail


## 📋Running the Program

Once the program is ready, execute it using the following command:

```sh
make && bin/worm
```

