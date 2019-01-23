 ///
 /// @file    Rsstest.cc
 /// @author  bigfei775655478@qq.com)
 /// @date    2019-01-22 19:04:35
 ///

#include "test.h"
#include "tinyxml2.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	RssReader reader;
	reader.parseRss("/home/dafei/Learngit/20190116/xml/feed.xbeta.info.xml");
	string file("pagelib3.txt");
	reader.dump(file);
	return 0;
}
