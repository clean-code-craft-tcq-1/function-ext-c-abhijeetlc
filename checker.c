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
#define MAXTEMP 45.0
#define MINTEMP 0
#define MAXSOC 80.0
#define MINSOC 20.0


/*Battery Parameter Low Check - generic function */
/* Arguement : InPut Parameter , MinVal , MaxVal  */

int checkBattParameterLow(float VALUEIN,float Const_Min)
{
  if(VALUEIN <= Const_Min )
    {
        return 1;
    }
    else
    {
        return 0;
    }
	
}

/*Battery Parameter High Check - generic function */
/* Arguement : InPut Parameter , MinVal , MaxVal  */

int checkBattParameterHigh(float VALUEIN,float Const_Max)
{
	if( VALUEIN > Const_Max )
    {
        return 1;
    }
    else
    {
        return 0;
    }
	
	
}

/* Check for temperature range */
/* Arguement : Temperature  */
int checktemperature(float TempIn)
{
	int TempValueLowCheck = checkBattParameterLow(TempIn,MINTEMP);
	int TempValueHighCheck = checkBattParameterHigh(TempIn,MAXTEMP);
	if (!( TempValueLowCheck + TempValueHighCheck))
  {
    printf(" The current Battery temperature is %f. OK \n", TempIn);
    return 0;
  } 
  printf("Battery Temperature is %f. Out of range!\n", TempIn);
  return 1;

}

/* Check for Charge rate */
/* Arguement : ChargeRate  */
int CheckChargeRate(float chargeRate)
{
	 if(chargeRate>MAXCHARGERATE)
	   {
		printf("Charge Rate is %f. Out of range!\n", chargeRate);
		return 1;
	   }
	printf("Charge Rate is %f . OK \n", chargeRate);  
	return 0;
}

/* Check for SOC status */
 /* Arguement : SOC  */
int Checksoc(float SOCIn)
{
  int socValueLowCheck= checkBattParameterLow(SOCIn,MAXSOC);
  int socValueHighCheck= checkBattParameterHigh(SOCIn,MAXSOC);
  if (!(socValueLowCheck + socValueHighCheck))
  {
     printf("State of Charge is %f percent.OK!\n",SOCIn);
	 
     return 0;
  }
  printf("SOC value is %f. Out of range!\n", SOCIn);
  return 1;
}

/* Battery overall check */
/* Arguement : Temperature  , SOC , Chanrgerate */
int checkBattery(float TempIn, float SOCIn, float chargeRate) {
  
  int BatteryState = 0;
  
  int socstatus,temperaturecheck,chargeratecheck;
  
     socstatus = Checksoc(SOCIn); 
     chargeratecheck = CheckChargeRate(chargeRate);
     temperaturecheck = checktemperature(TempIn);
     BatteryState = !(socstatus + chargeratecheck + temperaturecheck);
     return (BatteryState);
 
}


/*  Main function to call test cases  */

int main() {
	
  assert(checkBattery(25, 70, 0.6));
  assert(!checkBattery(50, 85, 0));
  assert(!checkBattery(0, 0, 0));
  assert(!checkBattery(100, 100, 100));
  assert(checkBattery(30, 40, 0.5));
	
	
}
