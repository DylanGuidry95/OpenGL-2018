#pragma once
#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <string>

extern std::string PrintMatrix(glm::mat4 matrix)
{
	std::string data = "";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data += int(matrix[i][j]) + ' ';
		}
		data += '\n';
	}
	return data;
}