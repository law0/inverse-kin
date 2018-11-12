#include "armsegment.h"
#include "math.h"

ArmSegment::ArmSegment(double x1, double y1, double x2, double y2)
  : _p1(x1, y1)
  , _p2(x2, y2)
{

}

ArmSegment::ArmSegment(const ArmPoint& begin, const ArmPoint& end)
  : _p1(begin)
  , _p2(end)
{

}

ArmSegment& ArmSegment::operator=(const ArmSegment& other)
{
  this->_p1 = other._p1;
  this->_p2 = other._p2;
  return *this;
}

ArmSegment::~ArmSegment()
{

}

void ArmSegment::setLine(double x1, double y1, double x2, double y2)
{
  _p1.x = x1;
  _p1.y = y1;
  _p2.x = x2;
  _p2.y = y2;
}

void ArmSegment::setLine(const ArmPoint& p1, const ArmPoint& p2)
{
  _p1 = p1;
  _p2 = p2;
}

void ArmSegment::setP1(const ArmPoint& point)
{
  _p1 = point;
}

void ArmSegment::setP2(const ArmPoint& point)
{
  _p2 = point;
}

ArmPoint ArmSegment::p1() const
{
  return _p1;
}

ArmPoint ArmSegment::p2() const
{
  return _p2;
}

double ArmSegment::x1() const
{
  return _p1.x;
}

double ArmSegment::y1() const
{
  return _p1.y;
}

double ArmSegment::x2() const
{
  return _p2.x;
}

double ArmSegment::y2() const
{
  return _p2.y;
}

radian ArmSegment::angle() const
{
  return atan2(_p2.y - _p1.y, _p2.x - _p1.x);
}

radian ArmSegment::angleTo(const ArmSegment& otherArmSegment) const
{
  return otherArmSegment.angle() - this->angle();
}

double ArmSegment::length() const
{
  double dx = _p2.x - _p1.x;
  double dy = _p2.y - _p1.y;
  return sqrt(dx * dx + dy * dy);
}

void ArmSegment::translate(double dx, double dy)
{
  _p1.x += dx;
  _p1.y += dy;
  _p2.x += dx;
  _p2.y += dy;
}

void ArmSegment::translate(const ArmPoint &point)
{
  this->translate(point.x, point.y);
}

void ArmSegment::rotateAroundP1(radian angle)
{
  double len = this->length();
  radian curr_angle = this->angle();
  _p2.x = _p1.x + len * cos(curr_angle + angle);
  _p2.y = _p1.y + len * sin(curr_angle + angle);
}

void ArmSegment::rotateAroundP2(radian angle)
{
  double len = this->length();
  radian curr_angle = this->angle();
  _p1.x = _p2.x - len * cos(curr_angle + angle); // cos(pi + x) = - cos(x)
  _p1.y = _p2.y - len * sin(curr_angle + angle); // sin(pi + x) = - sin(x)
}

double ArmSegment::distance(const ArmPoint& p1, const ArmPoint& p2)
{
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}
