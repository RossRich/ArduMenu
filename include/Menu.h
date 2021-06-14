#if !defined(_ARDUMENU_MENU_)
#define _ARDUMENU_MENU_

#include "ArduMenu.h"
#include "MenuComponent.h"

class Menu : public MenuComponent {
private:
  MenuComponent *vectorContainer[MAX_ITEMS];
  Vector<MenuComponent *> _mItems;
  int _mIndex = 0;
  int _mNumItems = 0;
  int _mCursor = 0;

public:
  explicit Menu(const char *name) : MenuComponent(name) {}
  Menu(const char *name, MenuComponent *parent);
  ~Menu() {}

  void add(MenuComponent *item);

  void select();

  void print(MenuDisplay *display);

  void scroll(int dir);

  void sweep(int dir);

  void printPointer(MenuDisplay *display);
};

#endif // _ARDUMENU_MENU_
