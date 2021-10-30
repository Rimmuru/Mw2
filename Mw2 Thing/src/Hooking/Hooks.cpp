#include "../pch.h"

PaintAllStub_t PaintAllStub;
CG_DrawRotatedPicPhysical_t R_AddCmdDrawPhysical;
R_AddCmdDrawStretchPic_t R_AddCmdDrawStretchPic;

float Pink[] = { 1,0.7,1, 1 };

void RAddCmdDrawHook(DWORD ScreenPlacement, FLOAT x, FLOAT y, FLOAT w, FLOAT h, FLOAT Angle, const float* Color, DWORD Material)
{
	Color = Pink;
	std::cout << Material << std::endl;
	R_AddCmdDrawPhysical(ScreenPlacement, x, y, w, h, Angle, Color, Material);
}

void PaintHook(DWORD a)
{
	//std::cout << "Paint\n";
	DrawingTest();
	PaintAllStub(a);
}

void FillHooks()
{//ScreenPlacement 0x17807360
	PaintAllStub = PaintAllStub_t(0x005A8770);
	R_AddCmdDrawPhysical = CG_DrawRotatedPicPhysical_t(0x0048B580);
	R_AddCmdDrawStretchPic = R_AddCmdDrawStretchPic_t(0x00410E20);
}

