#include "drivers/nfc.h"
#include "drivers/uart.h"
#include "utils/delay.h"

// 唤醒指令
const unsigned char NFC_WAKE_UP[] = {
    0x55, 0x55,                                                                          // 前导码
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 同步码
    0xFF, 0x03,                                                                          // 包开始标记和长度
    0xFD,                                                                                // 校验和
    0xD4, 0x14,                                                                          // 命令码（SAM配置命令）
    0x01,                                                                                // 参数
    0x17, 0x00                                                                           // 后缀
};

// 读取UID指令
const unsigned char NFC_READ_UID[] = {
    0x00, 0x00, 0xFF,  // 帧头
    0x04,              // 长度
    0xFC,              // 长度校验和
    0xD4, 0x4A,        // 命令码
    0x01, 0x00,        // 参数
    0xE1,              // 数据校验和
    0x00               // 帧尾
};

void nfc_init(void) {
    unsigned char i;

    // 发送唤醒指令
    for (i = 0; i < sizeof(NFC_WAKE_UP); i++) {
        uart_send_byte(NFC_WAKE_UP[i]);
    }

    // 等待响应
    delay_125ms();
}

unsigned char nfc_read_uid(unsigned char* uid) {
    unsigned char i;
    unsigned char length;
    unsigned char header[3];

    uart_clear_buffer();  // 清除缓冲区

    // 发送寻卡指令
    for (i = 0; i < sizeof(NFC_READ_UID); i++) {
        uart_send_byte(NFC_READ_UID[i]);
    }

    // 跳过空数据包
    for (i = 0; i < 6; i++) {
        uart_receive_byte();
    }

    // 读取响应包头
    header[0] = uart_receive_byte();
    header[1] = uart_receive_byte();
    header[2] = uart_receive_byte();

    // 检查包头
    if (header[0] != 0x00 || header[1] != 0x00 || header[2] != 0xFF) {
        return 0;
    } else {
        length = uart_receive_byte();               // 读取长度
        if (length >= 7) {                          // 确保响应中包含UID
            for (i = 0; i < length - 4 + 1; i++) {  // 跳过其他数据 + LCS长度校验位
                uart_receive_byte();
            }
            // 读取4字节UID
            for (i = 0; i < 4; i++) {
                uid[i] = uart_receive_byte();
            }

            // 跳过响应包尾
            uart_receive_byte();
            uart_receive_byte();

            return 1;
        }
    }

    return 0;
}