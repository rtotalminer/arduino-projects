#include <math.h>

#include <max7219.h>
#define LEFT 0
#define RIGHT 1

MAX7219 max7219;

long MAX_NUMBER = 99999999;


int good_fib()
{
  String s_Fn;
  char c_Fn[8];
  long n1 = 0, n2 = 1, n3;

  for (int i=2; i < 100; i++)
  {
    n3 = n1 + n2;

    s_Fn = String(n3);
    if (s_Fn.length() > 8)
    {
      max7219.Clear();
      s_Fn = String(i);
      s_Fn.toCharArray(c_Fn, s_Fn.length()+1);

      max7219.DisplayText(c_Fn, RIGHT);
      max7219.DisplayText("COUNT-", LEFT);
      delay(2500);
      return 0;
    }
    s_Fn.toCharArray(c_Fn, s_Fn.length()+1);

    max7219.DisplayText(c_Fn, RIGHT);
    delay(1000);

    n1 = n2;
    n2 = n3;
  }
  return 0;
}

void setup() {
  Serial.begin(9600);
  max7219.Begin();
}

void loop() {
  max7219.Clear();
  good_fib();
  max7219.Clear();
}
