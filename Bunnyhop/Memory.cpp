#include "Memory.h"

bool Memory::FindProcess(const char* name)
{
	PROCESSENTRY32 ProcessEntry;
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE processHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (processHandle == INVALID_HANDLE_VALUE)
		return false;

	do {
		if (!strcmp(ProcessEntry.szExeFile, name)) {
			ProcessID = ProcessEntry.th32ProcessID;
			CloseHandle(processHandle);
			HandleProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_READ | PROCESS_VM_OPERATION, false, ProcessID);
			return true;
		}
	} while (Process32Next(processHandle, &ProcessEntry));

	CloseHandle(processHandle);
	return false; ///
}

DWORD Memory::ModulePointer(const char* name)
{
	HANDLE moduleHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);

	if (moduleHandle == 0)
		return 0;

	MODULEENTRY32 ModuleEntry;
	ModuleEntry.dwSize = sizeof(ModuleEntry);

	while (Module32Next(moduleHandle, &ModuleEntry)) {
		if (!strcmp(ModuleEntry.szModule, name)) {
			CloseHandle(moduleHandle);
			return (DWORD)ModuleEntry.modBaseAddr;
		}
	}
	CloseHandle(moduleHandle);
	return 0;
}

extern Memory Mem;