#include <Arduino.h>

// PH sensors vars
int PhSense = A0;
int TempSense = A1;

// paristaltic pump vars
int pump1_pin = 6;
int pump2_pin = 3;


float adc_resolution = 1024.0;

void setup()
{
  Serial.begin(9600);
  // Serial.println("read PH-4502C");

  Serial.println("write PWM to pumps");
  pinMode(pump1_pin, OUTPUT);
  pinMode(pump2_pin, OUTPUT);

}

float ph_val (float Ph_Voltage) 
{
  return 7 + ((2.5 - Ph_Voltage) / 0.18);
}

void loop () 
{

// controlling parastaltic pumps
  analogWrite(pump1_pin, 0);
  analogWrite(pump2_pin, 0);

/* 
// reading PH meter
// variables holding PH-4502c readings
int measuring_Ph = 0;
int measuring_Temp = 0;

measuring_Ph = analogRead(PhSense);
measuring_Temp = analogRead(TempSense);

// adjust for PH offset
measuring_Ph = measuring_Ph-52;

// get voltage level from analog reads
float voltage_Ph = 5 / adc_resolution * measuring_Ph;
float voltage_Temp = 5 / adc_resolution * measuring_Temp;


// normalize to voltage range for voltage_Temp, then correlate to temperature range
float V_temp = voltage_Temp/5;
float temp_C = V_temp*80;
 
Serial.print(temp_C);
Serial.print(" C\n");
*/



delay(1000);

}
