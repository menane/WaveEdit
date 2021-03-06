
// WaveEditView.h : interface of the CWaveEditView class
//

#pragma once


class CWaveEditView : public CScrollView
{
	int selectionStart, selectionEnd;
	bool mousePressed;//boolean to keep track of if the mouse is pressed
	int startSelection;//denotes the start of a selection
	int endSelection;//denotes the end of a selection
	int zinflag; //flag to check if the user selects the 'Zoom In' button
	int zoutflag; //flag to check if the user selects the 'Zoom Out' button

protected: // create from serialization only
	CWaveEditView();
	DECLARE_DYNCREATE(CWaveEditView)
	WaveFile * clipboard; //global var to store selection from cut, copy and paste

// Attributes
public:
	CWaveEditDoc* GetDocument() const;
	

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CWaveEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnToolsZoomin();
	afx_msg void OnToolsZoomout();
};

#ifndef _DEBUG  // debug version in WaveEditView.cpp
inline CWaveEditDoc* CWaveEditView::GetDocument() const
   { return reinterpret_cast<CWaveEditDoc*>(m_pDocument); }
#endif

