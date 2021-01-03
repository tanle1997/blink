.PHONY: all

all:
	armcc --c99 -c --cpu Cortex-M3 -D__EVAL -D__MICROLIB -g -O2 --apcs=interwork --split_sections -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I./RTE/_blink -IC:/Users/TanLe/AppData/Local/Arm/Packs/ARM/CMSIS/5.7.0/CMSIS/Core/Include -IC:/Users/TanLe/AppData/Local/Arm/Packs/Keil/STM32F1xx_DFP/2.3.0/Device/Include -D__UVISION_VERSION="533" -D_RTE_ -DSTM32F10X_MD -D_RTE_ -DUSE_HAL_DRIVER -DSTM32F103xB -o blink/*.o --omf_browse blink/*.crf --depend blink/*.d
