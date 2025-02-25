#ifndef __NFC_H__
#define __NFC_H__

/**
 * @brief  初始化NFC模块，对模块进行唤醒
 */
void NFC_Init();

/**
 * @brief  读取卡片UID
 */
unsigned char NFC_ReadUID(unsigned char* uid);

#endif
