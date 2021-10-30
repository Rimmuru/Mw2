#pragma once
typedef void(*CG_DrawRotatedPicPhysical_t)(DWORD ScreenPlacement, FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, FLOAT Angle, const float* Color, DWORD Material);
extern CG_DrawRotatedPicPhysical_t R_AddCmdDrawPhysical;
typedef void(*R_AddCmdDrawStretchPic_t)(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const float* color, int material);
extern R_AddCmdDrawStretchPic_t R_AddCmdDrawStretchPic;

void DrawingTest();

// byte[] nop = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };// 6 bytes
 
