int lr;

int n;

int Sonic_Time_out = 40*2*29;

long Sonic_Timing(){
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  long duration = pulseIn(8,HIGH,Sonic_Time_out);
  if ( duration == 0 ){
    duration = Sonic_Time_out;
    digitalWrite(9, HIGH);
    delay(25);
    digitalWrite(9 ,LOW);
    delay(225);
  }
  return duration;
}

// うしろにすすむ
void back() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

// ちょっととまる
void stop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

// とまる
void Freeze() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  while (true) {
  }
}

// まえにすすむ
void forward() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

// ひだりにまがる
void left() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

// みぎにまがる
void right() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  n = 1;
  lr = 0;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}


void loop()
{
  if (Sonic_Timing()/29/2 < 20) {
    stop();
    if (lr == 0) {
      right();
      lr = 1;

    } else {
      left();
      lr = 0;

    }
    delay((2000 * n));
    n = n + 1;
    stop();

  } else {
    lr = 0;
    n = 1;
    forward();
    delay(100);

  }

}