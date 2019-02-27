#pragma once
#include "DataSpoof.h"
using namespace DataSpoof;

constexpr int FL_ONGROUND = (1 << 0);
const int JUMP = 5;
const int STAY = 4;

void JumpQueue()
{
	if (GetAsyncKeyState(VK_SPACE))
		(currentFlag & FL_ONGROUND) ? setJump(JUMP) : setJump(STAY);
}
