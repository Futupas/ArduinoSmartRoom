int MODE = 0; //0 - Light, 1 - RoomExit, 2 - Signalization, 3 - SignalWorkss

const int Lamp = 13;
const int MovingSensor = 12;

const int JoystickX = 0;
const int JoystickY = 0;
const int ConsoleA = 7;
const int ConsoleB = 6;
const int ConsoleC = 5;
const int ConsoleD = 4;


void setup() {
  pinMode(ConsoleA, INPUT);
  pinMode(ConsoleB, INPUT);
  pinMode(ConsoleC, INPUT);
  pinMode(ConsoleD, INPUT);
  
  pinMode(MovingSensor, INPUT);
  
  pinMode(Lamp, OUTPUT);
}

void loop() {
  switch(MODE){
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
  }
}

