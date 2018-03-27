#pragma once
/* @ Graphics Manager
   @ Initialize Window & Main Render _ Call Manager
   @ Graphics Manager -> Manager(Object) -> Each Objects Draw */
class CGraphicsManager
{
	GLFWwindow * _Window; //!< window
	CManager	 _cManager; //!< object manager

	float		_fTime; //!< frame time

private:
	bool initGLFW();
	void windowSetting();
	bool createWindow();
	bool initGLEW();

public:
	bool initWindow();

	void LoopWindow();
	void EndWIndow();
};