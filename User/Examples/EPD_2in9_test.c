/*****************************************************************************
* | File      	:   EPD_2IN9_test.c
* | Author      :   Waveshare team
* | Function    :   2.9inch e-paper test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-06-11
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "EPD_Test.h"
#include "EPD_2in9.h"
UBYTE *BlackImage ;
int EPD_test(void)
{    Paint_DrawString_CN(130, 0,"你好ht", &Font12CN, BLACK, WHITE);
			DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage); 		
    printf("EPD_2IN9_test Demo\r\n");
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN9_Init(EPD_2IN9_FULL);
    EPD_2IN9_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlackImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN9_WIDTH % 8 == 0)? (EPD_2IN9_WIDTH / 8 ): (EPD_2IN9_WIDTH / 8 + 1)) * EPD_2IN9_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT, 270, WHITE);

#if 1   //show image for array    
    printf("show image for array\r\n");
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_DrawBitMap(gImage_2in9);

    EPD_2IN9_Display(BlackImage);
    DEV_Delay_ms(2000);
#endif
    EPD_2IN9_Clear();
#if 1   // Drawing on the image
    printf("Drawing\r\n");
    //1.Select Image
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    // 2.Drawing on the image
    printf("Drawing:BlackImage\r\n");
    Paint_DrawPoint(10, 80, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    Paint_DrawPoint(10, 90, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
    Paint_DrawPoint(10, 100, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
    Paint_DrawLine(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
		Paint_DrawLine(70, 70, 20, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawRectangle(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);  
		Paint_DrawRectangle(80, 70, 130, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawCircle(45, 95, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);    
		Paint_DrawCircle(105, 95, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
    Paint_DrawLine(85, 95, 125, 95, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);    
		Paint_DrawLine(105, 75, 105, 115, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
    Paint_DrawString_EN(10, 0, "waveshare", &Font16, BLACK, WHITE);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);    
		Paint_DrawString_EN(10, 20, "hello hantao", &Font12, WHITE, BLACK);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
    Paint_DrawNum(10, 33, 123456789, &Font12, BLACK, WHITE);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);    
		Paint_DrawNum(10, 50, 987654321, &Font16, WHITE, BLACK);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
    Paint_DrawString_CN(130, 0,"你好周一", &Font12CN, WHITE, BLACK);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);    
		Paint_DrawString_CN(130, 20, "微雪电子", &Font24CN, WHITE, BLACK);
    DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
    DEV_Delay_ms(2000);
#endif

#if 1   //Partial refresh, example shows time    		
    printf("Partial refresh\r\n");
    EPD_2IN9_Init(EPD_2IN9_PART);
    Paint_SelectImage(BlackImage);
    PAINT_TIME sPaint_time;
    sPaint_time.Hour = 12;
    sPaint_time.Min = 34;
    sPaint_time.Sec = 56;
    UBYTE num = 50;
    for (;;) {
        sPaint_time.Sec = sPaint_time.Sec + 1;
        if (sPaint_time.Sec == 60) {
            sPaint_time.Min = sPaint_time.Min + 1;
            sPaint_time.Sec = 0;
            if (sPaint_time.Min == 60) {
                sPaint_time.Hour =  sPaint_time.Hour + 1;
                sPaint_time.Min = 0;
                if (sPaint_time.Hour == 24) {
                    sPaint_time.Hour = 0;
                    sPaint_time.Min = 0;
                    sPaint_time.Sec = 0;
                }
            }
        }
        Paint_ClearWindows(150, 80, 150 + Font20.Width * 7, 80 + Font20.Height, WHITE);
        Paint_DrawTime(150, 80, &sPaint_time, &Font20, WHITE, BLACK);

       // num = num - 1;
        if(num == 0) {
            break;
        }
        EPD_2IN9_Display(BlackImage);
        DEV_Delay_ms(500);//Analog clock 1s
    }

#endif
    printf("Clear...\r\n");
    EPD_2IN9_Init(EPD_2IN9_FULL);
    EPD_2IN9_Clear();

    printf("Goto Sleep...\r\n");
    EPD_2IN9_Sleep();
    free(BlackImage);
    BlackImage = NULL;

    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
    
    return 0;
}


void Weekday(int year,int month,int day)
{
	
if (month < 3)
		{
			year -= 1;
			month += 12;
		}
		int c = (year / 100), y = year - 100 * c;
		int w = (c / 4) - 2 * c + y + (y / 4) + (26 * (month + 1) / 10) + day - 1;
		w = (w % 7 + 7) % 7;

char b[7][6] = { "周日","周一","周二","周三","周四","周五","周六" };
Paint_DrawString_CN(255, 70,b[w], &Font12CN, BLACK, WHITE);		
Paint_DrawString_CN(255, 92,"霾", &Font12CN, BLACK, WHITE);	
DEV_Delay_ms(2000);    EPD_2IN9_Display(BlackImage);
}


