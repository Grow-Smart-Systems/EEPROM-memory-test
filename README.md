# EEPROM-memory-test

## Описание
Скетч для тестирования памяти на Arduino UNO R3 с подключенным OLED дисплеем.

### Тест на чтение и запись EEPROM

Тест на чтение запись блоков (данные записанные в память не теряются).
```cpp
BoolArray MaintenanceEEPROM::ReadWriteMemoryTest(unsigned int from = 0, unsigned int to = 0);
```
В процессе выполнения функции происходит последовательно во все ячейки памяти 0x00, затем 0xFF. После завершения функция передает массив bool спрятанный в BoolArray для компактности. На экран выводится пустые пиксели в местах, где тест ячейки пройден неудачно.
```cpp
void OLED::printMemoryMap(const BoolArray& map)
```
### Тест на чтение из памяти

Тест служет только для демонтрации наличия данных в памяти на экране.

```cpp
BoolArray MaintenanceEEPROM::ReadDataFormMemory()
```

## Дисплей OLED SSD1306 128x64

### Физическое подключение

| SSD1306 | Arduino UNO |
|-------------|-------------|
| GND | GND |
| VCC | 5V |
| SCL | A5 |
| SDA | A4 |

### Программное подключение

Для подключения было использована библиотека u8glib. 
Cсылка: [Github]([https://github.com/olikraus/u8glib)
```cpp
#include <u8glib.h>
```
Данная библиотека считается устаревшей и более не обновляется автором, но для небольшого количества памяти устройства 2 версия данной библиотеки не сильно подходит.
