#pragma once
#include <ios>
#include <fstream>
#include "pugixml.cpp"

#ifndef CONFIGURE
#define CONFIGURE

using namespace std;
using namespace pugi;

static string name, background, forgeground, font;
static bool UseForground = true, UseFont = true, UseSelfFont = true;

void LoadEngineConfig()
{

}

void LoadGameConfig()
{
	fstream file;
	xml_document doc;
	//.
	file.open("game.xml", ios::in);
	if (file.good())
		doc.load_file("game.xml");
	file.close();
	//Game
	file.open(".\\Resources\\game.xml", ios::in);
	if (file.good())
		doc.load_file("game.xml");
	file.close();
	xml_node _name = doc.select_node("//Name").node;
	xml_node _background = doc.select_node("//Background").node;
	xml_node _forgeground = doc.select_node("//Forgeground").node;
	xml_attribute _font = _name.attribute("font");
	name = _name.child_value();
	background = _background.child_value();
	forgeground = _forgeground.child_value();
	font = _font.value;
	if (forgeground == "")UseForground = false;
	if (font == "")UseFont = false;
	if (font.find(".") + 1 || font.find("\\") + 1)UseSelfFont = false;
}



void LoadConfig()
{

}

#endif // !CONFIGURE
