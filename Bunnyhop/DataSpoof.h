#pragma once
namespace DataSpoof 
{
	Memory Mem;
	/// Offsets
	const DWORD pLocalPlayer = 0xCCA6B4;
	const DWORD pJump = 0x517E234;
	const DWORD pFlag = 0x104;
	const DWORD pVelocity = 0x114;
	/// ������������ � ������� ������� ��� �������� �������

	DWORD clientDll;

	DWORD playerBase;
	int currentFlag;

	void getPlayerBase()
	{
		playerBase = Mem.Read<DWORD>(clientDll + pLocalPlayer);
	}

	void getFlag()
	{
		currentFlag = Mem.Read<int>(playerBase + pFlag);
	}

	void setJump(int value)
	{
		Mem.Write<int>(clientDll + pJump, value);
	}
}