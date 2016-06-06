#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"
#include <sstream>
#include <functional>
#include <string>
#include <iostream>

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnOn", bind(&CRemoteControl::TurnOn, this, _1) },
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) },
		{ "SelectChannel", bind(&CRemoteControl::SelectedChannel, this, _1) },
		{ "GetInfo", bind(&CRemoteControl::GetInfo, this, _1) },
		{ "SelectPreviousChannel", bind(&CRemoteControl::SelectedPreviousChannel, this, _1) }
		
})
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it-> second(strm);
		return true;
	}
	return false;
}

void CRemoteControl::TurnOn(std::istream & args)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
}

void CRemoteControl::TurnOff(std::istream & args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
}

void CRemoteControl::SelectedChannel(std::istream & strm)
{
	int channel;
	strm >> channel;
	if (!m_tv.SelectChannel(channel))
	{
		m_output << "can't select channel" << endl;
	}
}

void CRemoteControl::GetInfo(std::istream & args)
{
	int channel = m_tv.GetChannel();
	if (channel == 0)
	{
		m_output << "TV is OFF" << endl;
	}
	else
	{
		m_output << channel << endl;
	}
}

void CRemoteControl::SelectedPreviousChannel(std::istream & strm)
{
	if (!m_tv.SelectPreviousChannel())
	{
		m_output << "can't select previous channel" << endl;
	}
}
