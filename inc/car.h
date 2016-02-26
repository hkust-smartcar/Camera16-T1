/*
 * car.h
 *
 *  Created on: 2016�~1��16��
 *      Author: yungc
 */

#pragma once


#include <libsc/led.h>
#include <libbase/k60/mcg.h>
#include <libsc/ab_encoder.h>
#include <libsc/trs_d05.h>
#include <libsc/tsl1401cl.h>
#include <libsc/button.h>
#include <libsc/joystick.h>
#include <libsc/st7735r.h>
#include <libsc/simple_buzzer.h>
#include <string>
#include <libsc/alternate_motor.h>
#include <libsc/lcd_console.h>
#include <libsc/lcd_typewriter.h>
#include <libsc/tower_pro_mg995.h>
#include <array>
#include <sstream>
#include <functional>





class Car{
public: // public means anyone can access it
	//there are even ���Z, that means really anyone can access it, even when the class object does not exist :O
	// if you wanna do that, just search " class friend c++"

	Car();
	// default constructor, it will be automatically called once the class object is created
	// example : Car D7689;
	// once the compiler run this code, Car() will be immediately called.
	//same name as the class name
	~Car();
	//default destructor, it will be automatically called when the class object is gonna out the scope
	// example : int main(){  while(1){Car D7689;}   }
	// in the example, D7689 is inside the scope of the while loop, that means after ' ; 'destructor will be called
	// in other word you will D 7 689 again and again
	// if u still dont understand, google "class c++" :)
	//same name as the class name with a '~'


	/*--------------------------------printing below------------------------------------*/

	void printvalue(int16_t value, int16_t color);
	//print number to up-right corner in LCD

	void printvalue(int x,int y,int w,int h,int16_t value, int16_t color);
	//print number to specific location, (x,y,w,h,value-to-print) respectively

	void printvalue(std::string);
	//print string to up-right corner in LCD

	void printvalue(int x,int y,int w,int h,std::string Result);
	//print string to to specific location, (x,y,w,h,value-to-print) respectively


/*
	void printCCDGraph(uint16_t data[libsc::Tsl1401cl::kSensorW], uint16_t color);
	void clearCCDGraph(uint16_t);
	//mainly for clearing graph of CCD
	//print graph inside tick
	// (important) in comment state as there's no CCD in our program
*/

	void printCamGraph();
	 /* not yet finish */


	void clearLcd (uint16_t);
	//clear the lcd the the given color
	// its very slow

	void printline(int16_t value,uint16_t color);
	// print a horizontal line, could be for threshold

	/*--------------------------------printing above------------------------------------*/





	/*--------------------------------signal component below------------------------------------*/

	void blinkLED(int8_t id, int delay_time, int persist_time);
	//blink LED
	//Internal delay inside

	void beepbuzzer(bool tobeep);
	//beep buzzer
	//its so fuxking annoying

	void switchLED(int8_t id);
	//use inside ticks
	/*--------------------------------signal component above------------------------------------*/





	/*--------------------------------switch below------------------------------------*/

	bool getbutton(int8_t id);
	//return true when the specific button has been pressed

	libsc::Joystick::State getjoystick();
	//return state, use with ticks

	/*--------------------------------switch above------------------------------------*/





	/*--------------------------------get data from component below------------------------------------*/

	int16_t otsu_threshold();



	/*--------------------------------get data from component above------------------------------------*/





	/*--------------------------------implement in inherited class------------------------------------*/
	//virtual simply means you can have different implementation of that function in the inherited class
	// dont understand? NVM, just skip this part


	virtual int16_t turningPID (int16_t){return 0; };
	//PID = kp *error +kd *(error_prev - error) + ki * sum of error
	// one of the method to turn your car

	virtual int16_t motorPID (int16_t){return 0; };
	//PID = kp *error +kd *(error_prev - error) + ki * sum of error

	virtual void motor_control(uint16_t power, bool is_clockwise_rotating){ };	//0~1000
	//apply motor PID to improve the acceleration

	virtual void servo_control(int16_t degree){ }; //-90 to 90
	//apply turning PID to improve the turning delay & to have a smooth turning

	virtual int32_t get_encoder_count(){return 0; };
	//not sure how to use encoder



private: // on9 sin set private :)
	//private means only member of it's only class can access it.



protected: //protected seems professional
	//protected means either member of it's only class or class inherited

	libsc::Led* Led1;
	libsc::Led* Led2;
	libsc::Led* Led3;
	libsc::Led* Led4;
	libsc::AbEncoder* encoder;
	libsc::TrsD05* servo;
	libsc::AlternateMotor* motor;
	libsc::Button* button1;
	libsc::Button* button2;
	libsc::Joystick* joystick;
	libsc::St7735r* LCD;
	libsc::LcdConsole* LCDconsole;
	libsc::LcdTypewriter* LCDwriter;
	libsc::SimpleBuzzer* buzzer;

	//the above * means its a pointer.
	// either  int* a;
	// or 	   int *a;
	// are correct, but int* a is recommended. The reason is....i forgot, just better to do this


};