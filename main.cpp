#include "stdafx.h"

void main()
{
	CGraphicsManager _cGraphics;

	_cGraphics.InitWindow(__D_SCREEN_WIDTH__, __D_SCREEN_HEIGHT__);

	_cGraphics.LoopWindow();

	_cGraphics.EndWIndow();
}