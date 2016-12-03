const bool ON = true;
const bool OFF = false;

const int MovingSensor = 2;
const int RadioA = 3;
const int RadioB = 4;
const int RadioC = 5;
const int Relay1 = 6;
const int Relay2 = 7;

int MODE = 2; /*
  0 - ON --- A
  1 - WAIT - C
  2 - OFF -- B
*/

bool Rel = false;

void setup(){
  pinMode(MovingSensor, INPUT);
  pinMode(RadioA, INPUT);
  pinMode(RadioB, INPUT);
  pinMode(RadioC, INPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  switch(MODE){
    case 0:
      // On light
      SetRelays(ON);
      if(digitalRead(RadioB)){
        MODE = 2;
      }
      if(digitalRead(RadioC)){
        MODE = 1;
      }
      break;
     case 1:
      // Off light, but waiting to on
      SetRelays(OFF);
      if(digitalRead(RadioA) || digitalRead(MovingSensor)){
        MODE = 0;
      }
      if(digitalRead(RadioB)){
        MODE = 2;
      }
      break;
     case 2:
      // Off light
      SetRelays(OFF);
      if(digitalRead(RadioA)){
        MODE = 0;
      }
      if(digitalRead(RadioC)){
        MODE = 1;
      }
      break;
  }

  if(millis() % 500 == 0){
    if(MODE == 0) Serial.println("0 - ON - A");
    if(MODE == 1) Serial.println("1 - WAIT - C");
    if(MODE == 2) Serial.println("2 - OFF - B");
  }
}
void SetRelays(bool pos){
  if(Rel != pos){
    Rel = pos;
    if(Rel){
      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, HIGH);
    } else {
      digitalWrite(Relay1, LOW);
      digitalWrite(Relay2, LOW);
    }
  }
}
//ToDo: Add buzzer

