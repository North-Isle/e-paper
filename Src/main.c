/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "EPD_2in9.h"
#include "driver_dht11.h"
#include "fonts.h"
#include "EPD_use.h"
#include "Picture.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#include "stdio.h"
#include <string.h>
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


#define RX_BUFFER_SIZE 1024  // 定义接收缓冲区大小

uint8_t rxBuffer[RX_BUFFER_SIZE];  // 接收缓冲区
uint16_t rxIndex = 0;  // 接收缓冲区的索引
char text_result[100];
char update_result[100];
char tem_result[100];
char real_time[100];
int count=0;
int year,month,day,hum,temp;
UWORD Imagesize = ((EPD_2IN9_WIDTH % 8 == 0)? 
                    (EPD_2IN9_WIDTH / 8 ) : 
                    (EPD_2IN9_WIDTH / 8 + 1)) * EPD_2IN9_HEIGHT;
extern  UBYTE *BlackImage ;



void extractText(const char *json) {
    const char *text_key = "\"text\":\"";
    const char *start = strstr(json, text_key);
    if (start) {
        start += strlen(text_key);
        const char *end = strchr(start, '"');
        if (end) {
            size_t len = end - start;
            if (len < sizeof(text_result)) {
                strncpy(text_result, start, len);
                text_result[len] = '\0';
                printf("%s\n", text_result);
            } else {
                printf("提取的 text 字段过长，超出缓冲区大小\n");
            }
        }
    } else {
        text_result[0] = '\0';
        printf("未找到 text 字段\n");
    }
}
void clear_rxBuffer(void) {
    // 清空缓冲区数据
    memset(rxBuffer, 0, RX_BUFFER_SIZE);
    // 重置接收缓冲区索引
    rxIndex = 0;
    printf("接收缓冲区已清空。\n");
}

void extract_update(const char *json) {
    const char *text_key = "\"last_update\":\"";
    const char *start = strstr(json, text_key);
    if (start) {
        start += strlen(text_key);
        const char *end = strchr(start, '"');
        if (end) {
            size_t len = end - start;
            if (len < sizeof(update_result)) {
                strncpy(update_result, start, len);
                update_result[len] = '\0';
                printf("%s\n", update_result);
            } else {
                printf("提取的 last_update 字段过长，超出缓冲区大小\n");
            }
        }
    } else {
        update_result[0] = '\0';
        printf("未找到 update 字段\n");
    }
}
void extract_real_time(const char *json) {
    const char *text_key = "\"request_id\":\"";
    const char *start = strstr(json, text_key);
    if (start) {
        start += strlen(text_key);
        const char *end = strchr(start, '"');
        if (end) {
            size_t len = end - start;
            if (len < sizeof(real_time)) {
                strncpy(real_time, start, len);
                real_time[len] = '\0';
                printf("%s\n", real_time);
            } else {
                printf("提取的 last_update 字段过长，超出缓冲区大小\n");
            }
        }
    } else {
        update_result[0] = '\0';
        printf("未找到 request_id 字段\n");
    }
}


void extract_date_from_http(const char *json) {
	const char *text_key = "Date: ";
    const char *start = strstr(json, text_key);
    if (start) {
        start += strlen(text_key);
			const char *end = strchr(start, 'G');
        if (end) {
            size_t len = end - start;
            if (len < sizeof(real_time)) {
                strncpy(real_time, start, len);
                real_time[len] = '\0';
                printf("%s\n", real_time);
            } else {
                printf("提取的 last_update 字段过长，超出缓冲区大小\n");
            }
        }
    } else {
        update_result[0] = '\0';
        printf("未找到 Date 字段\n");
    }
}


void extract_tempare(const char *json) {
    const char *text_key = "\"temperature\":\"";
    const char *start = strstr(json, text_key);
    if (start) {
        start += strlen(text_key);
        const char *end = strchr(start, '"');
        if (end) {
            size_t len = end - start;
            if (len < sizeof(tem_result)) {
                strncpy(tem_result, start, len);
                tem_result[len] = '\0';
                printf("%s\n", tem_result);
            } else {
                printf("提取的 last_update 字段过长，超出缓冲区大小\n");
            }
        }
    } else {
        update_result[0] = '\0';
        printf("未找到 update 字段\n");
    }
}

