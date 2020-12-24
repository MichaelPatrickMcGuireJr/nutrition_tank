#include <Arduino.h>

int PhSense = A0;
int TempSense = A1;
int samples = 10;

float adc_resolution = 1024.0;

void setup()
{
  Serial.begin(9600);
//  adc_resolution(8);
  delay(100);
  Serial.println("read PH-4502C");
}

float ph_val (float Ph_Voltage) 
{
  return 7 + ((2.5 - Ph_Voltage) / 0.18);
}

void loop () 
{


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

delay(1000);



  /*
  int measurings=0;
  for (int i = 0; i < samples; i++)
  {
    measurings += analogRead(pHSense);
    delay(10);
  }
  float voltage = 5 / adc_resolution * measurings/samples;
  Serial.print("pH= ");
  Serial.println(ph(voltage));
  delay(3000);
  */
}
