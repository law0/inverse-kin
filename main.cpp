#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>

#include "mygraphicsscene.h"
#include "arm.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  MyGraphicsScene scene;
  scene.setSceneRect(0, 0, 800, 600);

  Arm arm(scene, 3);

  QGraphicsView view(&scene);
  view.show();

  return a.exec();
}
