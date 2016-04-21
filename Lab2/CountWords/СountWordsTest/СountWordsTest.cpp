// СountWordsTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CountWords/CountWords.h"

#include <string>
#include <map>

BOOST_AUTO_TEST_SUITE(CountOccurrenceOfWords_function)

BOOST_AUTO_TEST_CASE(should_return_empty_string_from_empty_input_string)
{
	std::string inputString;
	std::map <std::string, size_t> expectedMap;
	BOOST_CHECK(expectedMap == CountOccurrenceOfWords(inputString));
}
BOOST_AUTO_TEST_CASE(should_return_occurrence_of_words_from__input_string)
{
	std::string inputString;
	inputString = "Are you study English?";
	std::map <std::string, size_t> expectedMap
	{	
		{"Are", 1}, 
		{ "English", 1 },
		{ "study", 1 },
		{ "you", 1 },
	};
	BOOST_CHECK(expectedMap == CountOccurrenceOfWords(inputString));
}
BOOST_AUTO_TEST_CASE(should_return_occurrence_of_words_from__input_string_with_delimiter)
{
	std::string inputString;
	inputString = "Are? you. study          () English?";
	std::map <std::string, size_t> expectedMap
	{
		{ "Are", 1 },
		{ "English", 1 },
		{ "study", 1 },
		{ "you", 1 },
	};
	BOOST_CHECK(expectedMap == CountOccurrenceOfWords(inputString));
}
BOOST_AUTO_TEST_SUITE_END()

