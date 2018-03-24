#pragma once

class CGraphicsManager
{
	float				_fTime;

	GLFWwindow * _Window;
	CManager	 _cManager;


	void Error(const std::string& error);
public:

	void InitWindow(const int& width, const int& height);
	void LoopWindow();
	void EndWIndow();
};