#include <raylib.h>

#pragma once
class Bird;

class Pipe
{
	int m_spacing;
	int m_centery;
	int m_top;
	int m_bottom;
	int m_x;
	int m_w;
	int m_speed;

public:
	Pipe();

	int getTop() { return m_top; }
	int getBottom() { return m_bottom; }
	int getX() { return m_x; }

	bool hits(Bird bird);
	bool offscreen();

	void show();
	void update();
};