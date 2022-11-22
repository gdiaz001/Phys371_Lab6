

unsigned long currentTime = 0; 
unsigned long lastTime = 0; 
const unsigned long intervalBetweenData = 1000; 

const int outPin = 9; 

long int  numDataPoints = 0; 
const long int DataPointsNeeded = 20000; 
  
void setup() {
  // put your setup code here, to run once:

  Serial.begin(500000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(numDataPoints < DataPointsNeeded){
  currentTime = micros();

  tone(outPin,498);
 
  if(currentTime - lastTime >= intervalBetweenData ) {
    int sensorValue = analogRead(A1);
    lastTime += intervalBetweenData; 
    
    numDataPoints +=1; 
 
   
    Serial.print(currentTime/1000); 
    Serial.print(',');
    Serial.println(sensorValue); 
  
  }
  
  }
 
  else{
    exit(0); 
  }
  
}
