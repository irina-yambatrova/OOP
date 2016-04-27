// СountWordsTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CountWords/CountWords.h"

#include <string>
#include <map>

BOOST_AUTO_TEST_SUITE(CountOccurrenceOfWords_function)

	BOOST_AUTO_TEST_CASE(makes_empty_map_from_empty_input_string)
	{
		std::string inputText;
		std::map <std::string, size_t> expectedMap;
		BOOST_CHECK(expectedMap == CountOccurrenceOfWords(inputText));
	}
	BOOST_AUTO_TEST_CASE(should_return_occurrence_of_words_from__input_string)
	{
		std::map <std::string, size_t> expectedMap
		{
			{ "do", 1 },
			{ "english", 1 },
			{ "study", 1 },
			{ "you", 1 },
		};
		BOOST_CHECK(expectedMap == CountOccurrenceOfWords(std::string("Do you study English")));
	}
	BOOST_AUTO_TEST_CASE(returns_occurrence_of_words_from_input_string_with_one_word)
	{
		std::map <std::string, size_t> expectedMap
		{	
			{"do", 1}, 
			
		};
		BOOST_CHECK(expectedMap == CountOccurrenceOfWords(std::string("Do")));
	}
	BOOST_AUTO_TEST_CASE(returns_occurrence_of_words_from_input_string_excluding_delimiters)
	{
		std::map <std::string, size_t> expectedMap
		{
			{ "do", 1 },
			{ "english", 1 },
			{ "study", 1 },
			{ "you", 2 },
		};
		BOOST_CHECK (expectedMap == CountOccurrenceOfWords(std::string("Do? you.You study          () English?")));
	}
BOOST_AUTO_TEST_SUITE_END()

