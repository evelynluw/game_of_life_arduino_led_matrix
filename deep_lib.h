//const for the game
const int MAX_ROW = 8 + 2;
const int MAX_COL = 32 + 2;

void fill_margin(bool twod[][MAX_COL]) {
    //copy column (max-2) to col (0)
    for(int i = 0; i < MAX_ROW; i++) {
        twod[i][0] = twod[i][MAX_COL - 2];
    }
    //copy col (1) to col (max-1)
    for(int i = 0; i < MAX_ROW; i++) {
        twod[i][MAX_COL - 1] = twod[i][1];
    }
    //copy row(max - 2) to row(0)
    for(int j = 0; j < MAX_COL; j++) {
        twod[0][j] = twod[MAX_ROW -2][j];
    }
    //copy row(1) to row (max - 1)
    for(int j = 0; j < MAX_COL; j++) {
        twod[MAX_ROW - 1][j] = twod[1][j];
    }
}

void copy_2d(bool dest[][MAX_COL], bool src[][MAX_COL]) {
    for(int i = 0; i < MAX_ROW; i++) {
        for(int j = 0; j < MAX_COL; j++) {
            dest[i][j] = src[i][j];
        }
    }
}


int count_neighbors(bool twod[][MAX_COL], int i, int j) {
    int count = 0;
    for(int i1 = i - 1; i1 <= i + 1; i1 ++) {
        for(int j1 = j - 1; j1 <= j + 1; j1 ++) {
            if(i1 == i && j1 == j)
                continue;
            if(twod[i1][j1])
                count++;
        }
    }
    return count;
}


void live_or_die(bool &cell, int neighborCount) {
    if(cell) {  // cell is alive
        if(neighborCount < 2)
            cell = false;
        if(neighborCount > 3)
            cell = false;
    }
    else {      // cell is dead
        if(neighborCount == 3)
            cell = true;
    }
}

bool all_dead(bool twod[][MAX_COL]) {
    bool allDead = true;
    for(int i = 1; i < MAX_ROW - 1; i++) {
        for(int j = 1; j < MAX_COL - 1; j++) {
            if(twod[i][j])
                allDead = false;
        }
    }
    return allDead;
}

