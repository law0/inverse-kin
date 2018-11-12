#ifndef ARM_H
#define ARM_H

#include <QObject>
#include "mygraphicsscene.h"
#include <QGraphicsTextItem>
#include <math.h>
#include "armdef.h"
#include "armsegment.h"

class Arm : public QObject
{
  Q_OBJECT

public:
  Arm(MyGraphicsScene& s, uint nOfLines);
  void rotateEndEffector(uint index, radian angle);
  uint ccd(double x, double y);

public slots:
  void onMouseEvent(double x, double y);

private:
  MyGraphicsScene& scene;
  const uint nlines;
  QList<QGraphicsLineItem*> lines;
  QList<ArmSegment> segments;
  QGraphicsTextItem* textItem;
};

#endif // ARM_H
