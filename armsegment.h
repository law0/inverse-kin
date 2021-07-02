#ifndef ARMSEGMENT_H
#define ARMSEGMENT_H

#include <armpoint.h>

class ArmSegment
{
public:
  explicit ArmSegment(double x1, double y1, double x2, double y2);
  explicit ArmSegment(const ArmPoint& begin = ArmPoint(), const ArmPoint& end = ArmPoint());
  ArmSegment(const ArmSegment&) = default;
  ArmSegment& operator=(const ArmSegment& other);
  ~ArmSegment();

  void setLine(double x1, double y1, double x2, double y2);
  void setLine(const ArmPoint& p1, const ArmPoint& p2);
  void setP1(const ArmPoint& point);
  void setP2(const ArmPoint& point);
  ArmPoint p1() const;
  ArmPoint p2() const;
  double x1() const;
  double y1() const;
  double x2() const;
  double y2() const;
  radian angle() const;
  radian angleTo(const ArmSegment&) const;
  double length() const;
  void translate(double dx, double dy);
  void translate(const ArmPoint& point);
  void rotateAroundP1(radian angle);
  void rotateAroundP2(radian angle);

  static double distance(const ArmPoint& p1, const ArmPoint& p2);

private:
  ArmPoint _p1;
  ArmPoint _p2;
};

#endif // ARMSEGMENT_H
