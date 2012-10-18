#pragma config(UART_Usage, UART1, VEX_2x16_LCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in2,    AutoPot1,       sensorPotentiometer)
#pragma config(Sensor, in3,    AutoPot2,       sensorPotentiometer)
#pragma config(Sensor, in4,    ArmPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  Button1,        sensorTouch)
#pragma config(Sensor, dgtl2,  Button2,        sensorTouch)
#pragma config(Sensor, dgtl3,  Button1Top,     sensorTouch)
#pragma config(Sensor, dgtl4,  Button2Top,     sensorTouch)
#pragma config(Sensor, dgtl5,  Quad2,          sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  Quad3,          sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Quad4,          sensorQuadEncoder)
#pragma config(Sensor, dgtl11, Quad5,          sensorQuadEncoder)
#pragma config(Motor,  port1,           LF,            tmotorVex393, openLoop)
#pragma config(Motor,  port2,           RF,            tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           LB,            tmotorVex393, openLoop)
#pragma config(Motor,  port4,           RB,            tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           Arm1,          tmotorVex393, openLoop)
#pragma config(Motor,  port7,           Arm2,          tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           Roll1,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           Roll2,         tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

int cubicMap(int x)
{
       return ((((x*3)/25)*((x*3)/25)*((x*3)/25)/27 + x/2)*2)/3;
}

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

// void test()
// {
  // clearLCDLine(1);
  // displayLCDCenteredString(1, "hello, world");
// }

//Autonomous
int auto()
{
  int a = -2;
  int b = -2;
  int c = -2;
  //- minus
  if (SensorValue[AutoPot1] >= 1150)
  {
    a = 0;
  }
  //+ plus
  if (SensorValue[AutoPot1] <= 1150)
  {
    a = 1;
  }
  //- minus
  if (SensorValue[AutoPot2] >= 2350)
  {
    b = 2;
  }
  //+ plus
  if (SensorValue[AutoPot2] <= 2350)
  {
    b = 4;
  }
  return a+b;
}
//++5programming skills  +-3isolation red  -+4isolation blue  --2nothing

void drive(int x)
{
      motor[LB] = 127;
      motor[LF] = 127;
      motor[RB] = 127;
      motor[RF] = 127;
      wait1Msec(x);
}
task autonomous()
{
  clearLCDLine(1);
  clearLCDLine(2);
  clearLCDLine(3);
  int c = auto();
  while(true)
  {
  if (c == 5)
  {
    displayLCDCenteredString(1,"Programming Skills");
    while(true)
    {
      if (SensorValue[Button1] == 1)
      {
        while (SensorValue[Button1] == 1)
        {
        motor[Roll1] = -127;
        motor[Roll2] = -127;
        }
        motor[Roll1] = 0;
        motor[Roll1] = 0;
      }
      if (SensorValue[Button2] == 1)
      {
        //drive(x);
      }
    }
    //programming skills
  }
  if (c == 4)
  {
    displayLCDCenteredString(1,"Isolation Blue");
    if (SensorValue[Button2Top] == 1)
    {
      motor[Roll1] = -127;
      motor[Roll2] = -127;
      wait1Msec(200);
      motor[Roll1] = 127;
      motor[Roll2] = 127;
      wait1Msec(200);
      //go 55 inches
      motor[Roll1] = -127;
      motor[Roll2] = -127;
      drive(1847);
      //go back
      motor[LB] = -127;
      motor[LF] = -127;
      motor[RB] = -127;
      motor[RF] = -127;
      motor[Roll1] = 0;
      motor[Roll2] = 0;
      wait1Msec(1847);
      motor[LB] = 0;
      motor[LF] = 0;
      motor[RB] = 0;
      motor[RF] = 0;
      //reposition
      wait1Msec(4000);
      motor[LB] = 127;
      motor[LF] = -127;
      motor[RB] = -127;
      motor[RF] = 127;
      motor[Arm1] = -127;
      motor[Arm2] = -127;
      wait1Msec(396);
      //drive
      drive(789);
      motor[Roll1] = 127;
      motor[Roll2] = 127;
      motor[LB] = 0;
      motor[LF] = 0;
      motor[RB] = 0;
      motor[RF] = 0;
      wait1Msec(1500);
    }
  }
  if (c == 3)
  {
    displayLCDCenteredString(1,"Isolation Red");
    if (SensorValue[Button2Top] == 1)
    {
      motor[Roll1] = -127;
      motor[Roll2] = -127;
      wait1Msec(200);
      motor[Roll1] = 127;
      motor[Roll2] = 127;
      wait1Msec(200);
      //go 55 inches
      motor[Roll1] = -127;
      motor[Roll2] = -127;
      drive(1847);
      //go back
      motor[LB] = -127;
      motor[LF] = -127;
      motor[RB] = -127;
      motor[RF] = -127;
      motor[Roll1] = 0;
      motor[Roll2] = 0;
      wait1Msec(1847);
      motor[LB] = 0;
      motor[LF] = 0;
      motor[RB] = 0;
      motor[RF] = 0;
      //reposition
      wait1Msec(4000);
      motor[LB] = -127;
      motor[LF] = 127;
      motor[RB] = 127;
      motor[RF] = -127;
      motor[Arm1] = -127;
      motor[Arm2] = -127;
      wait1Msec(396);
      //drive
      drive(789);
      motor[Roll1] = 127;
      motor[Roll2] = 127;
      motor[LB] = 0;
      motor[LF] = 0;
      motor[RB] = 0;
      motor[RF] = 0;
      wait1Msec(1500);
    }
  }
}
}

