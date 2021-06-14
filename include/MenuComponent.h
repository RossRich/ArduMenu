#if !defined(_ARDUMENU_COMPONENT_)
#define _ARDUMENU_COMPONENT_

#include "ArduMenu.h"

class MenuManager;

class MenuComponent {
private:
  const char *_mName;

protected:
  MenuManager *_mMenuManager = nullptr;
  MenuComponent *_parent = nullptr;

public:
  MenuComponent(const char *name) : _mName(name) {}
  ~MenuComponent() {}

  inline const char *getName() const { return _mName; }

  virtual void select() = 0;

  virtual void add(MenuComponent *item) = 0;

  virtual void print(MenuDisplay *display) = 0;

  virtual void scroll(int dir = SCROLL_BOTTOM) = 0;

  virtual void sweep(int dir = SWEEP_LEFT) = 0;

  inline void setParent(MenuComponent *item) { _parent = item; }

  inline void setManager(MenuManager *manager) { _mMenuManager = manager; }
};

#include "MenuManager.h"

#endif // _ARDUMENU_COMPONENT_
