void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);
}

unsigned long timeNow = millis() ;
unsigned long timePrev = millis();
float pepino = 0.16*3.14;
float velocidade = 0;
int val = 1;
int valAnt = 1;

void loop() {

  val = digitalRead(7);
  if(val == 1 && valAnt == 0 && (millis() - timePrev) > 10)
    valAnt = 1;
  if(val==0 && valAnt==1 && (millis() - timePrev) > 10){
      valAnt = val;
      timeNow = millis();
      velocidade = (pepino*1000)/((timeNow - timePrev));
      timePrev = timeNow;
      Serial.println(velocidade);
      delay(300);
  }
    
}
