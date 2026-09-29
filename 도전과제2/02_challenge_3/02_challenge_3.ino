#define PIN_LED 7

long pwm_period = 10000;
int pwm_duty = 0;

void set_period(int period)
{
  pwm_period = period;
}

void set_duty(int duty)
{
  pwm_duty = duty;

  long on_time = pwm_period * duty / 100;
  long off_time = pwm_period - on_time;

  unsigned long start_time = micros();

  while (micros() - start_time < 5000)
  {
    
    if (on_time > 0)
    {
      digitalWrite(PIN_LED, LOW);
      delayMicroseconds(on_time);
    }

  
    if (off_time > 0)
    {
      digitalWrite(PIN_LED, HIGH);
      delayMicroseconds(off_time);
    }
  }
}

void setup()
{
  pinMode(PIN_LED, OUTPUT);


  digitalWrite(PIN_LED, HIGH);


  set_period(100);
}

void loop()
{

  for (int duty = 0; duty <= 100; duty++)
  {
    set_duty(duty);
  }

 
  for (int duty = 99; duty >= 0; duty--)
  {
    set_duty(duty);
  }
}