/* Author : Abhijeet C */
/* Program : Primitive BMS simulation */

/* Includes */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* defines */

#define MAXCHARGERATE 0.8
#define MAXTEMP 45
#define MINTEMP 0
#define MAXSOC 80
#define MINSOC 20


/* Check for temperature range */
/* Arguement : Temperature  */
int checktemperature(float TempIn)
{
	int TempValue = ((MINTEMP < TempIn) || (TempIn < MAXTEMP));
	if (TempValue)
  {
    printf(" The current Battery temperature is %f. \n", TempIn);
    return 1;
  } 
  printf("Battery Temperature is %f. Out of range!\n", TempIn);
  return 0;

}

/* Check for Charge rate */
/* Arguement : ChargeRate  */
int CheckChargeRate(float chargeRate)
{
	int chargerate_check=(chargeRate>MAXCHARGERATE);
	 if(chargerate_check)
	   {
		printf("Charge Rate is %f. Out of range!\n", chargeRate);
		return 0;
	   }
	printf("Charge Rate is %f . OK \n", chargeRate);  
	return 1;
}

/* Check for SOC status */
 /* Arguement : SOC  */
int Checksoc(float soc)
{
  int socValue= ((soc < MINSOC) || (soc > MAXSOC));
  if (socValue)
  {
     printf("State of Charge is %f percent.Out of range!\n", soc);
	 
     return 0;
  }
  return 1;
}

/* Battery overall check */
/* Arguement : Temperature  , SOC , Chanrgerate */
int checkBattery(float TempIn, float soc, float chargeRate) {
  
  int BatteryState = 0;
  
  int socstatus,temperaturecheck,chargeratecheck;
  
     socstatus = Checksoc(soc);
     chargeratecheck = CheckChargeRate(chargeRate);
     temperaturecheck = checktemperature(TempIn);
     BatteryState = (socstatus & chargeratecheck & temperaturecheck);
     return (BatteryState);
 
}


/*  Main function to call test cases  */

int main() {
  assert(checkBattery(25, 70, 0.7));
  assert(!checkBattery(50, 85, 0));
}
