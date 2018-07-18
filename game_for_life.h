#include "deep_lib.h"

void initialize_2d(bool twod[][MAX_COL]) {
    //so the twod[] will be declared as twod[MAX_ROW][MAX_COL]
    for(int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            twod[i][j] = false;
        }
    }
}

void initial_config(bool twod[][MAX_COL]) {
//    twod[1][2] = true;
//    twod[2][3] = true;
//    twod[3][1] = true;
//    twod[3][2] = true;
//    twod[3][3] = true;
    for(int i = 12; i < 22; i++) {
        twod[5][i] = true;
    }
    fill_margin(twod);
}

void initial_random(bool twod[][MAX_COL], int count_arg) {
    randomSeed(analogRead(0));
    int pos_i = 0;
    int pos_j = 0;
    int count = count_arg;
    while (count > 0){
        pos_i = rand() % (MAX_ROW - 2) + 1;
        pos_j = rand() % (MAX_COL - 2) + 1;
//        cout << "DEBUG: ";
//        printf("(%d, %d)\n", pos_i, pos_j);
        if (!twod[pos_i][pos_j]){
            twod[pos_i][pos_j] = true;
            count --;
        }
    }
}

void step(bool twod[][MAX_COL]) {
    bool temp[MAX_ROW][MAX_COL];
    copy_2d(temp, twod);
    for(int i = 1; i < MAX_ROW - 1; i++) {
        for(int j = 1; j < MAX_COL  - 1; j++) {
            live_or_die(twod[i][j], count_neighbors(temp, i, j));
        }
    }
    fill_margin(twod);
}



//void fill_margin(bool twod[][MAX_COL]) {
//    //copy column (max-2) to col (0)
//    for(int i = 0; i < MAX_ROW; i++) {
//        twod[i][0] = twod[i][MAX_COL - 2];
//    }
//    //copy col (1) to col (max-1)
//    for(int i = 0; i < MAX_ROW; i++) {
//        twod[i][MAX_COL - 1] = twod[i][1];
//    }
//    //copy row(max - 2) to row(0)
//    for(int j = 0; j < MAX_COL; j++) {
//        twod[0][j] = twod[MAX_ROW -2][j];
//    }
//    //copy row(1) to row (max - 1)
//    for(int j = 0; j < MAX_COL; j++) {
//        twod[MAX_ROW - 1][j] = twod[1][j];
//    }
//}
//
//void print_2d(bool twod[][MAX_COL]) {
//    for(int i = 1; i < MAX_ROW - 1; i++) {
//        for(int j = 1; j < MAX_COL - 1; j++) {
////            cout << twod[i][j] << ' ';
//            if(twod[i][j])
//                cout << "o ";
//            else
//                cout << ". ";
//        }
//        cout << endl;
//    }
//}


//void print_1d(bool oned[]) {
//    int length = max(MAX_ROW, MAX_COL);
//    for(int i = 0; i < length; i++) {
//        cout << oned[i] << ' ';
//    }
//    cout << endl;
//}



