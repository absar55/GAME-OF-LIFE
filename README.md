# Game of Life 🕹️

**Conway's Game of Life** is a zero-player cellular automaton devised by mathematician John Conway in 1970. It simulates the life and death of cells on a two-dimensional grid based on simple rules, leading to fascinating and complex patterns over discrete time steps.

---

## 🚀 Project Overview

This project implements the classic **Game of Life** using C++, designed to run on Ubuntu OS. The simulation evolves a 20x20 grid of cells through multiple generations, applying Conway’s rules to determine cell survival, birth, and death.  

The implementation features:  
- Efficient tracking of live and neighbor cells using secondary arrays  
- Dynamic handling of cell state changes without temporary arrays  
- Reading initial configurations and generation count from an input file  
- Outputting the final live cell states to a file after simulation  

---

## 🎯 Core Concepts

### Grid and Cell States

- Grid size: **20 x 20** (expandable dynamically for cells outside current bounds)  
- Each cell is either **alive (1)** or **dead (0)**  
- Coordinates: (x, y) with (0, 0) at top-left, x increases rightwards, y increases downwards  

### Neighboring Cells

Each cell has **eight neighbors**:  
(x-1, y-1), (x, y-1), (x+1, y-1),
(x-1, y), (x+1, y),
(x-1, y+1), (x, y+1), (x+1, y+1)


### Rules of the Game

| Condition                        | Outcome                      |
|---------------------------------|------------------------------|
| **Dead cell with exactly 3 live neighbors** | Becomes alive (Birth)         |
| **Alive cell with 2 or 3 live neighbors**    | Remains alive (Survival)      |
| **Alive cell with <2 live neighbors**        | Dies (Death by loneliness)    |
| **Alive cell with >3 live neighbors**        | Dies (Death by overcrowding)  |

---

## 🛠️ Implementation Details

- **Grid Array:** Holds cell states (alive=1, dead=0)  
- **Secondary Array (sec-array):** Tracks coordinates of currently alive cells for efficient updates  
- **Neighbor Array (nei-array):** Tracks dead neighbor cells adjacent to alive cells  
- No temporary arrays are used for insertion or deletion — cells are inserted/deleted efficiently with swapping  
- Input and output are file-based to easily simulate multiple generations and test patterns  

---

## 🔄 Simulation Workflow

1. **Read Input:** Number of generations & initial live cell coordinates from input file  
2. **Initialize Grid & sec-array** with initial pattern  
3. **Compute neighbors:** Fill nei-array with dead neighbor cells, avoiding duplicates  
4. **Count live neighbors** for each alive cell and neighbor cell  
5. **Apply rules:** Determine cells to survive, die, or become alive  
6. **Update sec-array and Grid:** Insert new live cells, remove dead cells  
7. **Repeat for desired generations**  
8. **Output final live cell coordinates** to output file  

---

## 📝 Input File Format

<number_of_generations>
<number_of_initial_live_cells>
x1 y1
x2 y2


Example:
10
6
19 9
10 10
11 10
12 10
19 10
19 11


---

## 💾 Output File Format

After simulation completes, live cells are output as:  
<number_of_generations>
<number_of_live_cells>
x1 y1
x2 y2


---

## ⚙️ How to Run

1. **Clone the repository:**

   ```bash
   git clone https://github.com/USERNAME/game-of-life.git
   cd game-of-life




---

## ⚙️ How to Run

1. **Clone the repository:**

   ```bash
   git clone https://github.com/USERNAME/game-of-life.git
   cd game-of-life


g++ -o game_of_life main.cpp
./game_of_life input.txt
