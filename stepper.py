from time import sleep
import RPi.GPIO as GPIO

STEP_PIN = 4
DIR_PIN = 17
ENABLE_PIN = 2

CW = 1
CCW = 0
STEP_COUNT = 100*165
# STEP_COUNT = 100*165

GPIO.setmode(GPIO.BCM)
GPIO.setup(DIR_PIN, GPIO.OUT)
GPIO.setup(STEP_PIN, GPIO.OUT)
GPIO.setup(ENABLE_PIN, GPIO.OUT)


delay = .0208

curtainsOpen = False

# NOTE: original code from Arduino sketch w/ steps to close curtains
# void closeCurtain(){
#   if (opened == true) {
#     digitalWrite(enablePin, LOW);
#     delayMicroseconds(2);
#     digitalWrite(dirPin, HIGH);
#     for(int i=0; i<=100*165; i++) {
#       digitalWrite(stepPin, HIGH);
#       delayMicroseconds(700);
#       digitalWrite(stepPin, LOW);
#       delayMicroseconds(2);
#     }
#     digitalWrite(enablePin, HIGH);
#     delayMicroseconds(2);
#     opened = false;
#   }
# }

GPIO.output(DIR_PIN, CW)
# enable the driver
GPIO.output(ENABLE_PIN, GPIO.LOW)

for step in range(STEP_COUNT):
	GPIO.output(STEP_PIN, GPIO.HIGH)
	sleep(delay)
	GPIO.output(STEP_PIN, GPIO.LOW)
	sleep(delay)

GPIO.cleanup()
# open and close logic/functions
# connection to wifi
# checking sunset times
# setting an alarm time/on off scheduling
# app?
