#include <QObjectManager.hpp>
#include <cstdio>
#include <stdlib.h>

QObjectManager::QObjectManager() { init(); }
QObjectManager::~QObjectManager() { free(list); }
void QObjectManager::init() {
  head = -1;
  last = -1;
  size = 0;
  prevSize = 0;
  curSize = MIN_LIST_SIZE;
  list = (QNode *)malloc(sizeof(QNode) * curSize);
  initList();
}
void QObjectManager::initList() {
  int i;
  for (i = prevSize; i < curSize; i++) {
    list[i].next = -2;
    list[i].prev = -2;
  }
}
void QObjectManager::extendListSize() {
  prevSize = curSize;
  curSize += EXTEND_SIZE;
  list = (QNode *)realloc(list, sizeof(QNode) * curSize);
  initList();
}
int QObjectManager::findNextFreeSlot() {
  if (curSize == size) {
    return -1;
  }
  int i;
  for (i = 0; i < curSize; i++) {
    if (list[i].next == -2) {
      return i;
    }
  }
  return -2;
}
void QObjectManager::addItem(QObject _object) {
  int _index = findNextFreeSlot();
  if (_index == -1) {
    extendListSize();
  }
  if (_index == -2) {
    perror("Error could not find free slot to add item");
    return;
  }

  list[_index].data = _object;
  list[_index].next = -1;

  // if list is empty
  if (head == -1) {
    head = _index;
    last = _index;
    list[_index].prev = -1;
    return;
  }
  // if not empty
  list[last].next = _index;
  list[_index].prev = last;
  last = _index;
}
QObject QObjectManager::removeItem(int _index) {}