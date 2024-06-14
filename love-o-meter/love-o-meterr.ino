float calc;
int switchpin = A0;
float voltage;
float temprature;
float start_temp = 20.0;
int led1 = 12;
int led2 = 13;
int led3 = 11;

void setup() {
  // put your setup code here, to run once:
 pinMode(switchpin, INPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 Serial.begin(9600);
}

void loop() {
calc = analogRead(switchpin);
Serial.println(calc);
voltage = (calc/1024.0) * 5.0;

Serial.print("Volts : ");
Serial.println(voltage);

Serial.print("Degrees C : ");
temprature = (voltage - .5) * 100;
Serial.println(temprature);
delay(500);

if (temprature < start_temp+2){
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
}

else if (temprature >= start_temp+2 && temprature < start_temp+4 ){
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
}
else if (temprature >= start_temp+4 && temprature < start_temp+6 ){
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, LOW);
}
else if (temprature >= start_temp+6 ){
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
}
}
