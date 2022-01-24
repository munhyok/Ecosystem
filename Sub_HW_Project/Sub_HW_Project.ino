int inputWC;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  
}

void loop() {
  
  if(Serial.available())
  {
    inputWC = Serial.read();
  }

  if(input

  
}
