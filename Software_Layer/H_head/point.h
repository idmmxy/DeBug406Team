/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/point.h 
  * @author  Debug406 Team
  * @date    17-Fabrulary-2018
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  
    TODO: v Serial communication;
          v Servo control (After commands);
          v Motor control (After commands);
            Gyro reading (When is turning back) 
              - To confirm has turned 180 angles;
          v Go to TRANS_TO_LINE_MODE;
   
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DEBUGROB_POINT_S
#define DEBUGROB_POINT_S

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include "motor.h"
#include "gyro.h"
#include "encoder.h"
#include "servo.h"
#include "systick.h"
#include "serial.h"
#include "main.h"

#include "line.h"

/* Exported types ------------------------------------------------------------*/
typedef enum pointAction__
{
  /* Default */
  POINT_DEFAULT = 0,
  
  /* Servo commands */
  HAND_UP,
  HEAD_MOVE,
  
  /* Motor Turn Commands */
  TURN_RIGHT,
  TURN_LEFT,
  TURN_BACK,
  TURN_ANYANGLE,
  
  /* Commands over */
  OVER_,
  QUIT_
} PointCommand_t;

typedef struct pointArguments__
{
  PointCommand_t _command;
  uint8_t _args[2];
}PointArgu_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void HandsUp(void);
void HeadMove(void);
void TurnRegAngle(void);
void TurnAngle(int16_t plusAngle);
void TurnBack(void);
void SendReCall(void);
int GettingPointCommand(void);
int32_t GetLineSpeed(void);

void _CommandUpdate_Callback(PointCommand_t newCom, uint8_t args[static 2]);

#endif /* DEBUGROB_POINT_S */