# GRMEngine

This document provides an overview of the GRMEngine project, including its structure, technologies, and coding conventions.

## Project Overview

GRMEngine is a cross-platform, game engine built in C++. With a primary goal of 3D, the project aims to have good support for most of my personal needs for game development.

## Technologies used

- **Language:** C++
- **Rendering:** [OpenGL](https://www.opengl.org/)
- **Window Handling:** [GLFW](https://www.glfw.org/)
- **OpenGL Binder:** [GLAD](https://github.com/Dav1dde/glad)
- **Lua Bunder:** [Sol2](https://github.com/ThePhD/sol2)

## Project Structure

The project is organized into the following main directories:

- `engine/`: Contains all rendering, math, etc... (**IMPORTANT:** Do **NOT** make engine rely on editor in any situation.)
  - `include/`: All high level exposed engine functions. (most names are self-explanatory)
    - `ecs/`: Entity Component System
    - `gal/`: Graphics Abstraction Layer
  - `src/`: All low level non-exposed engine functions.
- `editor/`: Editor related UI.
- `assets/`: All assets for the project.

## Coding Conventions

The project tries to stick to orthodox C++; if features like templates are needed, then they're allowed (example: math library).

Under **MOST** circumstances, inheritance should be avoided unless **NECESSARY**.

### Naming

The project uses common naming cases, if you find code not following these guidelines you are free to fix them.

- Constants: **SCREAMING_SNAKE_CASE*; if you find code not following these guidelines, you are free to fix them.

- Constants: **SCREAMING_SNAKE_CASE**
- Non-Const Vars: **camelCase**
- Classes: **PascalCase**

## Build Instructions

1. **Configure CMake**  
   Generate the build system:
    ```bash
    cmake -B build
    ```

2. **Build the Project**  
   Compile the source code:
    ```bash
    cmake --build build
    ```

3. **Run Executable**  
   Run the built file:
    ```bash
    ./build/GRMEngine
    ```

----