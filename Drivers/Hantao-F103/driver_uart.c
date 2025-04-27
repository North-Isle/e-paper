// SPDX-License-Identifier: GPL-3.0-only
/*
 * Copyright (c) 2008-2023 100askTeam : Dongshan WEI <weidongshan@qq.com> 
 * Discourse:  https://forums.100ask.net
 */

 
/*  Copyright (C) 2008-2023 深圳百问网科技有限公司
 *  All rights reserved
 *
 *
 * 免责声明: 百问网编写的文档，仅供学员学习使用，可以转发或引用(请保留作者信息)，禁止用于商业用途！
 * 免责声明: 百问网编写的程序，可以用于商业用途，但百问网不承担任何后果！
 * 
 * 
 * 本程序遵循GPL V3协议，使用请遵循协议许可
 * 本程序所用的开发板：	DShanMCU-F103
 * 百问网嵌入式学习平台：https://www.100ask.net
 * 百问网技术交流社区：	https://forums.100ask.net
 * 百问网官方B站：				https://space.bilibili.com/275908810
 * 百问网官方淘宝：			https://100ask.taobao.com
 * 联系我们(E-mail)：	  weidongshan@qq.com
 *
 * 版权所有，盗版必究。
 *  
 * 修改历史     版本号           作者        修改内容
 *-----------------------------------------------------
 * 2023.08.04      v01         百问科技      创建文件
 *-----------------------------------------------------
 */


#include "driver_uart.h"
#include "driver_lcd.h"
#include "driver_timer.h"
#include "usart.h"

#include <stdio.h>

#define DEBUG_UART_TIMEOUT 500

extern UART_HandleTypeDef huart1;
static UART_HandleTypeDef * g_HDebugUART = &huart1;

/**********************************************************************
 * 函数名称： UART_Init
 * 功能描述： UART初始化函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/08/05	     V1.0	  韦东山	      创建
 ***********************************************************************/
void UART_Init(void)
{
}


int fputc(int c, FILE *f) 
{
    (void)f;
    HAL_UART_Transmit(g_HDebugUART, (const uint8_t *)&c, 1, DEBUG_UART_TIMEOUT);
    return c;
}

int fgetc(FILE *f)
{
    uint8_t ch = 0;
    (void)f;

    /* Clear the Overrun flag just before receiving the first character */
    __HAL_UART_CLEAR_OREFLAG(g_HDebugUART);

    /* Wait for reception of a character on the USART RX line and echo this
    * character on console */
    HAL_UART_Receive(g_HDebugUART, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    HAL_UART_Transmit(g_HDebugUART, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;    
}


/**********************************************************************
 * 函数名称： UART_Test
 * 功能描述： UART测试程序
 * 输入参数： 无
 * 输出参数： 无
 *            无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人        修改内容
 * -----------------------------------------------
 * 2023/08/05        V1.0     韦东山       创建
 ***********************************************************************/
void UART_Test(void)
{    
    char c;
    
    UART_Init();

//    LCD_PrintString(0, 0, "UART");
		int a=0;
	
		printf("AT\r\n");  
    vTaskDelay(2000);
		printf("AT+RST\r\n");    
    vTaskDelay(5000);
    printf("AT+CWMODE=1\r\n");      
    vTaskDelay(2000);
    printf("AT+CWJAP=\"HANTAO\",\"1234567a\"\r\n");    
    vTaskDelay(5000);  // 连接 WiFi 可能需要更长时间
    printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"67c5704724d77232552235e2_HANTAO_01\",\"c9355cf24bdaf5dd73d6ca37a50b5d9bda010223f80f3752edac66c41b5f1c91\",0,0,\"\"\r\n");
    vTaskDelay(2000);  
    printf("AT+MQTTCLIENTID=0,\"67c5704724d77232552235e2_HANTAO_01_0_0_2025032608\"\r\n");
    vTaskDelay(2000);   
    printf("AT+MQTTCONN=0,\"2dddcab94e.st1.iotda-device.cn-north-4.myhuaweicloud.com\",1883,1\r\n");
    vTaskDelay(2000);  
    printf("AT+MQTTSUB=0,\"$oc/devices/67c5704724d77232552235e2_HANTAO_01/sys/properties/report\",1\r\n");
    vTaskDelay(2000);
    printf("AT+MQTTPUB=0,\"$oc/devices/67c5704724d77232552235e2_HANTAO_01/sys/properties/report\",\"{\\\"services\\\":[{\\\"service_id\\\":\\\"service1\\\"\\\,\\\"properties\\\":{\\\"ceshai\\\":\\\"%d\\\"}}]}\",0,0\r\n",3);
		uint16_t i=1;
		vTaskDelay(3000);

	
    while (1)
    {
		printf("AT+MQTTPUB=0,\"$oc/devices/67c5704724d77232552235e2_HANTAO_01/sys/properties/report\",\"{\\\"services\\\":[{\\\"service_id\\\":\\\"service1\\\"\\\,\\\"properties\\\":{\\\"ceshai\\\":\\\"%d\\\"}}]}\",0,0\r\n",i);				
//        c = fgetc(NULL);
//			printf("\n\r read:%c\n\r", c);
//				LCD_PrintHex(0, 0,c,1);
//			if (c=='1')
//        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
//			else if(c=='2')
//        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
			//printf("a=%d\n\r",a);
			vTaskDelay(5000);
			i++;
    }
}
