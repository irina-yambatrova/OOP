
#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"
#include <iostream>

using namespace std;

void main()
{
	CTVSet tv;
	CRemoteControl remoteControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "Enter command-> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
}

