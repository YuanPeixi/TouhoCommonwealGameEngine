#pragma once
#include <string>

using namespace std;

void strupr(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'a' - 'A';
		}
	}
}

void Interpreter(string command)
{
	strupr(command);
	if (command.find("DO"))
	{

	}
	if (command.find("SET"))
	{

	}
	if (command.find("DEF"))
	{

	}
	if (command.find("()"))
	{//DO or DEF
		int index = command.find("()");
		if (command[(size_t)index + 1] != '=' && command[(size_t)index + 2] != '=')//DO
		{

		}
		else
		{//DEF

		}
	}
	if (command.find("=" && command.find("()") == -1))
	{
		
	}
	else
	{//THROW UN+KNOW COMMAND

	}
}