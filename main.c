#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ON 219
#define OFF 0

typedef int State;
typedef int Grid [600];
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
    for (x = 1; x < 600; x++) {
        int r = rand() % 2;
        if (r == 1) {
            grid[x] = ON;
        } else {
            grid[x] = OFF;
        }
    }
}

int getNeighbours(Grid grid, Cell cell) {
    int neighbours = 0;
    if (grid[cell - 41] == ON) {
        neighbours += 1;
    }
    if (grid[cell - 40] == ON) {
        neighbours += 1;
    }
    if (grid[cell - 39] == ON) {
        neighbours += 1;
    }
    if (grid[cell - 1] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 1] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 39] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 40] == ON) {
        neighbours += 1;
    }
    if (grid[cell + 41] == ON) {
        neighbours += 1;
    }
    return neighbours;
}

void updateCell(Grid grid, Cell cell) {
//    int r = rand() % 2;
//    if (r == 1) {
//        grid[cell] = ON;
//    } else {
//        grid[cell] = 255;
//    }
    int p = getNeighbours(grid, cell);
    if (grid[cell] == ON && p < 2) {
        grid[cell] = OFF;
    } else if (grid[cell] == ON && p > 3) {
        grid[cell] = OFF;
    } else if (grid[cell] == OFF && p == 3) {
        grid[cell] = ON;
    }
}

void updateGrid(Grid grid) {
    int x;
    for (x = 1; x < 600; x++) {
        int r = rand() % 2;
        if (r == 1) {
            grid[x] = ON;
        } else {
            grid[x] = 176;
        }
        updateCell(grid, grid[x]);
    }
}

void displayGrid(Grid grid) {
    int x;
    for (x = 1; x < 600; x++) {
        if (x % 40) {
            printf("%c", grid[x]);
        } else {
            printf("\n");
        }
    }
}

int main() {
    Grid grid;
    initGrid(grid);
    while (1) {
        int x;
        for (x = 1; x < 600; x ++) {
            updateCell(grid, x);
        }
        displayGrid(grid);
        int count;
        time_t start, finish;
        sleep(1);
        system("cls");
    }
    return 0;
}
