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
  bool eventFilter(QObject* object, QEvent* event);
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
  bool _mouseActive;
};

#endif // MYGRAPHICSSCENE_H
