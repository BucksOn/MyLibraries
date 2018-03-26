#pragma once

#define __D_SCREEN_WIDTH__ 1366
#define __D_SCREEN_HEIGHT__ 768
#define __D_FRAME_MAX__ 60

typedef struct __ST_POSITION__
{
	float _xPos;
	float _yPos;

	__ST_POSITION__() {}

	__ST_POSITION__(int x, int y)
	{
		_xPos = x;
		_yPos = y;
	}
} stPos;