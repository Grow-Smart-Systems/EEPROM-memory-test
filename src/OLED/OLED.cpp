#include "OLED.h"


OLED::OLED()
  : _u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE)
{}

bool OLED::init()
{
  if (!_u8g2.begin())
    return false;

  _u8g2.setPowerSave(0);
  _u8g2.setFont(u8g_font_6x10);
  _u8g2.setFontRefHeightExtendedText();
  _u8g2.setFontPosTop();
  return true;
}

void OLED::printInitializeScreen()
{
  _u8g2.firstPage();
  do
  {
    //NOTE: Без setFont не работает!
    _u8g2.setColorIndex(1);
    _u8g2.setFont(u8g_font_6x13);
    _u8g2.drawStr(40, DEBUG_TEXT_STRING_3, "LOADING...");
  } while (_u8g2.nextPage());
}

void OLED::printMemoryMap(const BoolArray& map)
{
  _u8g2.firstPage();
  do
  {
    //NOTE: Без setFont не работает!
    _u8g2.setColorIndex(1);

    int cols = _u8g2.getWidth();
    int rows = map.size() / cols;
    int errorCount { 0 };
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        int index = i * cols + j;
        if (map.get(index))
          _u8g2.drawPixel(j, i);
        else
          errorCount++;
        
      }
    }
    _u8g2.setFont(u8g_font_4x6);
    String str = "cells: " + String(map.size()) + " (cols: " + String(cols) + " rows: " + String(rows) + ")";
    _u8g2.drawStr(0, rows+10, str.c_str());
    str = "error cells: " + String(errorCount);
    _u8g2.drawStr(0, rows+20, str.c_str());
  } while (_u8g2.nextPage());

}

