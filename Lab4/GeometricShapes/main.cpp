#include "stdafx.h"
#include "OperationsWithShapes.h"

using namespace std;

int main()
{
	vector<shared_ptr<IShape>> shapes;
	cout << "input name of shapes and properties, at the end, enter \"info\"!" << endl;

	COperationsWithShapes handle(cin, cout, shapes);
	while (!cin.eof() && !cin.fail())
	{
		cout << "-> ";
		if (!handle.HandleCommand())
		{
			cout << "Unknown shape!" << endl;
		}
	}
	return 0;
}

