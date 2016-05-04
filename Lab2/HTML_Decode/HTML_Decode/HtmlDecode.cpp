#include "stdafx.h"
#include <iostream>
#include <boost/algorithm/string/replace.hpp>
#include <string>
#include "HtmlDecode.h"

using namespace std;

std::string ReadInputData()
{
	string text;
	cout << "Введите строку, по окончании введите end  " << endl;
	getline(cin, text);
	return text;
}

std::string HtmlDecode(std::string const& html)
{
	string htmlDecodeText = html;
	if (html.length() != 0)
	{
		boost::replace_all(htmlDecodeText, "&quot;", "\"");
		boost::replace_all(htmlDecodeText, "&apos;", "'");
		boost::replace_all(htmlDecodeText, "&lt;", "<");
		boost::replace_all(htmlDecodeText, "&gt;", ">");
		boost::replace_all(htmlDecodeText, "&amp;", "&");
	}
	return  htmlDecodeText;
}

void PrintOuputText(string const&  htmlDecodeText)
{
	cout <<"Декодированный html-текст " << htmlDecodeText <<endl;
}

