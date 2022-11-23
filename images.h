const unsigned char bulb[] = { /*0X00,0X01,0X20,0X00,0X20,0X00,*/
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X80,0X00,
0X00,0X01,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X01,0X00,0X00,0XC7,0XE3,0X00,
0X00,0X1C,0X38,0X00,0X00,0X30,0X0C,0X00,0X00,0X20,0XE4,0X00,0X00,0X40,0X32,0X00,
0X00,0X40,0X12,0X00,0X00,0X40,0X1A,0X00,0X06,0XC0,0X0B,0X60,0X00,0X40,0X02,0X00,
0X00,0X40,0X02,0X00,0X00,0X60,0X06,0X00,0X00,0X20,0X04,0X00,0X00,0X10,0X08,0X00,
0X00,0X08,0X10,0X00,0X00,0X08,0X00,0X00,0X00,0X0F,0XE0,0X00,0X00,0X0F,0XF0,0X00,
0X00,0X0F,0XF0,0X00,0X00,0X0F,0XF0,0X00,0X00,0X06,0X60,0X00,0X00,0X06,0X60,0X00,
0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};

const unsigned char clouds[] = { /*0X00,0X01,0X32,0X00,0X32,0X00,*/
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0X00,0X00,
0X00,0X00,0X00,0X00,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0XFF,0XF0,0X00,0X00,0X00,
0X00,0X03,0XFF,0XF8,0X00,0X00,0X00,0X00,0X03,0XFF,0XFC,0X80,0X00,0X00,0X00,0X07,
0XFF,0XFF,0XF8,0X00,0X00,0X00,0X07,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X07,0XFF,0XFF,
0XFE,0X00,0X00,0X00,0X07,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XFF,0X00,
0X00,0X00,0X7F,0XFF,0XFF,0XFF,0X80,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X01,
0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X03,0XFF,0XFF,
0XFF,0XFF,0XE0,0X00,0X07,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X07,0XFF,0XFF,0XFF,0XFF,
0XF0,0X00,0X07,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X03,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X03,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X01,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0X01,0XFF,
0XFF,0XFF,0XFF,0XC0,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X1F,0XFF,0XFF,
0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char clearSky[] = { /*0X00,0X01,0X32,0X00,0X32,0X00,*/
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,
0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X00,0X00,
0X00,0X00,0X03,0X00,0XC0,0X30,0X00,0X00,0X00,0X03,0X80,0XC0,0X30,0X00,0X00,0X00,
0X01,0X80,0XC0,0X60,0X00,0X00,0X00,0X00,0XC0,0X00,0XE0,0X00,0X00,0X00,0X00,0XC0,
0X00,0XC0,0X00,0X00,0X00,0X00,0X40,0X00,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X80,0X01,0XE0,0X00,0X70,0X00,0X01,0XE0,0X0F,0XFC,0X01,0XE0,0X00,
0X00,0X78,0X1F,0XFE,0X03,0X80,0X00,0X00,0X38,0X3F,0XFF,0X03,0X00,0X00,0X00,0X00,
0X7F,0XFF,0X80,0X00,0X00,0X00,0X00,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0XFF,0XFF,
0XE0,0X00,0X00,0X00,0X01,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X01,0XFF,0XFF,0XE0,0X00,
0X00,0X00,0X03,0XFF,0XFF,0XF0,0X00,0X00,0X0F,0XC3,0XFF,0XFF,0XF0,0XFC,0X00,0X0F,
0XC3,0XFF,0XFF,0XF0,0XFC,0X00,0X00,0X03,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X01,0XFF,
0XFF,0XE0,0X00,0X00,0X00,0X01,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0XFF,0XFF,0XC0,
0X00,0X00,0X00,0X00,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X7F,0XFF,0X80,0X00,0X00,
0X00,0X38,0X3F,0XFF,0X03,0X00,0X00,0X00,0X70,0X1F,0XFE,0X03,0XC0,0X00,0X01,0XC0,
0X07,0XF8,0X00,0XE0,0X00,0X01,0X80,0X01,0XE0,0X00,0X60,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X00,0XC0,0X00,
0X00,0X00,0X01,0XC0,0X00,0XE0,0X00,0X00,0X00,0X01,0X80,0XC0,0X60,0X00,0X00,0X00,
0X03,0X80,0XC0,0X30,0X00,0X00,0X00,0X03,0X00,0XC0,0X30,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};
