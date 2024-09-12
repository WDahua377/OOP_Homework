#include "Grid.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

Grid::Grid():row(1), column(1), moverDIR(EAST), showpath(true){
    map[row-1][column-1] = '>';
    moverR = row;
    moverC = column;
}

// build grid with r rows, c cols, 
// blocks around edge with random exit and random mover position and direction
Grid::Grid(int r, int c):row(r), column(c), showpath(true){
    srand( time(NULL) );
    if(r < 3)
        row = 3;
    if(c < 3)
        column = 3;
    if(r > MAX_SIZE)
        row = MAX_SIZE;
    if(c > MAX_SIZE)
        column = MAX_SIZE;
    
    for(int i = 0;i < row;i++){
        for(int j = 0;j < column;j++){
            if(i == 0 || j == 0 || i == row-1 || j == column-1)
                map[i][j] = '#';
            else
                map[i][j] = '.';
        }
    }

    int randrow, randcol;
    while(true){
        randrow = rand() % (row) + 1;
        if(randrow != 1 && randrow != row)
                break;
    }

    while(true){
        randcol = rand() % (column) + 1;
        if(randcol != 1 && randcol != column)
                break;
    }
    int randDIR = rand() % (4);

    moverDIR = randDIR;
    switch (moverDIR){
        case 0:
            map[randrow-1][randcol-1] = '^';
            moverR = randrow;
            moverC = randcol;
            break;
        case 1:
            map[randrow-1][randcol-1] = '<';
            moverR = randrow;
            moverC = randcol;
            break;
        case 2:
            map[randrow-1][randcol-1] = 'v';
            moverR = randrow;
            moverC = randcol;
            break;
        case 3:
            map[randrow-1][randcol-1] = '>';
            moverR = randrow;
            moverC = randcol;
            break;
    }
    
    while(true){
        int randDIR = rand() % (4);
        if(randDIR == 0){
            randcol = rand() % (column) + 1;
            if(randcol != 1 && randcol != column){
                map[0][randcol-1] = ' ';
                break;
            }
        }
        if(randDIR == 2){
            randcol = rand() % (column) + 1;
            if(randcol != 1 && randcol != column){
                map[row-1][randcol-1] = ' ';
                break;
            }
        }
        if(randDIR == 1){
            randrow = rand() % (row) + 1;
            if(randrow != 1 && randrow != row){
                map[randrow-1][0] = ' ';
                break;
            }
        }
        if(randDIR == 3){
            randrow = rand() % (row) + 1;
            if(randrow != 1 && randrow != row){
                map[randrow-1][column-1] = ' ';
                break;
            }
        }
    }
    std::cout << randDIR << " " << randrow << " " << randcol << std::endl;
}

// build empty grid with r rows, c cols, and mover at row mr, col mc, and facing direction d
Grid::Grid(int r, int c, int mr, int mc, int d):row(r), column(c)
            , moverR(mr-1), moverC(mc-1),moverDIR(d), showpath(true){
    srand( time(NULL) );
    if(r < 1)
        row = 1;
    if(c < 1)
        column = 1;
    if(r > MAX_SIZE)
        row = MAX_SIZE;
    if(c > MAX_SIZE)
        column = MAX_SIZE;

    for(int i = 0;i < row;i++){
        for(int j = 0;j < column;j++){
            map[i][j] = '.';
        }
    }

    if(mr > row)
        moverR = row;
    if(mr < 0)
        moverR = 1;
    if(mc > column)
        moverC = column;
    if(mc < 0)
        moverC = 1;

    switch (moverDIR){
        case 0:
            map[moverR-1][moverC-1] = '^';
            break;
        case 1:
            map[moverR-1][moverC-1] = '<';
            break;
        case 2:
            map[moverR-1][moverC-1] = 'v';
            break;
        case 3:
            map[moverR-1][moverC-1] = '>';
            break;
    }
}

