#if !defined(_ARDUMENU_STARTVIEW_)
#define _ARDUMENU_STARTVIEW_

#include "ArduMenu.h"
#include "MenuComponent.h"

class StartView : public MenuComponent {
private:
  MenuComponent *_mNext = nullptr;

public:
  StartView(const char *name) : MenuComponent(name) {}
  ~StartView() {}
  void print(MenuDisplay *dispaly);
  void scroll(int dir);
  void select();
  void add(MenuComponent *next);
  void sweep(int dir);
};

#endif // _ARDUMENU_STARTVIEW_
