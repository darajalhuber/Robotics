#pragma config(Sensor, port7,  TopButton,      sensorVexIQ_Touch)
#pragma config(Sensor, port8,  BottomButton,   sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          LeftDriveMotor, tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor2,          MantisLeft,    tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor4,          RightArmMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor10,         LeftArmMotor,  tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor11,         MantisRight,   tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor12,         RightDriveMotor, tmotorVexIQ, PIDControl, reversed, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveArm(float timeToMove, int speed){
	setMotor(RightArmMotor, speed);
	setMotor(LeftArmMotor, speed);
	wait(timeToMove, seconds);
	stopAllMotors();
}

void raiseArmTop(){
	repeatUntil (getBumperValue(TopButton) == 1)
	{
		setMotor(RightArmMotor,100);
		setMotor(LeftArmMotor,100);
	}
}


void runProgram(){
	backward(0.7,seconds,100);
	//hanging
//	moveMotor(MantisLeft,-100,degrees,50);
//	moveMotor(MantisRight,-100,degrees,50);
	raiseArmTop();
	forward(1.5,seconds,100);
	moveArm(3.5,-100);

		repeat(forever){
		stopAllMotors();
	}
}

task main()
{
	waitUntil(getBumperValue(TopButton) == 1);
  runProgram();
}
