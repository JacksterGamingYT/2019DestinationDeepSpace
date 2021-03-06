/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <subsys/IMechanism.h>
#include <hw/DragonTalon.h> 
#include <hw/DragonServo.h>

class Climber : public IMechanism {
public:
  Climber(std::vector<IDragonMotorController*> motorControllers, std::vector<DragonServo*> servos);

  void SetClimbDriveSpeed(double speed);
  void MoveClimbElevator(double speed);
  void DropBuddyClimb(bool drop);

  IMechanism::MECHANISM_TYPE GetType() const override;

private:
  DragonTalon* m_climbElevator;
  DragonTalon* m_climbWheel;
  DragonServo* m_buddyServo;

  const double SERVO_LOCKED_POSITION = 0.0;
  const double SERVO_DROPPED_POSITION = 1.0;
};
