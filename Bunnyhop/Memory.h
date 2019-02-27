#pragma once
#include <Windows.h>
#include <TlHelp32.h>

class Memory
{
private:
	HANDLE HandleProcess;
	DWORD ProcessID;
public:
	bool FindProcess(const char*);
	DWORD ModulePointer(const char*);

	template <class T>
	T Read(DWORD address)
	{
		T out;
		ReadProcessMemory(HandleProcess, (LPVOID)address, &out, sizeof(T), 0);
		return out;
	}

	template <class T>
	void Write(DWORD address, T v)
	{
		WriteProcessMemory(HandleProcess, (LPVOID)address, &v, sizeof(T), 0);
	}
};
