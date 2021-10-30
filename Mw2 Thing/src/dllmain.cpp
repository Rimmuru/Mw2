// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>

BOOL WINAPI DllMain(HANDLE hInstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		ImGui_ImplWin32_Init(hInstDLL);
		IDirect3DDevice9* device;
		ImGui_ImplDX9_Init(device);
		ImGui::StyleColorsDark();

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