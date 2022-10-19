#pragma once

#include <vector>
#include <iostream>
#include <raylib.h>
#include <functional>
#include "Random.h"

class My_Matrix
{
	int m_rows;
	int m_cols;
	std::vector<std::vector<float>> data;

public:

	My_Matrix(int rows, int cols):
		m_rows(rows),
		m_cols(cols)
	{
		data.resize(m_rows);
		for (int i = 0; i < m_rows; i++)
		{
			data[i].resize(m_cols);
		}

		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				data[i][j] = 0;
			}
		}
	}

	My_Matrix(std::vector<float> &v):
		m_rows(v.size()),
		m_cols(1)
	{
		data.resize(m_rows);
		for (int i = 0; i < m_rows; i++)
		{
			data[i].resize(m_cols);
			data[i][0] = v[i];
		}
	}


	int get_rows() { return m_rows; }
	int get_cols() { return m_cols; }
	std::vector<std::vector<float>> get_matrix() {	return data; }

	void print()
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				std::cout << data[i][j] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	void randomize()
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				data[i][j] = Random::Float();
			}
		}
	}

	void transpose(My_Matrix m)
	{
		My_Matrix result(m_rows, m_cols);
		for (int i = 0; i < m.get_rows(); i++)
		{
			for (int j = 0; j < m.get_cols(); j++)
			{
				result.data[j][i] = m.data[i][j];
			}
		}
		data = result.data;
	}

	void map(std::function<float (float)>func)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				data[i][j] = func(data[i][j]);
			}
		}
	}

	void multiply(float n)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				data[i][j] *= n;
			}
		}
	}

	void multiply(My_Matrix m1, My_Matrix m2)
	{
		My_Matrix result(m1.get_rows(), m2.get_cols());
		for (int i = 0; i < result.get_rows(); i++)
		{
			for (int j = 0; j < result.get_cols(); j++)
			{
				float sum = 0;
				for (int k = 0; k < m1.get_cols(); k++)
				{
					sum += m1.data[i][k] * m2.data[k][j];
				}
				result.data[i][j] = sum;
			}
		}
		data = result.data;
	}

	void add(float n)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				data[i][j] += n;
			}
		}
	}

	void add(My_Matrix m)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < m_cols; j++)
			{
				data[i][j] += m.get_matrix()[i][j];
			}
		}
	}
};