#include "armpoint.h"
#include <math.h>

ArmPoint::ArmPoint(double _x, double _y)
  : x(_x)
  , y(_y)
{

}

ArmPoint::ArmPoint(const ArmPoint &other) : x(other.x), y(other.y)
{

}

ArmPoint& ArmPoint::operator=(const ArmPoint &other)
{
  x = other.x;
  y = other.y;
  return *this;
}

double ArmPoint::getPolarDistance()
{
  return sqrt(x * x + y * y);
}

radian ArmPoint::getPolarAngle()
{
  return atan2(y, x);
}
