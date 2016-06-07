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
	void TurnOn(std::istream & args);
	void TurnOff(std::istream & args);
	void SelectedChannel(std::istream & strm);
	void Info(std::istream & args);
	void SelectPreviousChannel(std::istream & strm);
private:
	typedef std::map<std::string, std::function<void(std::istream & args)>> ActionMap;

	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};