#include <iostream>
#include "Canvas.h"
#include <windows.h>

int main()
{
	Canvas c{ 30, 30 };

	c.DrawCircle(15, 15, 10, 'a');
	c.Print();
	Sleep(3 * 1000);
	c.Clear();

	c.FillCircle(15, 15, 10, 'a');
	c.Print();
	Sleep(3 * 1000);
	c.Clear();

	c.DrawRect(10, 10, 20, 20, 'a');
	c.Print();
	Sleep(3 * 1000);
	c.Clear();

	c.FillRect(10, 10, 20, 20, 'a');
	c.Print();
	Sleep(3 * 1000);
	c.Clear();

	c.SetPoint(10, 10, 'a');
	c.Print();
	Sleep(3 * 1000);
	c.Clear();

	c.DrawLine(10, 10, 20, 20, 'a');
	c.Print();
	Sleep(3 * 1000);
	c.Clear();

	return 0;
}