#define echoPin 9
#define trigPin 10

#define speedControl 3
#define motorPin1 4
#define motorPin2 5

#define ledPin 13

long dangerDistance = 3.5;

void setup()
{
    Serial.begin(9600);

    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);

    pinMode(speedControl, OUTPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);

    pinMode(ledPin, OUTPUT);

    digitalWrite(motorPin2, HIGH);
}

void loop()
{
    long distance = getDistanceFromSensor(echoPin, trigPin);
    Serial.println(distance);

    if (distance < dangerDistance)
    {
        analogWrite(speedControl, 200);
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        analogWrite(speedControl, 0);
        digitalWrite(ledPin, LOW);
    }
}

long getDistanceFromSensor(int echo, int trig)
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    unsigned long duration = pulseIn(echo, HIGH);
    long distance = (duration * 0.034 / 2);
    int offset = distance * 0; //0.03

    distance += offset;
    return distance;
}
