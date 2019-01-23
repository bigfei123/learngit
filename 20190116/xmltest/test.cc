///
/// @file    test.cc
/// @author  bigfei775655478@qq.com)
/// @date    2019-01-22 12:06:35
///
#include "tinyxml2.h" 
#include "test.h"
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using namespace tinyxml2;

//过滤HTML标记
string RegexString(const string &str){
		std::regex re("<(\\S*?)[^>]*>.*?|<.*?/>:|^\\s*|\\s*$|&nbsp|;");
		string pstr = str;
		pstr = std::regex_replace(pstr , re, string("")) ;
		return pstr;
}
RssReader::RssReader()
{	cout << " RssReader() " << endl;}

void RssReader::parseRss(const char *filename)
{
	RssItem  pItem ;
	XMLDocument doc;
	doc.LoadFile(filename);
	if(doc.ErrorID()) {
		cout << "Open file error ! " << endl;
	}
	XMLElement * itemNode = doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
	while(itemNode) {
		XMLElement * titleNode = itemNode -> FirstChildElement("title");
		XMLElement * linkNode= itemNode -> FirstChildElement("link");
		XMLElement * descriptionNode= itemNode -> FirstChildElement("description");
		XMLElement * contentNode= itemNode -> FirstChildElement("content:encoded");

		if(titleNode){
			pItem.title = RegexString(titleNode->GetText());
		}
		if(linkNode){
			pItem.link = RegexString(linkNode->GetText());
		}
		if(descriptionNode){
			pItem.description = RegexString(descriptionNode->GetText());
		}
		if(contentNode){
			pItem.content = RegexString(contentNode->GetText());
		}

		_rss.push_back(pItem);
		itemNode = itemNode->NextSiblingElement("item");
	}
}

void RssReader::dump(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs)
	{	cout << " open file error!" << endl;	}
	vector<RssItem>::iterator _begin = _rss.begin();
	vector<RssItem>::iterator _end = _rss.end();
	++_begin;	
	cout << "_rss.size() = " << _rss.size() << endl;
	//while(_begin != _end) {
	for( ; _begin != _end; ++_begin){
		ofs << "<doc>" << endl;
		ofs << "<title>" << '\t'<< _begin->title <<'\t' << "</title>" << endl;
		ofs << "<link>" << '\t' <<_begin->link<< '\t'<< "</link>" << endl;
		ofs << "<description>" << '\t'<<  _begin->description<<'\t'<< "</description>" << endl;
		ofs << "<content>" << '\t' <<_begin->content<< '\t' << "</content>" << endl;
		ofs << "/doc>" << endl;
		//++_begin;
	}
	ofs.close();
}


