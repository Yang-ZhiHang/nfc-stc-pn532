# NFC Lock Project

基于 STC89C52 单片机的 NFC 门锁控制系统，使用 PN532 NFC 模块实现卡片识别和舵机控制开门。

## 项目描述

- **集成开发环境**: Keil5
- **烧录程序**: STC-ISP
- **单片机**: STC89C52-35I
- **外接晶振**: 11.0592MHz
- **波特率**: 115200
- **NFC模块**: PN532 (NFC Module V3) HSU 协议
- **功能**: 读取 NFC 卡片 UID，匹配正确卡片后控制舵机开门，否则蜂鸣器报警。

## 项目结构

```
nfc-lock/
│
├── src/
│   ├── main.c          # 主程序入口
│   ├── drivers/
│   │   ├── buzzer.c    # 蜂鸣器驱动
│   │   ├── led.c       # LED指示灯驱动
│   │   ├── nfc.c       # PN532 NFC模块驱动
│   │   ├── servo.c     # MG90S舵机驱动
│   │   └── uart.c      # STC串口通信驱动
│   └── utils/
│       └── delay.c     # 延时函数工具
├── include/
│   ├── drivers/
│   │   ├── buzzer.h
│   │   ├── led.h
│   │   ├── nfc.h
│   │   ├── servo.h
│   │   └── uart.h
│   └── utils/
│       └── delay.h
├── nfc-lock.uvproj    # Keil 项目文件
└── README.md
```

## 模块说明

- **main.c**: 主循环，初始化各模块，读取 NFC 卡片并控制舵机/蜂鸣器。
- **drivers/**: 硬件驱动模块
- **utils/**: 工具模块，如延时函数。
- **include/**: 头文件目录，对应源文件。

## 编译与烧录

1. 使用 Keil5 打开 `nfc-lock.uvproj`。
2. 配置 include 路径：`include`、`include/drivers`、`include/utils`。
3. 编译生成 HEX 文件。
4. 使用 STC-ISP 烧录到 STC89C52 单片机。
