// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Detours/Detours.h"
#include <iostream>

BOOL WINAPI DllMain(HANDLE hInstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
		
		FillHooks();
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)PaintAllStub, (LPVOID)PaintHook);
		DetourAttach(&(PVOID&)R_AddCmdDrawPhysical, (LPVOID)RAddCmdDrawHook);
		DetourTransactionCommit();

		break;
	
	}
	return TRUE;
}