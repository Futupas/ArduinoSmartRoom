const bool ON = true;
const bool OFF = false;

const int MovingSensor = 2;
const int RadioA = 3;
const int RadioB = 4;
const int RadioC = 5;
const int Relay1 = 6;
const int Relay2 = 7;

const int MODE = 2;

void setup(){
  pinMode(MovingSensor, INPUT);
  pinMode(RadioA, INPUT);
  pinMode(RadioB, INPUT);
  pinMode(RadioC, INPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
}

void loop(){
  switch(MODE){
    case 0:
      // On light
      break;
     case 1:
      // Off light, but waiting to on
      break;
     case 2:
      // Off light
      break;
  }
}

