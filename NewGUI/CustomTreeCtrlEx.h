/*
  Copyright (c) 2003/2004, Dominik Reichl <dominik.reichl@t-online.de>
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

#ifndef AFX_CUSTOMTREECTRLEX_H__EE7BE580_7102_11D8_BF16_0050BF14F5CC__INCLUDED_
#define AFX_CUSTOMTREECTRLEX_H__EE7BE580_7102_11D8_BF16_0050BF14F5CC__INCLUDED_

/////////////////////////////////////////////////////////////////////////////

class CCustomOleDropHandler : public COleDropTarget
{
public:
	DROPEFFECT OnDragEnter(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	DROPEFFECT OnDragOver(CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	void OnDragLeave(CWnd* pWnd);
	BOOL OnDrop(CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);

	void SetDragAccept(BOOL bAccept);
	void _RemoveDropSelection();

	CWnd *m_pTopParentI;
	CTreeCtrl *m_pParentTree;

private:
	BOOL m_bAcceptDrop;
};

/////////////////////////////////////////////////////////////////////////////

class CCustomTreeCtrlEx : public CTreeCtrl
{
public:
	CCustomTreeCtrlEx();
	virtual ~CCustomTreeCtrlEx();

	BOOL InitDropHandler();

	CWnd *m_pParentI;
	CCustomOleDropHandler m_drop;

	//{{AFX_VIRTUAL(CCustomTreeCtrlEx)
	//}}AFX_VIRTUAL

private:
	BOOL m_bValidDropTarget;

protected:
	//{{AFX_MSG(CCustomTreeCtrlEx)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // AFX_CUSTOMTREECTRLEX_H__EE7BE580_7102_11D8_BF16_0050BF14F5CC__INCLUDED_
