#include "mygraphicsscene.h"
#include <iostream>
#include <QMouseEvent>

MyGraphicsScene::MyGraphicsScene(QObject* parent) : QGraphicsScene(parent), _mouseActive(false)
{

}

bool MyGraphicsScene::eventFilter(QObject* object, QEvent* event) {
  (void)object;

  if (event->type() == QEvent::MouseMove && _mouseActive) {
    QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
    emit mouseMoved(mouseEvent->pos().x(), mouseEvent->pos().y());
  }
  return false;
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  (void)event;
  _mouseActive = true;
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
  (void)event;
  _mouseActive = false;
}
