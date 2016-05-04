
#include "stdafx.h"
#include "../HTMl_Decode/HtmlDecode.h"
BOOST_AUTO_TEST_SUITE(HtmlDecodeSuite)

BOOST_AUTO_TEST_CASE(makes_empty_html_decode_string_from_empty_input_string)
{
	string text;
	std::string HtmlDecodeString;
	BOOST_CHECK(HtmlDecodeString == HtmlDecode(text));
}

BOOST_AUTO_TEST_CASE(return__html_decode_string_from_input_string)
{
	string inputString = "&amp;&lt;Hello&gt;&apos; &quot;";
	string htmlDecideString = "&<Hello>' \"";
	BOOST_CHECK(htmlDecideString == HtmlDecode(inputString));
}

BOOST_AUTO_TEST_SUITE_END()