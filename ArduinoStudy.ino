#include "TimerOne.h"
unsigned long iPeriod = 1000;
void setup()
{
  
  // 新建串口
  Serial.begin(115200);

  // 设置13为 output
  pinMode(13, OUTPUT);

  // 初始化定时器 单位us 周期0.1s。 最大 8388.608mS
  Timer1.initialize(1000000); 

  // 定时器1 回调函数
  Timer1.attachInterrupt(Timer1_Callback);  

  // 10bit占空比 此处改Period会同步改变Timer1 Period
  Timer1.pwm(9, 102, iPeriod);  
  Timer1.pwm(10, 204);  
  
}
void Timer1_Callback()
{
  // 翻转
  digitalWrite(13, digitalRead(13) ^ 1);

  // 动态修改Period
  iPeriod += 1000;
  Timer1.setPeriod(iPeriod);
  if (iPeriod >= 8000000)
  {
    iPeriod = 1000;
  }
}
void loop() 
{
  Serial.println(iPeriod);
  Serial.print("Hello!\r\n");
  delay(1000);
}
