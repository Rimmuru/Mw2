#pragma once
typedef void(*PaintAllStub_t)(DWORD a);
extern PaintAllStub_t PaintAllStub;

void RAddCmdDrawHook(DWORD ScreenPlacement, FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, FLOAT Angle,const float* Color, DWORD Material);
void PaintHook(DWORD a);
void FillHooks();

