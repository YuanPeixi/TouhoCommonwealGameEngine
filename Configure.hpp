#pragma once
#include <ios>
#include <fstream>
#include "pugixml.cpp"
#include <vector>
#include "resource.h"

#ifndef CONFIGURE
#define CONFIGURE

using namespace std;
using namespace pugi;

static int FPS;
static int LogStage=2;
static string* Level;
static string name, background, forgeground, font;
static bool UseForground = true, UseFont = true, UseSelfFont = true, LockFPS = false, AutoFullScreen,NotShowWarning=false,NotShowError=false;

#define In(x,y,z) ((x)>=(y))&&((x)<=(z))
//#define DEFAULT_CONFIGURE "a"//A const string in resources

inline int GetInt(string a)
{
	int result = 0;
	for (size_t i = 0; i < a.size(); i++)//12
	{
		result += ((double)a[i] - '0') * pow(10, a.size() - i - 1);
	}
	return result;
}

inline string strdpr(string a)
{
	for (size_t i = 0; i < a.size(); i++)
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
		CString strValue((LPCTSTR)DEFAULT_CONFIGURE);
		file.close();
		file.open("config.xml", ios::out);
		file << strValue;
	}
	file.close();
	xml_document doc;
	doc.load_file("config.xml");
	xml_node _lockfps = doc.select_node("//LockFPS").node();
	xml_node _fps = doc.select_node("//FPS").node();
	xml_node _autofullscreen = doc.select_node("//AutoFullScreen").node();
	xml_node _notshowwarning = doc.select_node("//NotShowWarning").node();
	xml_node _notshowerror = doc.select_node("//NotShowError").node();
	xml_node _logstage = doc.select_node("//LogStage").node();
	if (strdpr(_lockfps.child_value()) == "true") LockFPS = true;
	if (LockFPS) FPS = GetInt(_fps.child_value());
	else FPS = 0;
	if (strdpr(_autofullscreen.child_value()) == "true") AutoFullScreen = true;
	if (strdpr(_notshowerror.child_value()) == "true") NotShowError = true;
	if (strdpr(_notshowerror.child_value()) == "true") NotShowWarning = true;
	if (_logstage.child_value() == "Everything")LogStage = 0;
	if (_logstage.child_value() == "Event")LogStage = 1;
	if (_logstage.child_value() == "Warning")LogStage = 2;
	if (_logstage.child_value() == "Error")LogStage = 3;
	if (_logstage.child_value() == "Fatal")LogStage = 4;
	if (_logstage.child_value() == "None")LogStage = 5;
	else LogStage = 2;
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

void PreLoadLevel()
{
	xml_document doc;
	vector<string> a;
	doc.load_file("level.xml");
	xpath_query xQuery("/Levels/*");
	pugi::xpath_node_set xNodeSet = doc.select_nodes(xQuery);
	for (pugi::xpath_node_set::const_iterator it = xNodeSet.begin(); it != xNodeSet.end(); ++it)
	{
		pugi::xml_node nodeTmp = it->node();
		a.push_back(nodeTmp.name());
	}
	Level = new string[a.size() + 1];
	for (size_t i = 0; i < a.size(); i++)
	{
		Level[i] = a[i];
	}
}

void LoadLevel(const char* stage)
{
	xml_document doc;
	string str = "//";
	doc.load_file("level.xml");
	str += stage;
	xml_node Level = doc.select_node(str.c_str()).node();
	//主要执行部分

}

void LoadConfig()
{
	LoadEngineConfig();
	LoadGameConfig();
	PreLoadLevel();
}

#endif // !CONFIGURE
