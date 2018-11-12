#ifndef ARMPOINT_H
#define ARMPOINT_H

#include "armdef.h"

struct ArmPoint
{
  ArmPoint(double _x = 0, double _y = 0);
  ArmPoint(const ArmPoint& other);
  ArmPoint& operator=(const ArmPoint& other);
  double x;
  double y;

  double getPolarDistance();
  radian getPolarAngle();
};

#endif // ARMPOINT_H
