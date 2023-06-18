
/* Includes ------------------------------------------------------------------*/
#include"Quad_spider.h"
/*----------------------------------------------------------------------------*/
int servo_pins[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };//leg1(femur,tibia,coxa),leg2(femur, tibia, coxa),leg3(femur,tibia, coxa),leg4(femur, tibia, coxa)
/* Size of the leg robot in mm  ---------------------------------------------------------*/
const float Tibia_length = /*80;*/55;
const float Femur_length = /*55;*/77.5;
const float Coxa_length = /*27;*/27.5;


Quad_spider *robot = new Quad_spider(servo_pins,Coxa_length,Femur_length,Tibia_length);
/*
  - setup function
   ---------------------------------------------------------------------------*/
void Update_servos_pos(){
    robot->servo_service();
   }
void setup()
{
  //comment after setting all the servos to the same position(90 )
  //robot->Set_ALL_servo_to_90_deg();
  
  //start serial for debug
  Serial.begin(9600);
  Serial.println("Robot starts initialization");
  robot->Init_site();
  delay(2000);
  Serial.println("Robot initialization complete");
  //start servo service
  FlexiTimer2::set(20, Update_servos_pos);
  FlexiTimer2::start();
  Serial.println("Servo service started");
  //initialize servos
  robot->servo_attach();
  Serial.println("Servos initialized");
  Serial.println("Robot initialization Complete");

  Serial.println("Stand");
 robot->stand();
  delay(2000);
}



/*
  - loop function
  ---------------------------------------------------------------------------*/
void loop()
{
  

  //call Functions here from instance class of Quad_spider
  
  /*Serial.println("Sit");
  robot->sit();
  delay(5000);
  Serial.println("Stand");
  robot->stand();
  delay(5000);*/

  /*Serial.println("Step forward");
  robot->step_forward(4);*/
  //delay(5000);
}



