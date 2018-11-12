#include "arm.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

//#define ARM_DBUG

Arm::Arm(MyGraphicsScene& s, uint nOfLines) : scene(s), nlines(nOfLines), lines()
{
  for(uint i = 0; i < nlines; ++i)
  {
    lines.append(scene.addLine(QLineF(100 * i, 100 * i, 100 *(i+1), 100 * (i+1))));
    segments.append(ArmSegment(ArmPoint(100 * i, 100 * i), ArmPoint(100 * (i + 1), 100 * (i + 1))));
    textItem = scene.addText("(0, 0)");
  }
  connect(&scene, &MyGraphicsScene::mouseMoved, this, &Arm::onMouseEvent);
}

void Arm::onMouseEvent(double x, double y)
{
  uint iters = ccd(x, y);
  textItem->setPlainText(QString("(%1, %2) n=%3").arg(x).arg(y).arg(iters));
  textItem->setPos(x, y);
}

/**
 * @brief Arm::rotateEndEffector rotate a segment of the arm with all its "children"
 * @param index
 * @param angle
 */
void Arm::rotateEndEffector(uint index, radian angle)
{
  if(index < nlines)
  {
    ArmSegment& seg = segments[index];
#ifdef ARM_DBUG
    printf("index %d angle before %f ", index, radToDeg(seg.angle()));
#endif
    seg.rotateAroundP1(degToRad(angle));
#ifdef ARM_DBUG
    printf("angle after %f\n", radToDeg(seg.angle()));
#endif

    for(; index < nlines - 1; ++index) //make the following segments (the children) rotate accordingly
    {
      ArmSegment& curr = segments[index];
      ArmSegment& next = segments[index + 1];
      next.rotateAroundP1(degToRad(angle)); //rotate first by adding same angle
      double x1 = next.x1();
      double y1 = next.y1();
      double x2 = curr.x2(); //has moved
      double y2 = curr.y2(); //has moved
      next.translate(x2 - x1, y2 - y1); //translate to reattach to parent
    }
  }
}

/**
 * @brief Arm::ccd implements cyclic coordinates descent algorithm
 * @param x
 * @param y
 */
uint Arm::ccd(double x, double y)
{
  ArmPoint target(x, y);
  uint i = 0;
  while(ArmSegment::distance(target, segments.last().p2()) > 10 && i < 1000)
  {
    ++i;
    for(int index = nlines - 1; index > -1; --index)
    {
      ArmPoint p1(segments.at(index).p1());
      ArmSegment segmentToTarget(p1, target);
      ArmSegment segmentToEndEffector(p1, segments.last().p2());
      radian angle = segmentToEndEffector.angleTo(segmentToTarget);

#ifdef ARM_DBUG
      printf("BEFORE ROTATION angle (end effector -> end joint %d -> target) %f\n", index, radToDeg(angle));
#endif

      if(index == 0)
      {
        rotateEndEffector(index, angle);
      }
      else
      {
        rotateEndEffector(index, angle * (nlines - index) / (nlines - index + 1)); //less angles for the upper arms
      }

#ifdef ARM_DBUG
      p1 = segments.at(index).p1();
      ArmPoint p2 = segments.last().p2();
      segmentToTarget.setLine(p1, target);
      segmentToEndEffector.setLine(p1, p2);
      angle = segmentToEndEffector.angleTo(segmentToTarget);

      printf("AFTER ROTATION angle %f\n", radToDeg(angle));
      printf("x %f, y %f, sx %f, sy %f\n", x, y, p2.x, p2.y);
#endif
    }
  }

  for(uint index = 0; index < nlines; ++index)
  {
    ArmSegment seg = segments[index];
    double x1 = seg.x1();
    double y1 = seg.y1();
    double x2 = seg.x2();
    double y2 = seg.y2();
    lines[index]->setLine(x1, y1, x2, y2);
  }

  return i;
}
