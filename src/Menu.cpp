#include "Menu.h"

Menu::Menu(const char *name, MenuComponent *parent) : MenuComponent(name) {
  parent->add(this);
  _mItems.setStorage(vectorContainer);
}

void Menu::add(MenuComponent *item) {
  item->setParent(this);
  item->setManager(_mMenuManager);
  _mItems.push_back(item);
  _mNumItems = _mItems.size();

#if defined(_ARDUMENU_DEBUG_)

  Serial.println(F("=== Add === "));
  Serial.print(F("What: "));
  Serial.println(item->getName());
  Serial.print(F("To: "));
  Serial.println(getName());
  Serial.print(F("NumItems: "));
  Serial.println(_mNumItems);

#endif // _ARDUMENU_DEBUG_
}

void Menu::select() {

#if defined(_ARDUMENU_DEBUG_)
  Serial.println(F("=== Select === "));
  Serial.print(F("Index: "));
  Serial.println(_mIndex);
  Serial.print(F("NumItems: "));
  Serial.println(_mNumItems);
  Serial.print(F("Cursor: "));
  Serial.println(_mCursor);

#endif // _ARDUMENU_DEBUG_

  if (_mIndex >= 0 && _mIndex <= _mNumItems - 1)
    _mMenuManager->setVisible(_mItems.at(_mIndex));
  else if (_mIndex == -1 || _mIndex == _mNumItems)
    if (_parent != nullptr) { // ??
      _mMenuManager->setVisible(_parent);
      _mIndex = 0;
    }
}

/** TODO
 * hide cursor
 **/
void Menu::print(MenuDisplay *display) {
  
  #if defined(_ARDUMENU_DEBUG_)
  
  Serial.print(F("==="));Serial.print(getName());Serial.println(F("==="));
  // Serial.print(F("Cursor: ")); Serial.println(_mCursor);
  Serial.print(F("Index: ")); Serial.println(_mIndex);
  Serial.print(F("NumItems: "));Serial.println(_mNumItems);
  
  #endif // _ARDUMENU_DEBUG_

  uint8_t displayHeight = display->getHeight();
  uint8_t printIndex = _mIndex;

  // out mode[return to parent] of start list
  if (_mIndex < 0) {

    display->setCursor(0, 1);
    display->print(" ");
    return;

  }

  // out mode [return to parent] of end list
  if (_mIndex == _mNumItems) { 

    if (_mNumItems > displayHeight) {
      display->setCursor(0, displayHeight);
      display->print(" ");
    } else {
      display->setCursor(0, _mNumItems);
      display->print(" ");
    }

    return;
  }

  display->clear();

  if (_mNumItems > displayHeight) {
    if (displayHeight + printIndex > _mNumItems)
      printIndex = _mNumItems - displayHeight;
  }

  for (int i = 0; i < displayHeight; ++i) {
    if (printIndex + i > _mNumItems - 1)
      break;

    display->setCursor(0, i + 1);
    display->print(" ");
    Serial.println(_mItems.at(printIndex + i)->getName());
    display->print(_mItems.at(printIndex + i)->getName());
  }

  printPointer(display);
}

void Menu::printPointer(MenuDisplay *display) {
  uint8_t printingItems = _mNumItems - _mIndex + 1;
  uint8_t displayHeight = display->getHeight();
  uint8_t pointPosition = 1;

  if (printingItems <= 0 || printingItems <= displayHeight) {
    if (_mNumItems > displayHeight) {
      uint8_t ii = _mNumItems - displayHeight;
      pointPosition = _mIndex + 1 - ii;
    } else
      pointPosition = _mIndex + 1;
  }

  display->setCursor(0, pointPosition);
  display->print("*");
}

void Menu::scroll(int dir) {
  // _mCursor = _mIndex;
  if (dir == SCROLL_BOTTOM && _mIndex < _mNumItems) {
    ++_mIndex;
  } else if (dir == SCROLL_TOP && _mIndex != -1) {
    --_mIndex;
  } else if (_mIndex < 0)
    _mIndex = _mNumItems - 1;
  else if (_mIndex == _mNumItems)
    _mIndex = 0;
}

void Menu::sweep(int dir) {
  if (dir == SWEEP_RIGHT)
    select();
  else if (dir == SWEEP_LEFT) {
    _mIndex = -1;
    select();
  }
}
