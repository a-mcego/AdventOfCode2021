#include "global.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "give day as param" << endl;
		return -1;
	}
	funcs[FromString<int>(argv[1])]();
}
