#if !defined(_MENU_CONTROLS_H)
#define _MENU_CONTROLS_H

#define SCROLL_TOP 1
#define SCROLL_BOTTOM 0
#define SWEEP_LEFT 2
#define SWEEP_RIGHT 3

class MenuControls
{
public:
  MenuControls() {}
  virtual ~MenuControls() {}
  
  void select() = 0;
  void scroll(int dir = SCROLL_BOTTOM) = 0;
  void sweep(int dir = SWEEP_LEFT) = 0;
};

#endif // _MENU_CONTROLS_H
