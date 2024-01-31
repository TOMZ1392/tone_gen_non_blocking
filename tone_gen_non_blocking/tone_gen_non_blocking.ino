
#define BUZZER_PIN   8

#define BUZZER_TONE_INTERVAL   700
#define BUZZER_HIGH_TIME_1 300
#define BUZZER_LOW_TIME_1 50
#define BUZZER_HIGH_TIME_2 200
#define BUZZER_LOW_TIME_2 50
void generateAlarm()
{
  static bool hightone = false;
  static long startTime = millis();
  if (millis() - startTime <= BUZZER_TONE_INTERVAL) {
    if (hightone) {
      digitalWrite(BUZZER_PIN, 1);
      delayMicroseconds(BUZZER_HIGH_TIME_1);
      digitalWrite(BUZZER_PIN, 0);
      delayMicroseconds(BUZZER_LOW_TIME_1);

    }
    else {
      digitalWrite(BUZZER_PIN, 1);
      delayMicroseconds(BUZZER_HIGH_TIME_2);
      digitalWrite(BUZZER_PIN, 0);
      delayMicroseconds(BUZZER_LOW_TIME_2);

    }

  }
  else {
    if (hightone) {
      hightone = false;
    } else {
      hightone = true;
    }
    startTime = millis();
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {


}
