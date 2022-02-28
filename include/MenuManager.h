#if !defined(_ARDUMENU_MANAGER_)
#define _ARDUMENU_MANAGER_

#include "ArduMenu.h"
#include "MenuComponent.h"

class MenuManager {
private:
  MenuComponent *_mVisibleItem = nullptr;
  MenuDisplay *_mDispaly = nullptr;

public:
  MenuManager() {}
  MenuManager(MenuComponent *startView, MenuDisplay *display) {
    setStarView(startView);
    _mDispaly = display;
  }
  ~MenuManager() {}

  void setStarView(MenuComponent *start) {
    start->setManager(this);
    _mVisibleItem = start;
  }

  inline MenuComponent* getVisible() { return _mVisibleItem; }

  inline void setVisible(MenuComponent *item) { _mVisibleItem = item; }

  inline void select() { _mVisibleItem->select(); }

  inline void print() { _mVisibleItem->print(_mDispaly); }

  inline void scroll(int dir) { _mVisibleItem->scroll(dir); }

  inline void sweep(int dir) { _mVisibleItem->sweep(dir); }

  inline void update() { _mVisibleItem->update(_mDispaly); }
};

#endif // _ARDUMENU_MANAGER_
