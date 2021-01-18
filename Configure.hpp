#pragma once
#include <ios>
#include <fstream>
#include "pugixml.cpp"

#ifndef CONFIGURE
#define CONFIGURE

using namespace std;
using namespace pugi;

static int FPS;
static string name, background, forgeground, font;
static bool UseForground = true, UseFont = true, UseSelfFont = true, LockFPS = false, AutoFullScreen;;

#define In(x,y,z) ((x)>=(y))&&((x)<=(z))
#define DEFAULT_CONFIGURE "<?xml version="1.0" encoding="utf-8"?><Config>  <LockFPS>false</LockFPS>  <AutoFullScreen>true</AutoFullScreen></Config>"//A const string in resources

inline int GetInt(string a)
{
	int result = 0;
	for (int i = 0; i < a.size(); i++)//12
	{
		result += ((double)a[i] - '0') * pow(10, a.size() - i - 1);
	}
	return result;
}

inline string strdpr(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (In(a[i], 'A', 'Z'))a[i] += 'a' - 'A';
	}
	return a;
}

void LoadEngineConfig()
{
	fstream file;
	file.open("config.xml", ios::in);
	if (!file.good())
	{//不存在 加载默认值
		file.close();
		file.open("config.xml", ios::out);
		file << DEFAULT_CONFIGURE;
	}
	file.close();
	xml_document doc;
	doc.load_file("config.xml");
	xml_node _lockfps = doc.select_node("//LockFPS").node();
	xml_node _fps = doc.select_node("FPS").node();
	xml_node _autofullscreen = doc.select_node("AutoFullScreen").node();
	if (strdpr(_lockfps.child_value()) == "true") LockFPS = true;
	if (LockFPS) FPS = GetInt(_fps.child_value());
	else FPS = 0;
	if (strdpr(_autofullscreen.child_value()) == "true") AutoFullScreen = true;
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
	xml_node _name = doc.select_node("//Name").node();
	xml_node _background = doc.select_node("//Background").node();
	xml_node _forgeground = doc.select_node("//Forgeground").node();
	xml_attribute _font = _name.attribute("font");
	name = _name.child_value();
	background = _background.child_value();
	forgeground = _forgeground.child_value();
	font = _font.value();
	if (forgeground == "")UseForground = false;
	if (font == "")UseFont = false;
	if (font.find(".") + 1 || font.find("\\") + 1)UseSelfFont = false;
}

void LoadLevel() //Pre-LoadSupport
{
	fstream file;
	file.open("level.xml", ios::in);
	if (!file.good())throw 0;
}

void LoadConfig()
{

}

#endif // !CONFIGURE
