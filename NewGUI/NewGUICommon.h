/*
  Copyright (c) 2003, Dominik Reichl <dominik.reichl@t-online.de>
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer. 
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  - Neither the name of ReichlSoft nor the names of its contributors may be
    used to endorse or promote products derived from this software without
    specific prior written permission.
 
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ___NEW_GUI_COMMON___
#define ___NEW_GUI_COMMON___

// StdAfx defines CR_BACK and CR_FRONT
#include "../StdAfx.h"

// The following is defined in StdAfx.h already
// #define CR_BACK RGB(...)
// #define CR_FRONT RGB(...)

#ifndef LVS_EX_GRIDLINES
	#define LVS_EX_GRIDLINES        0x00000001
	#define LVS_EX_SUBITEMIMAGES    0x00000002
	#define LVS_EX_CHECKBOXES       0x00000004
	#define LVS_EX_TRACKSELECT      0x00000008
	#define LVS_EX_HEADERDRAGDROP   0x00000010
	#define LVS_EX_FULLROWSELECT    0x00000020
	#define LVS_EX_ONECLICKACTIVATE 0x00000040
	#define LVS_EX_TWOCLICKACTIVATE 0x00000080
#endif

#ifndef LVS_EX_FLATSB
	#define LVS_EX_FLATSB           0x00000100
	#define LVS_EX_REGIONAL         0x00000200
	#define LVS_EX_INFOTIP          0x00000400
	#define LVS_EX_UNDERLINEHOT     0x00000800
	#define LVS_EX_UNDERLINECOLD    0x00001000
	#define LVS_EX_MULTIWORKAREAS   0x00002000
#endif

#define LVS_EX_SI_MENU (/*LVS_EX_FLATSB|*/LVS_EX_ONECLICKACTIVATE|LVS_EX_UNDERLINEHOT)
#define LVS_EX_SI_REPORT (/*(LVS_EX_FLATSB)*/ 0)

#ifndef CDRF_NOTIFYSUBITEMDRAW
#define CDRF_NOTIFYSUBITEMDRAW 0x00000020
#define CDDS_SUBITEM           0x00020000
#endif

typedef struct tagNMLVCUSTOMDRAWX
{
    NMCUSTOMDRAW nmcd;
    COLORREF clrText;
    COLORREF clrTextBk;
    int iSubItem;
} NMLVCUSTOMDRAWX, *LPNMLVCUSTOMDRAWX;

#ifndef COLOR16
typedef USHORT COLOR16;
#endif

#ifndef TRIVERTEX
typedef struct _TRIVERTEX
{
    LONG    x;
    LONG    y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
}TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;
#endif

#ifndef GRADIENT_RECT
typedef struct _GRADIENT_TRIANGLE
{
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
} GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

typedef struct _GRADIENT_RECT
{
    ULONG UpperLeft;
    ULONG LowerRight;
}GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;
#endif

#ifndef GRADIENT_FILL_RECT_H
#define GRADIENT_FILL_RECT_H    0x00000000
#define GRADIENT_FILL_RECT_V    0x00000001
#define GRADIENT_FILL_TRIANGLE  0x00000002
#define GRADIENT_FILL_OP_FLAG   0x000000ff
#endif

// No balloon support
#ifndef TTS_BALLOON
#define TTS_BALLOON 0
#endif

#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(p) ((void)0)
#endif

COLORREF NewGUI_GetBgColor();
COLORREF NewGUI_GetBtnColor();

void NewGUI_SetImgButtons(BOOL bImageButtons);
void NewGUI_Button(void *pButton, int nBitmapIn = -1, int nBitmapOut = -1);

void NewGUI_TranslateCWnd(CWnd *pWnd);

BOOL CALLBACK NewGUI_TranslateWindowCb(HWND hwnd, LPARAM lParam);

#endif // ___NEW_GUI_COMMON___