void processReceivedData(uint8_t* buffer, uint16_t size)
{   
    printf("%s\n", buffer);  // 作为字符串输出
}
// ��һ�������С�ĵ�ɫλͼ��ָ��λ�ã�x, y��
void Paint_DrawBitMapXY(const unsigned char *image, UWORD x_start, UWORD y_start, UWORD width, UWORD height) {
    UWORD x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            UWORD byte_index = y * ((width + 7) / 8) + x / 8;
            UBYTE byte = image[byte_index];
            UBYTE bit = 0x80 >> (x % 8);
            if (byte & bit)
                Paint_SetPixel(x_start + x, y_start + y, BLACK);
            else
                Paint_SetPixel(x_start + x, y_start + y, WHITE);
        }
    }
}

void clear( UWORD x_start, UWORD y_start, UWORD width, UWORD height,uint16_t Color) {
    UWORD x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
                Paint_SetPixel(x_start + x, y_start + y, Color);
        }
    }
}



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
int EPD_test(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int MY_EPD_test(void)
{

		DEV_Module_Init();
		EPD_2IN9_Init(EPD_2IN9_FULL);
		EPD_2IN9_Clear();

		Paint_NewImage(BlackImage, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT, 270, WHITE);
		Paint_SelectImage(BlackImage);
		Paint_Clear(WHITE);

		Paint_DrawLine(0, 21, 296, 21, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);	
		Paint_DrawLine(245, 21, 245, 128, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);		
		Paint_DrawLine(72, 21, 72, 128, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);	
		HAL_Delay(2000);    EPD_2IN9_Display(BlackImage);		

		Paint_DrawBitMapXY(gImage_wifi_disconnect, 276, 0, 20, 20); // ����λ��
		HAL_Delay(2000);    EPD_2IN9_Display(BlackImage);
		return 0;
}


int E_test(void)
{
Paint_DrawBitMapXY(gImage_snow, 246, 21, 50, 50); // ����λ��
HAL_Delay(2000);    EPD_2IN9_Display(BlackImage);
return 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	count++;
	
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

 //
	BlackImage = (UBYTE *)malloc(Imagesize);
	MY_EPD_test();
	DHT11_Init();
	HAL_TIM_Base_Start_IT(&htim4);



HAL_Delay(2000);    EPD_2IN9_Display(BlackImage);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  while (1)
//  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//  	HAL_Delay(1000);

//	}
		HAL_UART_Receive_IT(&huart1, &rxBuffer[0], 1);
		HAL_UART_AbortReceive_IT(&huart1);
		printf("AT\r\n");		HAL_Delay(1000);
		printf("AT+RST\r\n");		HAL_Delay(1000);
		printf("AT+CWJAP=\"HANTAO\",\"1234567a\"\r\n");  HAL_Delay(3000);
		printf("AT+CWMODE=1\r\n");HAL_Delay(2000);
		printf("AT+CIPSTART=\"TCP\",\"api.seniverse.com\",80\r\n");HAL_Delay(2000);
		printf("AT+CIPMODE=1\r\n");HAL_Delay(1000);
		printf("AT+CIPSEND\r\n");	HAL_Delay(1000);


			HAL_UART_AbortReceive_IT(&huart1);
			HAL_Delay(1000);
			printf("GET http://api.seniverse.com/v3/weather/now.json?key=SHxTJ0yyZMhCuawJ9&location=haerbin&language=zh-Hans&unit=c\r\n\r\n");	
			uint8_t end = 0x1A;
			HAL_UART_Transmit(&huart1, &end, 1, 100);
			 HAL_UART_Receive_IT(&huart1, &rxBuffer[0], 1);
        if (rxIndex > 0)  
        {
            processReceivedData(rxBuffer, rxIndex);
        }
			HAL_Delay(1000);
		extractText((const char *)rxBuffer);  
		extract_update((const char *)rxBuffer);  
		extract_tempare((const char *)rxBuffer); 	

		if (strcmp(text_result, "阴") == 0) {
        E_test();
    }	

		printf("\r\n+++");	HAL_Delay(5000);	
		printf("AT+CIPCLOSE\r\n");		HAL_Delay(1000);			
			
		HAL_UART_Receive_IT(&huart1, &rxBuffer[0], 1);
		HAL_UART_AbortReceive_IT(&huart1);		
		printf("+++");		HAL_Delay(1000);
		printf("\r\n");		HAL_Delay(1000);
		printf("AT+CIPCLOSE\r\n");		HAL_Delay(1000);		
		printf("AT+RST\r\n");		HAL_Delay(1000);	
		printf("AT+CWJAP=\"HANTAO\",\"1234567a\"\r\n");  HAL_Delay(3000);
		printf("AT+CWMODE=1\r\n");HAL_Delay(2000);		
		printf("AT+CIPSTART=\"TCP\",\"f.m.suning.com\",80\r\n");HAL_Delay(6000);
		printf("AT+CWMODE=1\r\n");HAL_Delay(2000);			
		printf("AT+CIPMODE=1\r\n");HAL_Delay(1000);
		printf("AT+CIPSEND\r\n");	HAL_Delay(1000);		
		clear_rxBuffer();	rxIndex = 0;

			HAL_UART_AbortReceive_IT(&huart1);
		printf("GET /api/ct.do HTTP/1.1\r\nHost: f.m.suning.com\r\nUser-Agent: ESP8266\r\nConnection: close\r\n\r\n");
				HAL_UART_Receive_IT(&huart1, &rxBuffer[0], 1);
        if (rxIndex > 0)  
        {
            processReceivedData(rxBuffer, rxIndex);
        }
				HAL_Delay(2000);
		extract_date_from_http((const char *)rxBuffer); 	
    
		printf("+++");	HAL_Delay(5000);	
		printf("AT+CIPCLOSE\r\n");		HAL_Delay(1000);			
		rxIndex = 0;	
		HAL_UART_Receive_IT(&huart1, &rxBuffer[0], 1);
		HAL_UART_AbortReceive_IT(&huart1);		
		printf("+++");		HAL_Delay(1000);
		printf("\r\n");		HAL_Delay(1000);	
		printf("AT+RST\r\n");		HAL_Delay(1000);	
//	Paint_DrawNum(50, 33, 1234, &Font12, BLACK, WHITE);
//	EPD_2IN9_Display(BlackImage);
//	Paint_DrawString_EN(60, 0, update_result, &Font24, BLACK,WHITE);		
//	HAL_Delay(2000);    EPD_2IN9_Display(BlackImage);
		//clear(0,0,296,128,0X00);
		//clear(0,0,50,70,0XFF);
		DHT11_Read(&hum, &temp);
		Paint_DrawBitMapXY(gImage_wifi, 276, 0, 20, 20); // ����λ��
		Paint_DrawBitMapXY(gImage_hum, 0, 44, 20, 20); // ����λ��
		Paint_DrawBitMapXY(gImage_tem, 0,79, 20, 20); // ����λ��
		Paint_DrawString_EN(54, 44, "%", &Font20, WHITE, BLACK);
		Paint_DrawString_EN(54, 79, "C", &Font20, WHITE, BLACK);


		Paint_DrawString_EN(0, 2, real_time, &Font16, WHITE, BLACK);
	  clear(187,0,88,20,0XFF);
		year=((update_result[0]-'0')*1000+(update_result[1]-'0')*100+(update_result[2]-'0')*10+(update_result[3]-'0'));
		month=((update_result[5]-'0')*10+(update_result[6]-'0'));
		day=((update_result[8]-'0')*10+(update_result[9]-'0'));		
		
		Weekday(year,month,day);
		Paint_DrawString_EN(255, 112, tem_result, &Font16, WHITE, BLACK);

    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
		PAINT_TIME part_time;
		part_time.Hour=(real_time[17]-'0')*10+real_time[18]-'0'+8;
		part_time.Min=(real_time[20]-'0')*10+real_time[21]-'0';
		part_time.Sec=(real_time[23]-'0')*10+real_time[24]-'0';		
		Paint_DrawTime(100,51,&part_time,&Font48, WHITE, BLACK);
		while(1)
	{
		printf("%s   %s\n", text_result,update_result);
		DHT11_Read(&hum, &temp);
		printf("%d %d\n",hum,temp);
		clear(21,22,34,100,0XFF);
    Paint_DrawNum(20, 44, hum, &Font20, BLACK, WHITE);		
    Paint_DrawNum(20, 79, temp, &Font20, BLACK, WHITE);	
    EPD_2IN9_Display(BlackImage);
		HAL_Delay(8000);    

		
	}


  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
