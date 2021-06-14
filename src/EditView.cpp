#include "EditView.h"

void EditView::print(MenuDisplay *dispaly) { Serial.println(getName()); }
void EditView::scroll(int dir) {}
void EditView::select() { _mMenuManager->setVisible(_parent); }
void EditView::sweep(int dir) {}