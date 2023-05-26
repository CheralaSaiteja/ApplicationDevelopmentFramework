#ifndef QOBJECTMANAGER_HPP
#define QOBJECTMANAGER_HPP

#include <QObject.hpp>

#define MIN_LIST_SIZE 5
#define EXTEND_SIZE 5

struct QNode {
  QObject data;
  int prev, next;
};

class QObjectManager {
public:
  int head, last, curSize, prevSize, size;
  QNode *list;
  QObjectManager();
  ~QObjectManager();
  void init();
  void addItem(QObject _object);
  QObject removeItem(int _index);
  int findNextFreeSlot();

private:
  void initList();
  void extendListSize();
};

#endif