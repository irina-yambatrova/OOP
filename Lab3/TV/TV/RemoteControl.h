#pragma once
#include <boost/noncopyable.hpp>
#include <map>
#include <functional>


class CTVSet;

class CRemoteControl : boost::noncopyable
{
public:
	CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommand();

private:
	bool TurnOn(std::istream & args);
	bool TurnOff(std::istream & args);
	bool SelectedChannel(std::istream & strm);
	bool GetInfo(std::istream & args);
	bool SelectedPreviousChannel(std::istream & strm);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};