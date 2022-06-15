//analog input
int GEAR1 = A0;
int GEAR2 = A1;
int GEAR3 = A2;
int GEAR4 = A3;
int GEAR5 = A4;
int GEARREV = A5;

//digital output
int LED_A = 5;//5v - B5 Cluster Pin
int LED_B = 4;//5v - B4 Cluster Pin
int LED_C = 3;//5v - B3 Cluster Pin

int gear_1 = HIGH;
int gear_2 = HIGH;
int gear_3 = HIGH;
int gear_4 = HIGH;
int gear_5 = HIGH;
int gear_r = HIGH;

int toNeutral = 0;

void setup() {
  //input setup
  pinMode(GEAR1, INPUT);
  pinMode(GEAR2, INPUT);
  pinMode(GEAR3, INPUT);
  pinMode(GEAR4, INPUT);
  pinMode(GEAR5, INPUT);
  pinMode(GEARREV, INPUT);

  //output setup
  pinMode(LED_C, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_A, OUTPUT);

  //set to n
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_C, HIGH);
  
  //debug
  pinMode(LED_BUILTIN, OUTPUT);

  debugStartUp();
  //Serial.begin(9600);
}

//for debug
void blink(int val){
  for (int i = 0; i < val; i++) {
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(200); 
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }  
}

void debugStartUp(){
  int i;
   for (i=0; i<6; i++){
    gearOutput(i);
    delay(400);
   }
}

void gearOutput(int i){
  if(i == 1){
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, HIGH);
  } else if(i == 2){
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, LOW);
  } else if(i == 3){
    digitalWrite(LED_A, LOW );
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
  } else if(i == 4){
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
  } else if(i == 5){
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, HIGH);
  } else if(i == 0){
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
  }
}

void loop() {
  gear_1 = digitalRead(GEAR1);
  gear_2 = digitalRead(GEAR2);
  gear_3 = digitalRead(GEAR3);
  gear_4 = digitalRead(GEAR4);
  gear_5 = digitalRead(GEAR5);
  gear_r = digitalRead(GEARREV);

//  Serial.print("######\n");
//  Serial.print(gear_1);
//  Serial.print(gear_2);
//  Serial.print(gear_3);
//  Serial.print(gear_4);
//  Serial.print(gear_5);
//  Serial.print("\n######\n");

 if (gear_1 == LOW){
    //gear 1
    gearOutput(1);
    toNeutral = 2;
    //blink(1);
  } else if(gear_2 == LOW){
    //gear 2
    gearOutput(2);
    toNeutral = 2;
    //blink(2);
  } else if(gear_3 == LOW){
    //gear 3 
    gearOutput(3);
    toNeutral = 2;
    //blink(3);
  } else if(gear_4 == LOW){
    //gear 4
    gearOutput(4);
    toNeutral = 2;
    //blink(4);
  } else if(gear_5 == LOW){
    //gear 5
    gearOutput(5);
    toNeutral = 2;
    //blink(5);
  } else if(gear_r == LOW){
    //gear r
    gearOutput(0);
    toNeutral = 2;
    //blink(6);
  } else {
    //gear r or neutral
    if(toNeutral == 0){
      gearOutput(0);
      toNeutral = 2;
    } else {
      toNeutral--;
    }
    //blink(0);
  }
  delay(500); //default 500
}
