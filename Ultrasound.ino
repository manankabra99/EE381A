int t1 = 11; // triggerPin for sensor1
int e1 = 10; // echoPin for sensor1
int t2 = 9; // triggerPin for sensor2
int e2 = 8; // echoPin for sensor2
float dur1, dur2, dur3, dur4;
int dist1, dist2, dist3, dist4;
void setup() {
  Serial.begin(9600); // set Baud rate for serial communication
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(e2, INPUT);
}

int find_dist(int t, int e){
   digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  float dur = pulseIn(e, HIGH);
  
  int ans = dur*0.017;
  return ans;     
}

void loop() {
  // digitalWrite(t1, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(t1, LOW);
  // dur1 = pulseIn(e1, HIGH);
  
  // digitalWrite(t2, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(t2, LOW);  
  // dur2 = pulseIn(e2, HIGH);
  
  // delay(200);
  
  // digitalWrite(t1, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(t1, LOW);
  // dur3 = pulseIn(e1, HIGH);
  
  // digitalWrite(t2, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(t2, LOW);  
  // dur4 = pulseIn(e2, HIGH);
  
  dist1 = 0.017*dur1;
  dist2 = 0.017*dur2;
  dist3 = 0.017*dur3;
  dist4 = 0.017*dur4;

  dist1 = find_dist(t1, e1);
  dist2 = find_dist(t2, e2);
  //delay(200);
  dist3 = find_dist(t1, e1);
  dist4 = find_dist(t2, e2);
  int key = 0;
  Serial.print(dist1);
  Serial.print(" ");
  Serial.print(dist2);
  Serial.print(" ");
  Serial.print(dist3);
  Serial.print(" ");
  Serial.print(dist4);
  Serial.print("    ");
  if((dist1 > 30 && dist3 > 30) && (dist2 > 30 && dist4 > 30)){
    //delay(2000);
  }
  else{
    if(dist1 <= 30 && dist2 <= 30 && dist3 <= 30 && dist4 <= 30){
      // if(dist1 <= 15 && dist2 <= 15){
      //   key = 1;
      // }
      // else{
      //   key = 2;
      // }
      key = 1;
    }

    else if(dist1 <= 30 && dist3 <= 30){
      key = 2;
    }
    
    else if(dist2 <= 30 && dist4 <= 30){
      key = 3;
    }

    else if(dist1 <= 15 && dist2 > 15 && dist3 > 15 && dist4 <= 15){
      key = 7;
    }

    // else if(dist1 > 60 && dist2 <= 60 && dist3 <= 60 && dist4 < 60){
    //   key = 8;
    // }
    
    // else if(dist1 <= 60){
    //   int dists[6];
    //   dists[0] = dist1;
    //   for(int i = 0; i < 5; i++){
    //     delay(100);
    //     digitalWrite(t1, HIGH);
    //     delayMicroseconds(10);
    //     digitalWrite(t1, LOW);

    //     dur1 = pulseIn(e1, HIGH);
    //     dists[i+1] = 0.017*dur1;
    //   }

    //   int c = 1;
    //   for(int i = 1; i < 6; i++){
    //     if(dists[i] > dists[i-1]){
    //       c = 0;
    //     }
    //   }    
    //   if(c == 1){
    //     key = 3;
    //   }

    //   c = 1;
    //   for(int i = 1; i < 6; i++){
    //     if(dists[i] < dists[i-1]){
    //       c = 0;
    //     }
    //   }
    //   if(c == 1){
    //     key = 4;
    //   }
    // }

    // else if(dist2 <= 100){
    // //   int dists[6];
    // //   dists[0] = dist2;
    // //   for(int i = 0; i < 5; i++){
    // //     delay(100);
    // //     digitalWrite(t2, HIGH);
    // //     delayMicroseconds(10);
    // //     digitalWrite(t2, LOW);

    // //     dur1 = pulseIn(e2, HIGH);
    // //     dists[i+1] = 0.017*dur1;
    // //   }
    // //   Serial.println();
    // //   Serial.print("Dist Array - ");
    // //   for(int i = 0; i < 6; i++){
    // //     Serial.print(dists[i]);
    // //     Serial.print("  ");
    // //   }
    // //   Serial.println();

      

    // //   int c = 1;
    // //   for(int i = 1; i < 6; i++){
    // //     if(dists[i] > dists[i-1]){
    // //       c = 0;
    // //     }
    // //   }    
    // //   if(c == 1){
    // //     key = 5;
    // //   }

    // //   c = 1;
    // //   for(int i = 1; i < 6; i++){
    // //     if(dists[i] < dists[i-1]){
    // //       c = 0;
    // //     }
    // //   }
    // //   if(c == 1){
    // //     key = 6;
    // //   }
    // // }
    //   delay(500);
    //   digitalWrite(t2, HIGH);
    //   delayMicroseconds(10);
    //   digitalWrite(t2, LOW);

    //   dur1 = pulseIn(e2, HIGH);
    //   int dist_new = 0.017*dur1;
    //   Serial.println();
    //   Serial.print("dist_new    - ");  

    //   Serial.print(dist_new);
    //   Serial.print(" ");  
    //   Serial.print(dist2);
    //   Serial.print("   ");  


    //   if(dist_new - dist2 >= 15){
    //     key = 5;
    //   }
    //   else if(dist_new - dist2 <= (-1)*15){
    //     key = 6;
    //   }
    //   else{
    //     key = 9;
    //   }
    // }
  }

  // ________ d1 d2 ___ d3 d4 ____d1 d2_____d3 d4__

  Serial.println(key);
  delay(2000);
}

