
# Silent Knight - Text-Based Adventure Game

This repository showcases the implementation of **Silent Knight**, a text-based adventure game developed as part of a **Data Structures course assignment (BLG223E)**. The game leverages **Stack data structures** and the **Depth-First Search (DFS)** algorithm to navigate through a decision tree, simulating a no-input gameplay experience.

## Game Description

**Silent Knight** is set in the fictional kingdom of **Calithulu**, where players must escape from a heavily guarded prison. Using limited actions and objects, the player interacts with the game world to progress through challenges. 

### Gameplay Summary
- **Objective**: Escape the prison by navigating rooms, interacting with guards, and using items effectively.
- **Actions Available**: 
  1. Open
  2. Look At
  3. Pick Up
  4. Misbehave
  5. Talk To
- **Objects and Rooms**: Items such as "Toilet Paper," "Sink," and rooms like "Cell" and "Toilet" are integral to gameplay.

## Features

- **DFS Algorithm**: Thoroughly explores all possible pathways for solving the game.
- **Stack Implementation**: Manages game states for backtracking and exploring decision trees.
- **Dynamic Inventory and Room Management**: Real-time updates of player inventory and room conditions.
- **Interactive Actions**: Actions dynamically alter the game state and progress the story.

## Technical Overview

### Key Data Structures
1. **Doubly Linked List**: Custom implementation to manage inventory and room objects.
2. **Stack**: Facilitates DFS-based exploration.

### Files in the Repository
- `game.cpp`: Contains the main game logic with DFS implementation.
- `doublelinklist.h`: Custom implementation of a doubly linked list.
- `objects.h`: Game objects and their behavior definitions.
- `game_initial.cpp`, `objects_initial.h`, `doublelinklist_initial.h`: Initial template files for reference.

### Compilation and Execution
- **Environment**: The code is compatible with Ubuntu and compiled using the default `g++` compiler.
- **Compilation Command**: 
  ```bash
  g++ -o game game.cpp
  ```
- **Execution**:
  ```bash
  ./game
  ```

## Observations and Challenges

1. **State Complexity**: Managed intricate game states using a custom `GameState` structure.
2. **Backtracking**: Implemented reliable backtracking with the Stack data structure.
3. **Performance**: Optimized doubly linked list operations for faster DFS traversal.

## Additional Documentation

For a more detailed explanation of the implementation and analysis, please refer to my report included in the repository.

## Privacy Note

This repository is anonymized to protect academic and personal details, adhering to privacy and plagiarism policies.

---


