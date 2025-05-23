/**
  ******************************************************************************
  * @file    Font12.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-February-2014
  * @brief   This file provides text Font12 for STM32xx-EVAL's LCD driver. 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"


// 
//  Font data for Courier New 12pt
// 

const CH_CN Font12CN_Table[] = 
{
/*--  文字:  你  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"你",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1D,0xC0,0x1D,0x80,0x3B,0xFF,0x3B,0x07,
0x3F,0x77,0x7E,0x76,0xF8,0x70,0xFB,0xFE,0xFB,0xFE,0x3F,0x77,0x3F,0x77,0x3E,0x73,
0x38,0x70,0x38,0x70,0x3B,0xE0,0x00,0x00,0x00,0x00},

/*--  文字:  好  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"好",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x73,0xFF,0x70,0x0F,0xFE,0x1E,
0x7E,0x3C,0x6E,0x38,0xEE,0x30,0xEF,0xFF,0xFC,0x30,0x7C,0x30,0x38,0x30,0x3E,0x30,
0x7E,0x30,0xE0,0x30,0xC1,0xF0,0x00,0x00,0x00,0x00},

/*--  文字:  树  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"树",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x0E,0x30,0x0E,0x3F,0xEE,0x30,0xEE,
0xFC,0xFF,0x76,0xCE,0x77,0xFE,0x7B,0xFE,0xFF,0xFE,0xF3,0xDE,0xF3,0xCE,0x37,0xEE,
0x3E,0x6E,0x3C,0x0E,0x30,0x3E,0x00,0x00,0x00,0x00},

/*--  文字:  莓  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"莓",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x70,0xFF,0xFF,0x3E,0x70,0x38,0x00,
0x7F,0xFF,0xE0,0x00,0xFF,0xFC,0x3B,0x8C,0x39,0xCC,0xFF,0xFF,0x73,0x9C,0x71,0xDC,
0x7F,0xFF,0x00,0x1C,0x01,0xF8,0x00,0x00,0x00,0x00},

/*--  文字:  派  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"派",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x1F,0xFF,0xF0,0x3E,0x00,0x0E,0x1F,
0xCF,0xFB,0xFF,0xF8,0x3F,0xFF,0x0F,0xFF,0x7F,0xD8,0x7F,0xDC,0x6F,0xCE,0xED,0xFF,
0xFD,0xF7,0xF9,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  a  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"a",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3E,0x00,0x67,0x00,0x07,0x80,0x0F,0x80,0x7F,0x80,0xE3,0x80,0xE7,0x80,0xE7,0x80,
0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  b  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"b",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x70,0x00,0x70,0x00,0x70,0x00,
0x7F,0x00,0x7B,0x80,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x7B,0x80,
0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  c  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"c",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3F,0x00,0x73,0x00,0xF0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xF0,0x00,0x73,0x00,
0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  A  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"A",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x1F,0x00,0x1F,0x00,
0x1F,0x00,0x3B,0x80,0x3B,0x80,0x71,0x80,0x7F,0xC0,0x71,0xC0,0xE0,0xE0,0xE0,0xE0,
0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  周  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"周",
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0x70,0x07,0x71,0xC7,
0x7F,0xFF,0x71,0xC7,0x71,0xC7,0x7F,0xFF,0x70,0x07,0x7F,0xF7,0x6E,0x37,0x6E,0x37,
0xEF,0xF7,0xEE,0x07,0xC0,0x3E,0x00,0x00,0x00,0x00},

/*--  文字:  一  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"一",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  二  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"二",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  三  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"三",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  四  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"四",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0x67,0x67,0x67,0x67,
0x67,0x67,0x67,0x67,0x66,0x67,0x66,0x67,0x6E,0x67,0x7C,0x7F,0x78,0x07,0x60,0x07,
0x60,0x07,0x7F,0xFF,0x60,0x07,0x00,0x00,0x00,0x00},

/*--  文字:  五  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"五",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x06,0x00,0x06,0x00,
0x0E,0x00,0x0E,0x00,0xFF,0xFC,0x0E,0x1C,0x0C,0x1C,0x0C,0x1C,0x1C,0x1C,0x1C,0x1C,
0x1C,0x1C,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},

/*--  文字:  六  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"六",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x03,0x80,0x01,0xC0,0x01,0xC0,
0xFF,0xFF,0x00,0x00,0x00,0x00,0x0E,0x70,0x0E,0x70,0x1C,0x38,0x38,0x1C,0x38,0x0E,
0x70,0x0E,0xE0,0x07,0xE0,0x07,0x00,0x00,0x00,0x00},

/*--  文字:  日  --*/
/*--  微软雅黑12;  此字体下对应的点阵为：宽x高=16x21   --*/
{"日",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFC,0x38,0x1C,0x38,0x1C,
0x38,0x1C,0x38,0x1C,0x38,0x1C,0x3F,0xFC,0x38,0x1C,0x38,0x1C,0x38,0x1C,0x38,0x1C,
0x38,0x1C,0x3F,0xFC,0x38,0x1C,0x00,0x00,0x00,0x00},

