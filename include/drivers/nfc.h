#ifndef NFC_H
#define NFC_H

/**
 * @brief 初始化NFC模块，对模块进行唤醒
 */
void nfc_init(void);

/**
 * @brief 读取卡片UID
 */
unsigned char nfc_read_uid(unsigned char* uid);

#endif // NFC_H
