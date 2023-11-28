const int trig1 = 9;
const int echo1 = 8;
const int trig2 = 11;
const int echo2 = 10;
int led1 = 3;
int led2 = 5;
int key, pw;
int out1 = 1;
int out2 = 1;
int pow1 = 80;
int pow2 = 80;
long dur;
int dist1, dist2;
float r;
unsigned long temp = 0;
int old_dist = 0, l = 0;

void find_distance(void){
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  
  dur = pulseIn(echo1, HIGH, 5000);

  r = 3.4*dur/2;
  dist1 = r/100.0;

  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  dur = pulseIn(echo2, HIGH, 5000);

  r = 3.4*dur/2;
  dist2 = r/100.0;
  delay(100);
}
void setup() {
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  analogWrite(led2, pow2);
  analogWrite(led1, 120);
}

void loop() {
  find_distance();
  key = 0;
  
  if(dist2 <= 35 && dist2 >= 5){
    delay(100);
    temp = millis();
    int k = 0, checker = 0;
    while(millis() <= (temp + 300)){
      find_distance();
    }
    
    if(dist2 <= 35 && dist2 >= 5){
      int old_dist = dist2;
      while((dist2 <= 50 || dist2 == 0) && k < 10){
        find_distance();
        if((old_dist + 8) < dist2){
          checker++;
        }
        else if((old_dist - 8) > dist2){
          checker--;
        }
        k++;
      }
      if(checker == 0){
        key = 1;
        Serial.println("Next");
      }
      else if(checker > 0){
        key = 2;
        pw = checker;
        while(checker){
          checker--;   
          Serial.println("Down");        
        }
      }
      else{
        key = 3;
        pw = abs(checker);
        while(checker < 0){
          checker++;
          Serial.println("Up");
        }
      }
    }
  }

  if(dist1 <= 35 && dist1 >= 5){
    delay(100);
    temp = millis();
    int k = 0, checker = 0;
    while(millis() <= (temp + 300)){
      find_distance();
    }
    
    if(dist1 <= 35 && dist1 >= 5){
      int old_dist = dist1;
      while((dist1 <= 50 || dist1 == 0) && k < 10){
        find_distance();
        if((old_dist + 8) < dist1){
          checker++;
        }
        else if((old_dist - 8) > dist1){
          checker--;
        }
        k++;
      }
      if(checker == 0){
        key = 4;
        Serial.println("Doosra Next");
      }
      else if(checker > 0){
        key = 5;
        pw = checker;
        while(checker){
          checker--;   
          Serial.println("Doosra Down");        
        }
      }
      else{
        key = 6;
        pw = abs(checker);
        while(checker < 0){
          checker++;
          Serial.println("Doosra Up");
        }
      }
    }
  }

  else{
    Serial.println("Kuch nahi hua");
  }
  if(key == 0){
    loop();
  }
  else if(key == 1){
    out1 = (out1 + 1)%2;
    if(out1){
      analogWrite(led1, pow1);      
    }
    else{
      analogWrite(led1, 0);
    }
  }
  else if(key == 2){
    if(out1){
      pow1 = max(5, pow1 - 10*pw);      
      analogWrite(led1, pow1);        
    }
  }
  else if(key == 3){
    if(out1){
      pow1 = min(255, pow1 + 10*pw);
      analogWrite(led1, pow1);  
    }
  }
  else if(key == 4){
    out2 = (out2 + 1)%2;
    if(out2){
      analogWrite(led2, pow2);      
    }
    else{
      analogWrite(led2, 0);
    }
  }
  else if(key == 5){
    if(out2){
      pow2 = max(5, pow2 - 15*pw);      
      analogWrite(led2, pow2); 
    }
  }
  else{
    if(out2){
      pow2 = min(255, pow2 + 15*pw);
      analogWrite(led2, pow2);
    }
  }
  delay(50);
}