/*--  文字:  晴  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"晴",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0xFC,0x70,0xFF,0xFF,
0xFC,0x70,0xFF,0xFF,0xFC,0x00,0xFF,0xFF,0xFF,0x87,0xFF,0xFF,0xFF,0x87,0xFF,0xFF,
0xFF,0x87,0xFF,0x87,0x03,0xBE,0x00,0x00,0x00,0x00,},

/*--  文字:  多  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"多",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x07,0x00,0x0F,0xFE,0x1C,0x1C,
0x7E,0x78,0xE7,0xE0,0x07,0x80,0x3E,0xF0,0xF3,0xFF,0x07,0x0E,0x1F,0x1C,0x73,0xF8,
0x01,0xE0,0x0F,0x80,0xF8,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  云  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"云",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xFF,0x07,0x00,0x07,0x00,0x0E,0x70,0x1C,0x78,0x1C,0x3C,
0x38,0x1C,0x7F,0xFE,0x00,0x07,0x00,0x00,0x00,0x00,},

/*--  文字:  间  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"间",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x7F,0xFF,0x1C,0x07,0xE0,0x07,
0xEF,0xF7,0xEE,0x77,0xEE,0x77,0xEF,0xF7,0xEE,0x77,0xEE,0x77,0xEE,0x77,0xEF,0xF7,
0xEE,0x07,0xE0,0x07,0xE0,0x3E,0x00,0x00,0x00,0x00,},

/*--  文字:  大  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"大",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0xFF,0xFF,0x03,0x80,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x07,0xE0,0x0E,0x60,0x0E,0x70,
0x3C,0x38,0x70,0x1E,0xE0,0x07,0x00,0x00,0x00,0x00,},

/*--  文字:  部  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"部",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x0E,0x7F,0xFF,0xF7,0x73,0xF7,
0x37,0x7E,0x3E,0x7C,0xFF,0xFE,0x00,0x77,0x00,0x77,0x7F,0xF3,0x63,0xF3,0x63,0xF3,
0x63,0xFF,0x7F,0xF0,0x63,0xF0,0x00,0x00,0x00,0x00,},

/*--  文字:  阴  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"阴",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xEF,0x87,0xFF,0x87,0xFF,0x87,
0xFB,0xFF,0xFB,0x87,0xFF,0x87,0xFF,0x87,0xEF,0xFF,0xEF,0x87,0xEF,0x87,0xFF,0x07,
0xE7,0x06,0xEE,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  阵  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"阵",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFC,0xE0,0xFF,0xFF,0xFD,0xC0,
0xF9,0xF8,0xFB,0xB8,0xFB,0xB8,0xFF,0xFF,0xFC,0x38,0xFC,0x38,0xFF,0xFF,0xFC,0x38,
0xE0,0x38,0xE0,0x38,0xE0,0x38,0x00,0x00,0x00,0x00,},

/*--  文字:  雨  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"雨",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x01,0x80,0x01,0x80,
0x7F,0xFE,0x61,0x86,0x79,0xE6,0x6F,0xFE,0x67,0x9E,0x79,0xE6,0x7D,0xFE,0x67,0x9E,
0x61,0x86,0x61,0xBE,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  雷  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"雷",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x01,0x80,0xFF,0xFF,
0xE1,0x87,0xFF,0xFF,0x01,0x80,0x3F,0xFC,0x00,0x00,0x7F,0xFE,0x71,0x8E,0x7F,0xFE,
0x71,0x8E,0x7F,0xFE,0x70,0x0E,0x00,0x00,0x00,0x00,},

/*--  文字:  伴  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"伴",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x70,0x1C,0x70,0x3E,0x77,0x3F,0x7F,
0x3B,0xFC,0x78,0x70,0xFF,0xFF,0xF8,0x70,0xF8,0x70,0x38,0x70,0x3F,0xFF,0x38,0x70,
0x38,0x70,0x38,0x70,0x38,0x70,0x38,0x70,0x00,0x00,},

/*--  文字:  有  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"有",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x07,0x00,0xFF,0xFF,0x0E,0x00,
0x1C,0x00,0x3F,0xFE,0x78,0x0E,0xFF,0xFE,0xD8,0x0E,0x18,0x0E,0x1F,0xFE,0x18,0x0E,
0x18,0x0C,0x18,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  冰  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"冰",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0xE0,0x70,0xE7,
0x3F,0xFF,0x03,0xFC,0x03,0xF8,0x33,0xF8,0x37,0xF8,0x77,0xFC,0x6E,0xEE,0x6E,0xEF,
0xFC,0xE7,0xD8,0xE0,0x03,0xE0,0x00,0x00,0x00,0x00,},

/*--  文字:  雹  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"雹",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x01,0x80,0xFF,0xFF,0xE1,0x87,
0xFF,0xFF,0x1D,0x80,0x3F,0xFE,0x30,0x0E,0x7F,0xEE,0xF8,0xEE,0x3F,0xEF,0x38,0x7F,
0x38,0x07,0x1F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  小  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"小",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x1D,0xF8,
0x39,0xFC,0x39,0xDC,0x71,0xCE,0x71,0xCE,0x61,0xCF,0xE1,0xC7,0xC1,0xC7,0x01,0xC0,
0x01,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  中  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"中",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x01,0x80,0x7F,0xFE,
0x61,0x86,0x61,0x86,0x61,0x86,0x61,0x86,0x7F,0xFE,0x61,0x86,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,},

/*--  文字:  暴  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"暴",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFE,0x30,0x0E,0x3F,0xFE,
0x30,0x0E,0x3F,0xFE,0x0E,0x70,0x7F,0xFF,0x0E,0x70,0xFF,0xFF,0x1D,0xF8,0x3F,0xFC,
0xE7,0xE7,0x3D,0xBC,0x7F,0x8E,0x00,0x00,0x00,0x00,},

/*--  文字:  特  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"特",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x70,0xF8,0x70,0xFB,0xFF,0xFE,0x70,
0xF8,0x70,0xFF,0xFF,0xF8,0x00,0x38,0x1C,0x3F,0xFF,0xFB,0x9C,0x3B,0xDC,0x38,0xDC,
0x38,0x1C,0x38,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  冻  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"冻",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0xE1,0xC0,0xFF,0xFF,0x73,0x80,
0x37,0x70,0x07,0x70,0x06,0x70,0x3F,0xFF,0x30,0x70,0x73,0x7C,0x67,0x7E,0x6E,0x77,
0xEE,0x77,0xDC,0x73,0x01,0xE0,0x00,0x00,0x00,0x00,},

/*--  文字:  夹  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"夹",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0xFF,0xFF,0x01,0x80,
0x31,0x8C,0x39,0xBC,0x1D,0xB8,0x01,0x80,0xFF,0xFF,0x03,0xC0,0x07,0xC0,0x06,0x60,
0x1C,0x70,0x78,0x1C,0xE0,0x07,0x00,0x00,0x00,0x00,},

/*--  文字:  雪  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"雪",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x01,0x80,0xFF,0xFF,
0xE1,0x87,0xFF,0xFF,0x01,0x80,0x3F,0xFC,0x00,0x00,0x7F,0xFE,0x00,0x0E,0x7F,0xFE,
0x00,0x0E,0x7F,0xFE,0x00,0x0E,0x00,0x00,0x00,0x00,},

/*--  文字:  浮  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"浮",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x1F,0xFF,0xF0,0x3E,0xCE,
0xC7,0xFC,0xF0,0x00,0x7F,0xFE,0x00,0x1C,0x70,0x38,0x7F,0xFF,0x70,0x70,0xE0,0x70,
0xE0,0x70,0xE3,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  尘  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"尘",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x01,0xC0,0x0D,0xF8,0x1D,0xFC,
0x39,0xCF,0x71,0xC7,0xE0,0x00,0x01,0xC0,0x01,0xC0,0x7F,0xFE,0x01,0xC0,0x01,0xC0,
0x01,0xC0,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  扬  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"扬",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x37,0xFE,0x30,0x3C,0xFC,0x78,
0x31,0xE0,0x33,0xC0,0x3F,0xFF,0x79,0xDF,0xF1,0xFF,0x33,0xBF,0x37,0x77,0x3E,0xE7,
0x31,0xC6,0xF3,0xBE,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  沙  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"沙",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0xF8,0x60,0x1B,0xFC,0x03,0x6E,
0xC7,0x6E,0xF6,0x67,0x3E,0x63,0x0C,0x66,0x38,0x6E,0x30,0x1C,0x70,0x38,0x70,0xF0,
0xE3,0xC0,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  强  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"强",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x1F,0x86,0x1F,0x86,
0x1F,0xFE,0xFF,0xF6,0xDC,0x70,0xC7,0xFF,0xFF,0x77,0x1F,0x77,0x1F,0xFF,0x1F,0x70,
0x1C,0x77,0x18,0xFF,0xFF,0xC3,0x00,0x00,0x00,0x00,},

/*--  文字:  雾  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"雾",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x01,0x80,0xFF,0xFF,
0xE1,0x87,0x3F,0xFC,0x1C,0x00,0x3F,0xFE,0xEE,0x3C,0x07,0xE0,0xFE,0x7F,0x03,0x00,
0x3F,0xFE,0x0F,0x0C,0xFD,0xFC,0x00,0x00,0x00,0x00,},

/*--  文字:  霾  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"霾",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x01,0x80,0xFF,0xFF,0xE1,0x87,
0x1E,0x00,0xF9,0xFF,0x7D,0xB7,0x7F,0xFF,0xFD,0xB7,0xDF,0xFF,0xFE,0x30,0x3F,0xFF,
0xFE,0x30,0x3F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  风  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"风",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFC,0x70,0x1C,0x7C,0x7C,
0x7E,0xFC,0x77,0xDC,0x77,0xDC,0x73,0x9C,0x77,0xDC,0x7E,0xFC,0x7C,0x7F,0xF8,0x7F,
0xE0,0x0F,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,},

/*--  文字:  冷  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"冷",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xC0,0xF0,0xE1,0xF8,0x73,0xB8,
0x37,0xDC,0x0E,0xEE,0x1C,0x73,0x00,0x00,0x7F,0xFE,0x70,0x0E,0x70,0x1C,0xE7,0x38,
0xE3,0xF0,0xE0,0xF0,0x00,0x38,0x00,0x00,0x00,0x00,},

/*--  文字:  热  --*/
/*--  微软雅黑8;  此字体下对应的点阵为：宽x高=16x21   --*/
{"热",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xE0,0x38,0xE0,0xFF,0xFC,0x38,0xDC,
0x3F,0xDC,0x7B,0xDC,0xF9,0xFF,0x3B,0xFF,0x3F,0x8F,0xFE,0x0F,0x00,0x00,0x7E,0xEC,
0x7E,0xEE,0xE7,0x77,0xE7,0x73,0x00,0x00,0x00,0x00,},




};
cFONT Font12CN = {
  Font12CN_Table,
  sizeof(Font12CN_Table)/sizeof(CH_CN),  /*size of table*/
  11, /* ASCII Width */
  16, /* Width */
  21, /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
