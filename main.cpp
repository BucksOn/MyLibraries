#include "Library\stdafx.h"

void main()
{
	CGraphicsManager _cGraphics;

	if (_cGraphics.initWindow())
		_cGraphics.LoopWindow();

	_cGraphics.EndWIndow();
}