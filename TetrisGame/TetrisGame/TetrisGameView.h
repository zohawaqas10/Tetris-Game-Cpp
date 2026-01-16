
// TetrisGameView.h : interface of the CTetrisGameView class
//

#pragma once


class CTetrisGameView : public CView
{
protected: // create from serialization only
	CTetrisGameView() noexcept;
	DECLARE_DYNCREATE(CTetrisGameView)

// Attributes
public:
	CTetrisGameDoc* GetDocument() const;

// Operations
public:
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void CTetrisGameView::ResizeWindow();
protected:

// Implementation
public:
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	void DrawPiece(CDC* pDC);;
	virtual ~CTetrisGameView();

	void DrawBoard(CDC* pDC);

#endif

protected:
	

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnFinalRelease();
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in TetrisGameView.cpp
inline CTetrisGameDoc* CTetrisGameView::GetDocument() const
   { return reinterpret_cast<CTetrisGameDoc*>(m_pDocument); }
#endif

