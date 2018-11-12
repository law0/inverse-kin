#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class MyGraphicsScene : public QGraphicsScene
{
  Q_OBJECT
public:
  MyGraphicsScene(QObject* parent=nullptr);

signals:
  void mouseMoved(double x, double y);

protected:
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MYGRAPHICSSCENE_H
