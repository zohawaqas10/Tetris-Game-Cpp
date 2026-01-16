
// TetrisGameDoc.h : interface of the CTetrisGameDoc class
//


#pragma once


#ifndef CTETRISGAMEDOC_H
#define CTETRISGAMEDOC_H

#include <afxwin.h>
#include "Game.h"
class CTetrisGameDoc : public CDocument
{
private:
	
protected: // create from serialization only
	CTetrisGameDoc() noexcept;
	DECLARE_DYNCREATE(CTetrisGameDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	Game game;
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTetrisGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

#endif // CTETRISGAMEDOC_H
