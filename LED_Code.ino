#include <ArduinoBLE.h>
const int charsize = 512;
BLEService ledService("180A");
BLEStringCharacteristic switchCharacteristic("2A57", BLERead | BLEWrite, charsize);
//ArduinoBlue phone(ledService);
int G = 6; //6 for ble
int R = 5;  //5 for ble
int B = 3;

float pink_r = 1;
float pink_g = 5.0/255;
float pink_b = 70.0/255;

float purple_r = 160.0/255;
float purple_b = 210.0/255;

void purple();
void pink();
void green();
void red();
void blue();
void cyan();
void yellow();
void orange();
void rave();
void miami();
void pulse();
void pred();
void pblue();
void pgreen();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(G, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(B, OUTPUT);
  if(!BLE.begin()){
    while(1);
  }
  BLE.setDeviceName("Nano");
  ledService.addCharacteristic(switchCharacteristic);
  BLE.addService(ledService);
  switchCharacteristic.writeValue("");
  BLE.setAdvertisedService(ledService);
  BLE.advertise();
}

void loop() {
  // put your main code here, to run repeatedly:
  int R_factor;
  int B_factor;
  Serial.println(pink_g);
  Serial.println(pink_b);
  Serial.println(purple_r);
  Serial.println(purple_b);
  for(int i = 170; i <= 255; i+=5){
    R_factor = (int)(purple_r*i);
    B_factor = (int)(purple_b*i);
    Serial.println(R_factor);
    Serial.println(B_factor);
  }
  BLEDevice central = BLE.central();
  //int button = phone.getButton();
//  Serial.print(button);
  String val = "";
  while(central.connected()){
    if(switchCharacteristic.written()){
      val = switchCharacteristic.value();
    }
    if (val == "red"){
      red();
      val = "";      
    }
    else if (val == "blue"){
      blue();
      val = ""; 
    }
    else if (val == "green"){
      green();
      val = "";
    }
    else if (val == "pink"){
      pink();
      val = "";
    }
    else if (val == "purple"){
      purple();
      val = "";
    }
    else if (val == "rave"){
      rave();
    }
    else if (val == "miami" || val == "Miami"){
      miami();
    }
    else if (val == "cyan"){
      cyan();
    }
    else if (val == "orange"){
      orange();
    }
    else if (val == "yellow"){
      yellow();
    }
    else if (val == "pulse"){
      pulse();
    }
    if (val == "off"){
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
      val = "";
    }
    
  }
}

void purple(){
  analogWrite(G, 0);
  analogWrite(B, 210);
  analogWrite(R, 160);
}
void pink(){
  analogWrite(G, 5);
  analogWrite(B, 70);
  analogWrite(R, 255);
}
void red(){
  analogWrite(G, 0);
  analogWrite(B, 0);
  analogWrite(R, 255);
}
void green(){
  analogWrite(G, 255);
  analogWrite(B, 0);
  analogWrite(R, 0);
}
void blue(){
  analogWrite(G, 0);
  analogWrite(B, 255);
  analogWrite(R, 0);
}
void yellow(){
  analogWrite(G, 255);
  analogWrite(B, 0);
  analogWrite(R, 255);
}
void orange(){
  analogWrite(G, 100);
  analogWrite(B, 0);
  analogWrite(R, 255);
}
void cyan(){
  analogWrite(G, 255);
  analogWrite(B, 255);
  analogWrite(R, 0);
}
void rave(){
  //rose to magenta
  analogWrite(G, 0);
  analogWrite(R, 255);
  for(int i = 0; i <= 255; i += 5){
    analogWrite(B, i);
    delay(50);
  }
  //pink();
  delay(50);
  //purple to blue
  int j = 0;
  for(int i = 255; i >= 0; i -= 5){
    j = 255-i;
    analogWrite(R, i);
    //analogWrite(B, j);
    delay(50);
  }
  //blue(); 
  delay(50);
  //Blue to cyan
  analogWrite(R, 0);
  for(int i = 0; i <= 255; i += 5){
    analogWrite(G, i);
    delay(50);
  }
  //cyan to green
  //cyan();
  delay(50);
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(B, i);
    delay(50);
  }
  //green();
  delay(50);
  for(int i = 0; i <= 255; i += 5){
    analogWrite(R, i);
    delay(50);
  }
  //yellow();
  delay(50);
  //yellow to red
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(G, i);
    delay(50);
  }
  //red();
  delay(50);
}

void miami(){
  cyan();
  delay(500);
  pink();
  delay(500);
  purple();
  delay(500);
  blue();
  delay(500);
}
void pulse(){
  int R_factor;
  int G_factor;
  int B_factor;
  analogWrite(R, 0);
  for(int i = 70; i <= 255; i+=5){
    analogWrite(G, i);
    analogWrite(B, i);
    delay(50);
  }
  for(int i = 255; i >= 70; i-=5){
    analogWrite(G, i);
    analogWrite(B, i);
    delay(50);
  }
  delay(250);
  for(int i = 70; i <= 255; i+=5){
    G_factor = (pink_g*i);
    B_factor = (pink_b*i);
    analogWrite(G, (int)G_factor);
    analogWrite(B, (int)B_factor);
    analogWrite(R, i);
    delay(50);
  }
  for(int i = 255; i >= 70; i-=5){
    G_factor = (pink_g*i);
    B_factor = (pink_b*i);
    analogWrite(G, (int)G_factor);
    analogWrite(B, (int)B_factor);
    analogWrite(R, i);
    delay(50);
  }
  delay(250);
  analogWrite(G, 0);
  for(int i = 70; i <= 255; i+=5){
    R_factor = (purple_r*i);
    B_factor = (purple_b*i);
    analogWrite(B, (int)B_factor);
    analogWrite(R, (int)R_factor);
    delay(50);
  }
  for(int i = 255; i >= 70; i-=5){
    R_factor = (purple_r*i);
    B_factor = (purple_b*i);
    analogWrite(B, (int)B_factor);
    analogWrite(R, (int)R_factor);
    delay(50);
  }
  delay(250);
  analogWrite(R,0);
  analogWrite(G,0);
  for(int i = 70; i <= 255; i+=5){
    analogWrite(B, i);
    delay(50);
  }
  for(int i = 255; i >= 70; i-=5){
    analogWrite(B, i);
    delay(50);
  }
  delay(250);
}

void pred(){
  for(int i = 0; i <= 255; i += 5){
    analogWrite(R, i);
  }
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(R, i);
  }
}

void pblue(){
  for(int i = 0; i <= 255; i += 5){
    analogWrite(B, i);
  }
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(B, i);
  }
}

void pgreen(){
  for(int i = 0; i <= 255; i += 5){
    analogWrite(G, i);
  }
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(G, i);
  }
}
