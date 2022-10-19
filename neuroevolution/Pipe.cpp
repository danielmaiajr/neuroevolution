#include "Pipe.h"
#include "Bird.h"

Pipe::Pipe() :
	m_spacing(GetRandomValue(50, GetScreenHeight() / 2)),
	m_centery(GetRandomValue(m_spacing, GetScreenHeight() - m_spacing)),
	m_top(m_centery - m_spacing / 2),
	m_bottom(GetScreenHeight() - (m_centery + m_spacing / 2)),
	m_x(GetScreenWidth()),
	m_w(50),
	m_speed(5)
{}

bool Pipe::hits(Bird bird)
{
	if (bird.get_y() < m_top || bird.get_y() > GetScreenHeight() - m_bottom)
	{
		if (bird.get_x() > m_x && bird.get_x() < m_x + m_w)
		{
			return true;
		}
	}
	return false;
}

void Pipe::show()
{
	DrawRectangle(m_x, 0, m_w, m_top, RAYWHITE);
	DrawRectangle(m_x, GetScreenHeight() - m_bottom, m_w, m_bottom, RAYWHITE);
}

void Pipe::update()
{
	m_x -= m_speed;
}

bool Pipe::offscreen()
{
	if (m_x < -m_w)
	{
		return true;
	}
	else {
		return false;
	}
}