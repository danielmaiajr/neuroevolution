
#include <raylib.h>
#include "NeuroNetwork.h"
#include <deque>


#pragma once

class Pipe;

class Bird
{
	int m_width;
	int m_height;
	int m_x;
	int m_y;

	int m_gravity;
	int m_velocity;

	NeuroNetwork nn;

public:
	Bird(const int& x, const int& y);

	int get_w() { return m_width; }
	int get_h() { return m_height; }
	int get_x() { return m_x; }
	int get_y() { return m_y; }

	void think(std::deque<Pipe> Pipe);
	void update();
	void show();
	
	/*
	void handle_keypressed()
		
	{
		if (GetKeyPressed() == 32)
		{
			m_velocity -= 20;
		}
	}
	*/
};