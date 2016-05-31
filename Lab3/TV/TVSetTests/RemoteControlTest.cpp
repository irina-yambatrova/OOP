#include "stdafx.h"
#include "../TV/RemoteControl.h"
#include "../TV/TVSet.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

// Зависимости RemoteControl-а вынесены в родительскую структуру,
// чтобы гарантировать их создание до конструирования самого remote-контрола
struct RemoteControlDependencies
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
};

struct RemoteControlFixture : RemoteControlDependencies
{
	CRemoteControl remoteControl;

	RemoteControlFixture(): remoteControl(tv, input, output)
	{
	}

	void VerifyCommandHandling(const string& command, const optional<int> & expectedChannel, const string& expectedOutput)
	{
		input << command;
		BOOST_CHECK(remoteControl.HandleCommand());
		BOOST_CHECK_EQUAL(tv.IsTurnedOn(), expectedChannel.is_initialized());
		BOOST_CHECK_EQUAL(tv.GetChannel(), expectedChannel.get_value_or(0));
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Remote_Control, RemoteControlFixture)

	BOOST_AUTO_TEST_CASE(can_handle_TurnOn_command)
	{
		VerifyCommandHandling("TurnOn", 1, "TV is turned on\n");
	}
	BOOST_AUTO_TEST_CASE(can_turn_off_tv_which_is_on)
	{
		tv.TurnOn();
		VerifyCommandHandling("TurnOff", none, "TV is turned off\n");
	}
	BOOST_AUTO_TEST_CASE(can_select_channel_when_tv_is_on)
	{
		tv.TurnOn();
		VerifyCommandHandling("SelectChannel 12", 12, "");
	}
	BOOST_AUTO_TEST_CASE(can_not_select_channel_when_tv_is_off)
	{
		VerifyCommandHandling("SelectChannel 10", none, "");
	}
	BOOST_AUTO_TEST_CASE(can_not_select_previous_channel_when_tv_is_off)
	{
		VerifyCommandHandling("SelectPreviousChannel", none, "");
	}
BOOST_AUTO_TEST_SUITE_END()

struct _after_turn_on_and_select_some_channel : RemoteControlFixture
{
	_after_turn_on_and_select_some_channel()
	{
		tv.TurnOn();
		tv.SelectChannel(12);
	}
};
BOOST_FIXTURE_TEST_SUITE(after_turn_on_and_select_some_channel, _after_turn_on_and_select_some_channel)
	BOOST_AUTO_TEST_CASE(can_select_previous_channel_when_tv_is_on)
	{
		VerifyCommandHandling("SelectPreviousChannel", 1, "");
	}
BOOST_AUTO_TEST_SUITE_END()