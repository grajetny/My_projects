#define potenc_blue A0
#define potenc_green A1
#define potenc_red A2

#define latch_blue 7
#define latch_red 6
#define latch_green 5

#define rx_0 13
#define rx_1 12
#define rx_2  8

#define pwm_red 9
#define pwm_green 10
#define pwm_blue 11

int sig_red = 0;
int sig_green = 0;
int sig_blue = 0;


int green = 0;
//int blue = 0;
//int red = 0;

bool green_stan = false;
bool red_stan = false;
bool blue_stan = false;


void setup() {

  Serial.begin(9600);

pinMode(latch_blue, OUTPUT);
pinMode(latch_red, OUTPUT);
pinMode(latch_green, OUTPUT);

digitalWrite(latch_blue, HIGH);
digitalWrite(latch_red, HIGH);
digitalWrite(latch_green, HIGH);

pinMode(rx_0, INPUT); //wejscie radio
pinMode(rx_1, INPUT);
pinMode(rx_2, INPUT);

}

void loop() {

  if(digitalRead(rx_0)){
    green_stan =! green_stan;
    }

  if(digitalRead(rx_1)){
    red_stan =! red_stan;
    }

  if(digitalRead(rx_2)){
    blue_stan =! blue_stan;
    }

  sig_red = map(analogRead(potenc_red), 0, 1023, 0, 255);
  sig_green = map(analogRead(potenc_green), 0, 1023, 0, 255);
  sig_blue = map(analogRead(potenc_blue), 0, 1023, 0, 255);
  
  analogWrite(pwm_red, sig_red);
  //analogWrite(pwm_green, sig_green);
  analogWrite(pwm_blue, sig_blue);
  
  digitalWrite(latch_blue, blue_stan);
  digitalWrite(latch_red, red_stan);
  digitalWrite(latch_green, green_stan);

  Serial.print("rx0 = ");
  Serial.print(green_stan);

  Serial.print("  rx1 = ");
  Serial.print(red_stan);

  Serial.print("  rx2 = ");
  Serial.print(blue_stan);

  Serial.print("  Analog_red = ");
  Serial.print(analogRead(potenc_red));

  Serial.print("  Analog_green = ");
  Serial.print(analogRead(potenc_green));

  Serial.print("  Analog_blue = ");
  Serial.println(analogRead(potenc_blue));

  

  delay(500);

}
