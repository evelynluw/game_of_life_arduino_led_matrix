#include <MD_MAX72xx.h>
#include "game_for_life.h"

#define MAX_DEVICES 12
#define CLK_PIN     13
#define DATA_PIN    11
#define CS_PIN      10

#define SPEED_SW_PIN 2  //speed switch button
int SPEED_MODE = 0;  
int DELAYTIME = 500;    
#define RST_PIN 3       //reset button
#define RDM_PIN 4       //random button
MD_MAX72XX M = MD_MAX72XX(CS_PIN, MAX_DEVICES);


bool world[MAX_ROW][MAX_COL];

//Code for arduino

void setup() {
  // put your setup code here, to run once:
  M.begin();
  Serial.begin(9600);
  initialize_2d(world);
  initial_config(world);
  pinMode(SPEED_SW_PIN, INPUT_PULLUP);
  pinMode(RST_PIN, INPUT_PULLUP);
  pinMode(RDM_PIN, INPUT_PULLUP);


}

void dotDisplay(int r, int c, bool state) {
  if(r < 8) {
    M.setPoint(7-r, c, state);
  }
  if(r >= 8 && r < 16) {
    M.setPoint(r-8, 63-c, state);
  }
  if(r >= 16 && r < 24) {
    M.setPoint(23-r, 64+c, state);  
  }
}

void displayArray(bool twod[][MAX_COL]) {
  for(int i = 1; i < MAX_ROW - 1; i++) {
    for(int j = 1; j < MAX_COL - 1; j++) {
      if(twod[i][j]) {
        dotDisplay(i-1, j-1, true);
//        Serial.print("o ");
      } else {
        dotDisplay(i-1, j-1, false);
//        Serial.print(". ");  
      }
        
    }
//    Serial.print("\n");
  }
}

void loop() {
  if (digitalRead(SPEED_SW_PIN) == LOW) {
    SPEED_MODE++;
    if(SPEED_MODE == 3) {
      SPEED_MODE = 0;  
    }
    Serial.print("speed ");
    Serial.print(SPEED_MODE);
    Serial.print("\n");
    switch(SPEED_MODE) {
      case 0:
        DELAYTIME = 500;
        break;
      case 1:
        DELAYTIME = 150;
        break;
      case 2:
        DELAYTIME = 100;
        break;  
    }
    delay(300);
  }
  if (digitalRead(RST_PIN) == LOW) {
    initialize_2d(world);  
  }
  if (digitalRead(RDM_PIN) == LOW) {
    initial_random(world, 30);  
  }
  displayArray(world);
  step(world);
  delay(DELAYTIME);
}
