static int LB = 500;
static int RB = 2500;
static int LF = 2500;
static int RF = 500;
static int LStop = 1500;
static int RStop = 1500;

void setup() {
  // put your setup code here, to run once:
InitEmoro();
EmoroServo.attach(SERVO_0);
EmoroServo.attach(SERVO_1);

Serial.begin(9600);
Serial.println("Example: IR + servo");

pinMode(IO_0, INPUT_PULLUP);
pinMode(IO_1, INPUT_PULLUP); 

}

void loop() {
  // put your main code here, to run repeatedly:

// 1 == white && 0 == black

if (digitalRead(IO_0) == 1 && digitalRead(IO_1) == 1) 
{
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RF);
}

else if (digitalRead(IO_0) == 0 && digitalRead(IO_1) == 0)
{
EmoroServo.write(SERVO_0, LStop);
EmoroServo.write(SERVO_1, RStop);
}

else if (digitalRead(IO_0) == 0 && digitalRead(IO_1) == 1)
{
EmoroServo.write(SERVO_0, LB);
EmoroServo.write(SERVO_1, RF);
delay(20);
}

else if (digitalRead(IO_1) == 0 && digitalRead(IO_0) == 1)
{
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RB);
delay(20);
}
}
