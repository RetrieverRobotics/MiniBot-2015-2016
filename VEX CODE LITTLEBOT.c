#pragma config(Motor,  port2,           RampR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           DriveR1,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           DriveR2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           IntakeL,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           IntakeR,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           DriveL1,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           DriveL2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RampL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

////////////////////////// SOFTWARE DEFINES ////////////////////////////////////

#define DRIVE_DZ 30 // The drive stick deadzone for both sticks

////////////////////////////////////////////////////////////////////////////////
/*
 * Deadzones a joystick input.
 *
 * @param stickValue The raw joystick value.
 * @param dz The lower threshold for input to go through.
 */
int applyDeadzone(int stickValue, int dz)
{
	int abValue = abs(stickValue);

	// If the absolute stick value is below the thresh return 0
	if (abValue < dz)
	{
		return 0;
	}
	else
	{
		return stickValue;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

		//Wheels
		motor[DriveR1] = applyDeadzone(vexRT(Ch2), DRIVE_DZ);
		motor[DriveL1] = applyDeadzone(vexRT(Ch3), DRIVE_DZ);
		motor[DriveR2] = applyDeadzone(vexRT(Ch2), DRIVE_DZ);
		motor[DriveL2] = applyDeadzone(vexRT(Ch3), DRIVE_DZ);

		//Intake
		// Spin the intake motors forward
		if (vexRT[Btn6D] == 1)
		{
			motor[IntakeL] = 127;
			motor[IntakeR] = 127;

		}
		// Spin the intake motors backward
		else if (vexRT[Btn6U] == 1)
		{
			motor[IntakeL] = -127;
			motor[IntakeR] = -127;
		}
		// Stop the intake motors.
		else
		{
			motor[IntakeL] = 0;
			motor[IntakeR] = 0;
		}

		// Ramp motors?
		// Run both in one direction
		if (vexRT[Btn5D] == 1)
		{
			motor[RampR] = 47;
			motor[RampL] = 47;
		}
		// Run both in the other direction
		else if (vexRT[Btn5U] == 1)
		{
			motor[RampR] = -47;
			motor[RampL] = -47;
		} // Stop motors
		else
		{
			motor[RampR] = 0;
			motor[RampL] = 0;
		}
	}
}
