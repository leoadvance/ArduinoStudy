#include "TimerOne.h"

void setup()
{
  int tickEvent;
  
  // 新建串口
  Serial.begin(115200);

  pinMode(13, OUTPUT);

  // 初始化定时器 单位us 周期0.1s。 最大 8388.608mS
  Timer1.initialize(100000); 

  // 定时器1 回调函数
  Timer1.attachInterrupt(Timer1_Callback);  
  
}
void Timer1_Callback()
{
  // 翻转
  digitalWrite(13, digitalRead(13) ^ 1);
}
void loop() 
{
  Serial.print("Hello!\r\n");
  delay(1000);
}
