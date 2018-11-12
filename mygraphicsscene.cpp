#include "mygraphicsscene.h"
#include <iostream>

MyGraphicsScene::MyGraphicsScene(QObject* parent) : QGraphicsScene(parent)
{

}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  emit mouseMoved(event->scenePos().x(), event->scenePos().y());
}