task usercontrol()
{


	while (true)
	{
    //Movement
    int channel1 = cubicMap(vexRT[Ch1]);
    int channel3 = cubicMap(vexRT[Ch3]);
    int channel4 = cubicMap(vexRT[Ch4]);
    motor(RF) = channel3 - channel4 - channel1;
    motor(LB) = channel3 - channel4 + channel1;
    motor(RB) = channel3 + channel4 - channel1;
    motor(LF) = channel3 + channel4 + channel1;

    //Lift
    if (vexRT[Btn5D] == 1 || vexRT[Btn5U] == 1)
    {
      if (vexRT[Btn5D] == 1)
      {
        motor(Arm1) = 127;
        motor(Arm2) = 127;
      }
      if (vexRT[Btn5U] == 1)
      {
        motor(Arm1) = -127;
        motor(Arm2) = -127;
      }
    }
    else
    {
      motor(Arm1) = 0;
      motor(Arm2) = 0;
    }

  //Rollers
  if (vexRT[Btn6D] == 1 || vexRT[Btn6U] == 1)
  {
    if (vexRT[Btn6D] == 1)
    {
      motor(Roll1) = 70;
      motor(Roll2) = 70;
    }
    if (vexRT[Btn6U] == 1)
    {
      motor(Roll1) = -127;
      motor(Roll2) = -127;
    }
  }
  else
  {
    motor(Roll1) = 0;
    motor(Roll2) = 0;
  }

    //Arm Presets
    // while (vexRT[Btn7U] == 1)
    // {
      // if (SensorValue[ArmPot] > 300)
      // {
          // motor[Arm1] = -127;
          // motor[Arm2] = -127;
      // }
      // if (SensorValue[ArmPot] < 300)
      // {
          // motor[Arm1] = 127;
          // motor[Arm2] = 127;
      // }
          // motor[Arm1] = 0;
          // motor[Arm2] = 0;
    // }
    // while (vexRT[Btn7D] == 1)
    // {
      // if (SensorValue[ArmPot] > 200)
      // {
        // while(SensorValue[ArmPot] > 200)
        // {
          // motor[Arm1] = -127;
          // motor[Arm2] = -127;
        // }
      // }
      // if (SensorValue[ArmPot] < 200)
      // {
        // while (SensorValue[ArmPot] < 200)
        // {
          // motor[Arm1] = 127;
          // motor[Arm2] = 127;
        // }
      // }
          // motor[Arm1] = 0;
          // motor[Arm2] = 0;
     // }
	}
}