// move forward s spaces, if possible
bool Grid::Move(int s){
    switch (moverDIR){
        case 0:
            for(int i = 1; i <= s;i++){
                if(map[moverR-i-1][moverC-1] == '#' || moverR-1 <= 0)
                    return false;
            }
            for(int i = 1; i <= s;i++){
                if(showpath == true)
                    map[moverR-i-1][moverC-1] = ' ';
            }
            map[moverR-s-1][moverC-1] = '^';
            return true;
            break;
        case 1:
            for(int i = 1; i <= s;i++){
                if(map[moverR-1][moverC-i-1] == '#' || moverC-1 <= 0)
                    return false;
            }
            for(int i = 1; i <= s;i++){
                if(showpath == true)
                    map[moverR-1][moverC-i-1] = ' ';
            }
            map[moverR-1][moverC-s-1] = '<';
            return true;
        case 2:
            for(int i = 1; i <= s;i++){
                if(map[moverR+i][moverC-1] == '#' || moverR+1 > row)
                    return false;
            }
            for(int i = 1; i <= s;i++){
                if(showpath == true)
                    map[moverR+i][moverC-1] = ' ';
            }
            map[moverR+s][moverC-1] = 'v';
            return true;
        case 3:
            for(int i = 1; i <= s;i++){
                if(map[moverR-1][moverC+i] == '#' || moverC+1 > column)
                    return false;
            }
            for(int i = 1; i <= s;i++){
                if(showpath == true)
                    map[moverR-1][moverC+i] = ' ';
            }
            map[moverR-1][moverC+s] = '>';
            return true;
            
        }
    return false;
}

// toggle whether or not moved path is shown
void Grid::TogglePath(){
    showpath = !showpath;
}

// turn the mover to the left
void Grid::TurnLeft(){
    switch (moverDIR){
        case 0:
            moverDIR = 1;
            break;
        case 1:
            moverDIR = 2;
            break;
        case 2:
            moverDIR = 3;
            break;
        case 3:
            moverDIR = 0;
            break;
        }
}

// put down an item at the mover's position
void Grid::PutDown(){
    map[moverR-1][moverC-1] = '@';
}

// put down an item at (r, c), if possible
bool Grid::PutDown(int r, int c){
    if(map[r][c] != '#' && r <= row && c <= column){
        map[r][c] = '0';
        return true;
    }
    else
    return false;
}

// pick up item at current position
bool Grid::PickUp(){
    if(map[moverR-1][moverC-1] == '@'){
        switch (moverDIR){
        case 0:
            map[moverR-1][moverC-1] = '^';
            break;
        case 1:
            map[moverR-1][moverC-1] = '<';
            break;
        case 2:
            map[moverR-1][moverC-1] = 'v';
            break;
        case 3:
            map[moverR-1][moverC-1] = '>';
            break;
        }
    }
    else
        return false;
    return false;
}

// put a block at (r, c), if possible
bool Grid::PlaceBlock(int r, int c){
    if(map[r][c] == '.' || map[r][c] == ' '){
        map[r][c] = '#';
        return true;
    }
    else
    return false;
}

// grow the grid by gr rows, gc columns
void Grid::Grow(int gr, int gc){
    int a = row, b = column;
    if( (row + gr) <= MAX_SIZE)
        row = row + gr;
    if( (column + gc) <= MAX_SIZE)
        column = column + gc;
    for(int i = a;i < row;i++){
        for(int j = b;j < column;j++){
            map[i-1][j-1] = '.';
        }
    }
}

// display the grid on screen
void Grid::Display() const{
    //std::cout << row << " " << column << std::endl;
    std::cout << "The Grid:" << std::endl;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < column;j++)
            std::cout << map[i][j] << " ";
        std::cout << std::endl;
    }
}

// Accessors
// check to see if space in front of mover is clear
bool Grid::FrontIsClear() const{
    std::cout << moverR << " " << moverC << std::endl;
    switch (moverDIR){
        case 0:
            if(map[moverR-2][moverC-1] != '#' && moverR-1 > 0)
                return true;
            else return false;
        case 1:
            if(map[moverR-1][moverC-2] != '#' && moverC-1 > 0)
                return true;
            else return false;
        case 2:
            if(map[moverR][moverC-1] != '#' && moverR+1 <= row)
                return true;
            else return false;
        case 3:
            if(map[moverR-1][moverC] != '#' && moverC+1 <= column)
                return true;
            else return false;
    }
    return false;
}

// check to see if space to right of mover is clear
bool Grid::RightIsClear() const{
    switch (moverDIR){
        case 1:
            if(map[moverR-2][moverC-1] != '#' && moverR-1 > 0)
                return true;
            else return false;
        case 2:
            if(map[moverR-1][moverC-2] != '#' && moverC-1 > 0)
                return true;
            else return false;
        case 3:
            if(map[moverR][moverC-1] != '#' && moverR+1 <= row)
                return true;
            else return false;
        case 0:
            if(map[moverR-1][moverC] != '#' && moverC+1 <= column)
                return true;
            else return false;
    }
    return false;
}

// return row of the mover
int Grid::GetRow() const{
    return moverR;
}

// return column of the mover
int Grid::GetCol() const{
    return moverC;
}

// return number of rows in the grid
int Grid::GetNumRows() const{
    return row+1;
}

// return number of columns in the grid
int Grid::GetNumCols() const{
    return column+1;
}
