#include "stm32f1xx_hal.h"
#include "Lcd.h"
#include "ShiftReg.h"

#define ROW_MAX_LENGTH  (0x28u)
#define COL_MAX_LENGTH  (0x02u)
typedef enum
{
  COMMAND = 0x00u,
  DATA,
}LcdInstructionType;

static void LCD_Send4Bit(unsigned int Data);
static void LCD_LInit(void);

void LCD_Init(void)
{
  LCD_LInit();
  /** @brief 0x02 */
  LCD_SendCommand(RETURN_HOME_CMD);
  LCD_SendCommand(ENTRY_MODE_SET_CMD(ENTRY_MODE_SET_INCREASE, \
                  ENTRY_MODE_SET_NON_DISPLAY_SHIFT));
  /** @brief 0x28 */
  LCD_SendCommand(FUNCTION_SET_CMD(FUNCTION_SET_DL_4BIT, \
                  FUNCTION_SET_N_2LINES, \
                  FUNCTION_SET_F_5X8_DOTS));

  /** @brief 0x0E */
  LCD_SendCommand(DISPLAY_CONTROL_CMD(DISPLAY_CONTROL_ENTIRE_DISPLAY_ON, \
                  DISPLAY_CONTROL_CURSOR_ON, \
                  DISPLAY_CONTROL_BLINK_CURSOR_OFF));
}

static void LCD_LInit()
{
  /* Initialization */
  /* Send 0x03 */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              1, LCD_INITIAL_VALUE));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              0, LCD_INITIAL_VALUE));
  HAL_Delay(1);
  /* Send 0x03 */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              1, LCD_INITIAL_VALUE));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              0, LCD_INITIAL_VALUE));
  HAL_Delay(1);
  /* Send 0x03 */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              1, LCD_INITIAL_VALUE));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              0, LCD_INITIAL_VALUE));
  HAL_Delay(1);
}

void LCD_SendCommand(unsigned char Command)
{
  /* Make a falling edge on Pin E to write 4 bit high */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 1, \
    (Command & 0xF0u) >> 4u));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 0, \
    (Command & 0xF0u) >> 4u));
  /* Make a falling edge on Pin E to write 4 bit low */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 1, \
    Command & 0x0Fu));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 0, \
    Command & 0x0Fu));
}

unsigned char LCD_GotoXY(unsigned char x, unsigned char y)
{
  unsigned char retVal = 1;

  if ((x > ROW_MAX_LENGTH) || (y > COL_MAX_LENGTH))
  {
    retVal = 0;
  }
  else
  {

  }

  return retVal;
}

static void LCD_Send4Bit(unsigned int Data)
{
  ShiftData(Data);
  ShiftLatch();
}


void LCD_PutString(unsigned char * const Character)
{
  unsigned char * TempStr = Character;

  while (*TempStr != '\0')
  {
    LCD_PutChar(*TempStr);
    TempStr++;
  }
}

void LCD_PutChar(unsigned char Character)
{
  /* 4-bit high */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 1, \
                                    ((Character & 0xF0u) >> 4u)));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 0, \
                                    ((Character & 0xF0u) >> 4u)));
  /* 4-bit low */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 1, \
                                    ((Character & 0x0Fu))));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 0, \
                                    ((Character & 0x0Fu))));
}

void LCD_ClearDisplay(void)
{
  LCD_SendCommand(CLEAR_DISPLAY_CMD);
}