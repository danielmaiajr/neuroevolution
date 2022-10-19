#pragma once
#include "Matrix.h"

class NeuroNetwork
{
	int m_input_nodes;
	int m_hidden_nodes;
	int m_output_nodes;

	My_Matrix weights_ih;
	My_Matrix weights_ho;

	My_Matrix bias_h;
	My_Matrix bias_o;

public:
	NeuroNetwork(int input_nodes, int hidden_nodes,	int output_nodes):
		m_input_nodes(input_nodes),
		m_hidden_nodes(hidden_nodes),
		m_output_nodes(output_nodes),
		weights_ih(hidden_nodes, input_nodes),
		weights_ho(output_nodes, hidden_nodes),
		bias_h(hidden_nodes, 1),
		bias_o(output_nodes, 1)
	{
		weights_ih.randomize();
		weights_ho.randomize();

		bias_h.randomize();
		bias_o.randomize();
	}

	My_Matrix feedForward(std::vector<float> &v)
	{
		My_Matrix input(v);
		My_Matrix hidden(m_hidden_nodes, 1);

		hidden.multiply(weights_ih, input);
		hidden.add(bias_h);
		hidden.map(sigmoid);

		My_Matrix output(m_output_nodes, 1);
		output.multiply(weights_ho, hidden);
		output.add(bias_o);
		output.map(sigmoid);

		return output;
	}

	std::function<float(float)> sigmoid = [](float x) { return x / (1 + abs(x)); };
};