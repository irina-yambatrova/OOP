
#include "stdafx.h"
#include "../HTMl_Decode/HtmlDecode.h"
BOOST_AUTO_TEST_SUITE(HtmlDecodeSuite)

BOOST_AUTO_TEST_CASE(makes_empty_string_from_empty_input_string)
{
	string text;
	std::string HtmlDecodeString;
	BOOST_CHECK(HtmlDecodeString == HtmlDecode(text));
}

BOOST_AUTO_TEST_CASE(return_html_decode_string_from_input_string)
{
	string inputString = "&amp;&lt;Hello&gt;&apos; &quot;";
	string htmlDecodeString = "&<Hello>' \"";
	BOOST_CHECK(htmlDecodeString == HtmlDecode(inputString));
}

BOOST_AUTO_TEST_SUITE_END()