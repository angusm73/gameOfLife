// Conway's Game of Life in C
// (c)oded by Angus Moore
// email: toxic0323@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ON 219
#define OFF 176
#define GRID_WIDTH 100
#define GRID_HEIGHT 50
#define GRID_SIZE GRID_WIDTH*GRID_HEIGHT

typedef int State;
typedef int Grid[GRID_SIZE];
typedef int Cell;

void sleep(time_t delay) {
    time_t timer0, timer1;
    time(&timer0);
    do {
        time(&timer1);
    } while ((timer1 - timer0) < delay);
}

void initGrid(Grid grid) {
    int x;
    for (x = 1; x < GRID_SIZE; x++) {
        int r = rand() % 2;
        if (r == 1) {
            grid[x] = ON;
        } else {
            grid[x] = OFF;
        }
    }
}

void initGlider(Grid grid) {
    int x;
    for (x = 1; x < GRID_SIZE; x++) {
        if (x == 2 || x == 103 || x == 201 || x == 202 || x == 203) {
            grid[x] = ON;
        } else {
            grid[x] = OFF;
        }
    }
}

void initTest(Grid grid) {
    int x;
    for (x = 1; x < GRID_SIZE; x++) {
        if (x == 122 || x == 223 || x == 321 || x == 322 || x == 323) {
            grid[x] = ON;
        } else {
            grid[x] = OFF;
        }
    }
}

void clearGrid(Grid grid) {
    int x;
    for (x = 0; x < GRID_SIZE; x++) {
        grid[x] = OFF;
    }
}

int getNeighbours(Grid grid, Cell cell) {
    int neighbours = 0;

//    printf("%i", grid[cell] % GRID_WIDTH);

    if (grid[cell - 101] == ON) {
        neighbours += 1;
    }
    if (grid[cell - 100] == ON) {
        neighbours += 1;
    }
    if (grid[cell - 99] == ON) {
        neighbours += 1;
    }
    if (grid[cell - 1] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 1] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 99] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 100] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 101] == ON) {
        neighbours += 1;
    }
    return neighbours;
}

void updateCell(Grid grid, Grid temp, Cell cell) {
//    int r = rand() % 2;
//    if (r == 1) {
//        grid[cell] = ON;
//    } else {
//        grid[cell] = 255;
//    }
    int p = getNeighbours(grid, cell);
    if (grid[cell] == ON && p < 2) {
        temp[cell] = OFF;
    } else if (grid[cell] == ON && p > 3) {
        temp[cell] = OFF;
    } else if (grid[cell] == OFF && p == 3) {
        temp[cell] = ON;
    }
}

void updateGrid(Grid grid, Grid temp) {
    grid = temp;
}

void displayGrid(Grid grid) {
    int x;
    for (x = 1; x < GRID_SIZE; x++) {
        if (x % GRID_WIDTH == 0) {
            printf("\n");
        } else {
            printf("%c", grid[x]);
        }
    }
}

int main() {
    Grid grid;
    Grid temp;
    initGrid(grid);
    // Change initGrid to initGlider for a glider that travels from the top left to the bottom right.
    int p;
    for (p = 0; p < GRID_SIZE; p++) {
        temp[p] = grid[p];
    }
    while (1) {
        for (p = 0; p < GRID_SIZE; p++) {
            grid[p] = temp[p];
        }
        int x;
        displayGrid(temp);
//        sleep(1);
        for (x = 1; x < GRID_SIZE; x ++) {
            updateCell(grid, temp, x);
        }
        updateGrid(grid, temp);
        system("cls");
    }
    return 0;
}
