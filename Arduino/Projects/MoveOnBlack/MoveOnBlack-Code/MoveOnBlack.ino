static int LB = 1000;
static int RB = 2000;

static int LF = 2000; // right
static int RF = 1000; // left

static int LStop = 1500;
static int RStop = 1500;

void setup() {
  // put your setup code here, to run once:
InitEmoro();
EmoroServo.attach(SERVO_0);
EmoroServo.attach(SERVO_1);
Ultrasonic.attach(GPP_0);

Serial.begin(9600);
Serial.println("Example: IR + servo");

pinMode(IO_0, INPUT_PULLUP); // Right
pinMode(IO_1, INPUT_PULLUP); // left
pinMode(GPP_0, INPUT_PULLUP);



}

void loop() {
  // put your main code here, to run repeatedly:

// 1 == white && 0 == black

Serial.println(Ultrasonic.read(GPP_0));

if  (Ultrasonic.read(GPP_0) > 1 && Ultrasonic.read(GPP_0) < 20)

{
  // turn Right
EmoroServo.write(SERVO_0, LStop);
EmoroServo.write(SERVO_1, RF);
delay(750);

// go forwerd
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RF);
delay(1000);

// turn Left
EmoroServo.write(SERVO_0, RB);
EmoroServo.write(SERVO_1, LF);
delay(450);

// go forwerd
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RF);
delay(2000);

// turn Left
EmoroServo.write(SERVO_0, RB);
EmoroServo.write(SERVO_1, LF);
delay(450);

// go forwerd
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RF);
delay(1000);

  // turn Right
EmoroServo.write(SERVO_0, LStop);
EmoroServo.write(SERVO_1, RF);
delay(750);

/*// tuen right
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RStop);
delay(500);

// go forwerd
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RF);
delay(500);*/

}

else if (digitalRead(IO_0) == 1 && digitalRead(IO_1) == 1) 
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
EmoroServo.write(SERVO_0, LF);
EmoroServo.write(SERVO_1, RStop);

}

else if (digitalRead(IO_1) == 0 && digitalRead(IO_0) == 1)
{
EmoroServo.write(SERVO_0, LStop);
EmoroServo.write(SERVO_1, RF);

}


}
