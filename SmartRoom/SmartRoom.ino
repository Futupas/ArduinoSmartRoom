int MODE = 0; //0 - Light, 1 - RoomExit, 2 - Signalization, 3 - SignalWorkss

const int Lamp = 13;
const int MovingSensor = 12;

const int JoystickX = 0;
const int JoystickY = 0;
const int ConsoleA = 7;
const int ConsoleB = 6;
const int ConsoleC = 5;
const int ConsoleD = 4;

bool CurrentLight = false;


void setup() {
  pinMode(ConsoleA, INPUT); // Light ON, OFF
  pinMode(ConsoleB, INPUT); // Exit from room
  pinMode(ConsoleC, INPUT); // On signalization
  pinMode(ConsoleD, INPUT); // Off signalization
  
  pinMode(MovingSensor, INPUT);
  
  pinMode(Lamp, OUTPUT);

  digitalWrite(Lamp, CurrentLight);
}

void loop() {
  switch(MODE){
    case 0: 
      if(digitalRead(ConsoleC)) MODE = 2; // Signalization
      if(digitalRead(ConsoleA)) {
        CurrentLight = !CurrentLight; // Switch light
        digitalWrite(Lamp, CurrentLight);
      }
      if(digitalRead(ConsoleB)) MODE = 1;
      break;
    case 1:
      if(digitalRead(MovingSensor)){
        digitalWrite(Lamp, CurrentLight);
        MODE = 0; // HERE
      }
      break;
    case 2:
      
      break;
    case 3:
      
      break;
  }

  delay(100); // TEMPORARY
}

