#include "Bird.h"
#include "Pipe.h"

Bird::Bird(const int& x, const int& y) :
	m_width(x * 2),
	m_height(y * 2),
	m_x(x), m_y(y),
	m_gravity(1),
	m_velocity(0),
	nn(4, 4, 1)
{}

void Bird::show()
{
	DrawCircle(m_x, m_y, 16, RAYWHITE);
}

void Bird::think(std::deque<Pipe> pipe)
{
	std::vector<float> input = { (float)m_y , (float)pipe[0].getTop(), (float)pipe[0].getBottom() , (float)pipe[0].getX() };
	My_Matrix output = nn.feedForward(input);

	if (output.get_matrix()[0][0] > 0)
	{
		m_velocity -= 20;
	}
}

void Bird::update()
{

	m_velocity += m_gravity;
	m_y += m_velocity;


	if (m_y > m_height)
	{
		m_y = m_height;
		m_velocity = 0;
	}

	if (m_y < 0)
	{
		m_y = 0;
		m_velocity = 0;
	}
	//handle_keypressed();
}