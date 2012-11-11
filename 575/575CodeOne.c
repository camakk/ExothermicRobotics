#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
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
#pragma config(Motor,  port1,           RF,            tmotorVex393, openLoop)
#pragma config(Motor,  port2,           LF,            tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           LB,            tmotorVex393, openLoop)
#pragma config(Motor,  port4,           RB,            tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           LArm1,         tmotorVex393, openLoop)
#pragma config(Motor,  port6,           LArm2,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           RArm1,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           RArm2,         tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


// Basically smooths the data received from the controller.
// Uses a cubic function to make the acceleration smooth and not jerky or sudden.
int cubicMap(int x)
{
	return ((((x*3)/25)*((x*3)/25)*((x*3)/25)/27 + x/2)*2)/3;
}




// All activities that occur before the competition starts
// Example: clearing encoders, setting servo positions, ...
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
}




// Code for autonomous
task autonomous()
{
		// ADD AUTONOMOUS CODE HERE
}



task usercontrol()
{
	while (true)
	{


    		// Basic Mecanum Movement
		int channel1 = cubicMap(vexRT[Ch1]);
    		int channel3 = cubicMap(vexRT[Ch3]);
    		int channel4 = cubicMap(vexRT[Ch4]);
    		motor(RF) = channel3 - channel4 - channel1;
    		motor(LB) = channel3 - channel4 + channel1;
    		motor(RB) = channel3 + channel4 - channel1;
    		motor(LF) = channel3 + channel4 + channel1;



    		// Basic Arm Movement
    		if (vexRT[Btn6D] == 1)			// lower the arm
    		{
    			motor(RArm1) = 127;
    			motor(RArm2) = 127;
    			motor(LArm1) = -127;
    			motor(LArm2) = -127;
    		}
		else if (vexRT[Btn6U] == 1)		// raise the arm
    		{
     			motor(RArm1) = -127;
      			motor(RArm2) = -127;
      			motor(LArm1) = 127;
      			motor(LArm2) = 127;
    		}
    		else					// supply no current to the arm
  		{
      			motor(RArm1) = 0;
      			motor(RArm2) = 0;
      			motor(LArm1) = 0;
      			motor(LArm2) = 0;
    		}


		// Basic Pneumatic Firing
		if(vexRT[Btn7D])
		{
			// FIRE THE PISTON!!
		}
		else if(vexRT[Btn7U])
		{
			// FIRE THE PISTON THE OTHER WAY!
		} else {
			// LOL NO PISTON FIRING HERE
		}


	}
}
