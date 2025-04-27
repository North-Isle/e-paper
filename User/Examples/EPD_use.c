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




#include "EPD_use.h"

UBYTE *BlackImage ;


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


