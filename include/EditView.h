#if !defined(_ARDUMENU_EDITVIEW_)
#define _ARDUMENU_EDITVIEW_

#include "ArduMenu.h"
#include "MenuComponent.h"

class EditView : public MenuComponent {
private:
  void add(MenuComponent *next) {}
public:
  EditView(const char *name) : MenuComponent(name) {}
  EditView(const char *name, MenuComponent *parent) : MenuComponent(name) {
    parent->add(this);
  }
  ~EditView() {}
  void print(MenuDisplay *dispaly);
  void scroll(int dir);
  void select();
  void sweep(int dir);
};

#endif // _ARDUMENU_EDITVIEW_
