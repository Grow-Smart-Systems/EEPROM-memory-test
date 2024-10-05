#pragma once

#include <Arduino.h>
#include <U8g2lib.h>

#include "../Utils/BoolArray.h"

// SSD1306 OLED DEBUG PRINT
#define DEBUG_TEXT_STRING_0 10
#define DEBUG_TEXT_STRING_1 20
#define DEBUG_TEXT_STRING_2 30
#define DEBUG_TEXT_STRING_3 40
#define DEBUG_TEXT_STRING_4 50
#define DEBUG_TEXT_STRING_5 60
#define DEBUG_TEXT_FONT u8g_font_6x10
//

class OLED 
{
    public:
        OLED();
        ~OLED() = default;

        /// @brief Инициализация экрана
        /// @return true - успешно, false - ошибка
        bool init();

        void printInitializeScreen();
        
        void printMemoryMap(const BoolArray& map);

    private:
        /// @brief Экземпляр дисплея U8G2 для SSD1306 с разрешением 128x64, без маркировки, с использованием аппаратного I2C.
        /// @note Если динамической памяти будет не хватать, можно заменить U8G2_SSD1306_128X64_NONAME_1_HW_I2C
        U8G2_SSD1306_128X64_NONAME_2_HW_I2C _u8g2;
};