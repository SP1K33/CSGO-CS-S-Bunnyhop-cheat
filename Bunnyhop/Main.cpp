#include <iostream>
#include <Windows.h>
#include "Memory.h"
#include "DataSpoof.h"
#include "Bunnyhop.h"

using std::cout;
using std::endl;
using std::boolalpha;
using namespace DataSpoof;

int main()
{
	cout << "Waiting for csgo.exe..." << endl;
	bool processExists = false;
	do 
	{
		processExists = Mem.FindProcess("csgo.exe");
		clientDll = Mem.ModulePointer("client_panorama.dll");
	} while (processExists == 0 && clientDll == 0);

	cout << "Done!" << endl;
	cout << "Press INSERT to switch hack" << endl;
	cout << "Press HOME exit hack" << endl;
	while (!GetAsyncKeyState(VK_HOME))
	{
		static bool state = true;
		if (GetAsyncKeyState(VK_INSERT))
		{
			state = !state;
			cout << "State: " << boolalpha << state << endl;
			Sleep(300);
		}
		if (state)
		{
			getPlayerBase();
			getFlag();
			JumpQueue();
		}
		Sleep(1);
	}
	return 0;
}
