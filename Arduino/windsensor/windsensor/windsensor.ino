
unsigned int counter = 0;
unsigned int oldcount = 0;
int dir = 0;
unsigned int offset = 0;

void counting(){
  if(digitalRead(8)){
    counter++;
  }
    else{
      counter--;
  }
  counter = counter % 512;
}

void index(){
  //if(counter>450){
  counter = 0;
  //}
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  attachInterrupt(0,counting,RISING);
  attachInterrupt(1,index,RISING);
  Serial.begin(9600);
}

void loop() {
  double printer;
  int analogcount;
  if(Serial.available() > 0){
    Serial.read();
    offset = counter;
  }
  if(oldcount != counter){
    oldcount = counter;
    printer = (counter-offset)%512 * 0.703125;
    analogcount = (counter-offset)%512/2*168/255;
    analogWrite(5,analogcount);
    Serial.print("Count = ");
    Serial.println(analogcount);
    if(printer >= 348.75 || printer < 11.25){
      //N
      Serial.println("N");
    }
    else if(printer >= 11.25 && printer < 33.75){
      //NNE
      Serial.println("NNE");
    }
    else if(printer >= 33.75 && printer < 56.25){
      //NE
      Serial.println("NE");
    }
    else if(printer >= 56.25 && printer < 78.25){
      //ENE
      Serial.println("ENE");
    }
    else if(printer >= 78.75 && printer < 101.25){
      //E
      Serial.println("E");
    }
    else if(printer >= 101.25 && printer < 123.75){
      //ESE
      Serial.println("ESE");
    }
    else if(printer >= 123.75 && printer < 146.25){
      //SE
      Serial.println("SE");
    }
    else if(printer >= 146.25 && printer < 168.75){
      //SSE
      Serial.println("SSE");
    }
    else if(printer >= 168.75 && printer < 191.25){
      //S
      Serial.println("S");
    }
    else if(printer >= 191.25 && printer < 213.75){
      //SSW
      Serial.println("SSW");
    }
    else if(printer >= 213.75 && printer < 236.25){
      //SW
      Serial.println("SW");
    }
    else if(printer >= 236.25 && printer < 258.75){
      //WSW
      Serial.println("WSW");
    }
    else if(printer >= 258.75 && printer < 281.25){
      //W
      Serial.println("W");
    }
    else if(printer >= 281.25 && printer < 303.75){
      //WNW
      Serial.println("WNW");
    }
    else if(printer >= 303.75 && printer < 326.25){
      //NW
      Serial.println("NW");
    }
    else if(printer >= 326.25 && printer < 348.75){
      //NNW
      Serial.println("NNW");
    }
  }
}
