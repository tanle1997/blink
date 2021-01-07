#ifndef _LCD_H_

#define _LCD_H_

#define LCD_INITIAL_VALUE                   (0x03u)
/** @brief Clear Display Command */
#define CLEAR_DISPLAY_CMD                   (0x01u)
/** @brief Return Home Command */
#define RETURN_HOME_CMD                     (0x02u)

/* Entry mode register */
#define ENTRY_MODE_SET_ID_Pos               (1u)
#define ENTRY_MODE_SET_S_Pos                (0u)
#define ENTRY_MODE_SET_INCREASE             (0x01u)
#define ENTRY_MODE_SET_DECREASE             (0x00u)
#define ENTRY_MODE_SET_DISPLAY_SHIFT        (0x01u)
#define ENTRY_MODE_SET_NON_DISPLAY_SHIFT    (0x00u)
/** @brief Entry Mode Set Command */
#define ENTRY_MODE_SET_CMD(ID, S)           (0x04u | \
                                            (ID << ENTRY_MODE_SET_ID_Pos) | \
                                            (S << ENTRY_MODE_SET_S_Pos))

/* Display control register */
#define DISPLAY_CONTROL_D_Pos               (2u)
#define DISPLAY_CONTROL_ENTIRE_DISPLAY_ON   (0x01u)
#define DISPLAY_CONTROL_ENTIRE_DISPLAY_OFF  (0x00u)
#define DISPLAY_CONTROL_C_Pos               (1u)
#define DISPLAY_CONTROL_CURSOR_ON           (0x01u)
#define DISPLAY_CONTROL_CURSOR_OFF          (0x00u)
#define DISPLAY_CONTROL_B_Pos               (0u)
#define DISPLAY_CONTROL_BLINK_CURSOR_ON     (0x01u)
#define DISPLAY_CONTROL_BLINK_CURSOR_OFF    (0x00u)
/** @brief Display Control Command */
#define DISPLAY_CONTROL_CMD(D, C, B)        (0x08u | \
                                            (D << DISPLAY_CONTROL_D_Pos) | \
                                            (C << DISPLAY_CONTROL_C_Pos) | \
                                            (B << DISPLAY_CONTROL_B_Pos))

/* Cursor or display register */
#define CURSOR_OR_DISPLAY_SC_Pos            (3u)
#define CURSOR_OR_DISPLAY_DISPLAY_SHIFT     (0x01u)
#define CURSOR_OR_DISPLAY_CURSOR_MOVE       (0x00u)
#define CURSOR_OR_DISPLAY_RL_Pos            (2u)
#define CURSOR_OR_DISPLAY_SHIFT2RIGHT       (0x01u)
#define CURSOR_OR_DISPLAY_SHIFT2LEFT        (0x00u)
/** @brief Cursor or Display Shift Command */
#define CURSOR_OR_DISPLAY_SHIFT_CMD(SC, RL) (0x10u | \
                                            (SC << CURSOR_OR_DISPLAY_SC_Pos) | \
                                            (RL << CURSOR_OR_DISPLAY_RL_Pos))

/* Function set register */
#define FUNCTION_SET_DL_Pos                 (4u)
#define FUNCTION_SET_DL_8BIT                (0x01u)
#define FUNCTION_SET_DL_4BIT                (0x00u)
#define FUNCTION_SET_N_Pos                  (3u)
#define FUNCTION_SET_N_2LINES               (0x01u)
#define FUNCTION_SET_N_1LINE                (0x00u)
#define FUNCTION_SET_F_Pos                  (2u)
#define FUNCTION_SET_F_5X10_DOTS            (0x01u)
#define FUNCTION_SET_F_5X8_DOTS             (0x00u)
/** @brief Function Set Command */
#define FUNCTION_SET_CMD(DL, N, F)          (0x20u | \
                                            (DL << FUNCTION_SET_DL_Pos) | \
                                            (N << FUNCTION_SET_N_Pos) | \
                                            (F << FUNCTION_SET_F_Pos))

/** Set Character address register */
#define SET_CGRAM_ADDR_Mask                 (0x3Fu)
/** @brief Set character address */
#define SET_CGRAM_ADDR_CMD(ACG)             (0x40u | \
                                            (ACG & SET_CGRAM_ADDR_Mask))

/** Set Address register */
#define SET_DDRAM_ADDR_Mask                 (0x7Fu)
/** @brief Set data address */
#define SET_DDRAM_ADDR_CMD(ADD)             (0x80u | \
                                            (ADD & SET_DDRAM_ADDR_Mask))


#define PACK_DATA_4BIT_INTERFACE_RS_Pos     (0u)
#define PACK_DATA_4BIT_INTERFACE_RS_Mask    (0x01u)
#define PACK_DATA_4BIT_INTERFACE_E_Pos      (1u)
#define PACK_DATA_4BIT_INTERFACE_E_Mask     (0x01u)
#define PACK_DATA_4BIT_INTERFACE_DATA_Pos   (2u)
#define PACK_DATA_4BIT_INTERFACE_DATA_Mask  (0x0Fu)
/** Use 74HC595 to control the LCD with 4-bit mode
 * This macro to encode more parameters into 8-bit data
*/
#define PACK_DATA_4BIT_INTERFACE(RS, E, DATA)   (0x00u | \
                                                ((((DATA & PACK_DATA_4BIT_INTERFACE_DATA_Mask) << PACK_DATA_4BIT_INTERFACE_DATA_Pos) | \
                                                ((E & PACK_DATA_4BIT_INTERFACE_E_Mask) << PACK_DATA_4BIT_INTERFACE_E_Pos) | \
                                                ((RS & PACK_DATA_4BIT_INTERFACE_RS_Mask) << PACK_DATA_4BIT_INTERFACE_RS_Pos))))

#define HIGH_NIBBLE_Mask    (0xF0u)
#define HIGH_NIBBLE_Pos     (4u)
#define LOW_NIBBLE_Mask     (0x0Fu)
#define LOW_NIBBLE_Pos      (0u)
/*********************** API ***************************/
extern void LCD_SendCommand(uint8 Command);
extern uint8 LCD_GotoXY(uint8 col, uint8 row);
extern void LCD_ClearDisplay(void);
extern void LCD_Init(void);
extern void LCD_PutChar(uint8 Character);
extern void LCD_PutString(uint8 * const Character);

#endif // End of _LCD_H_
