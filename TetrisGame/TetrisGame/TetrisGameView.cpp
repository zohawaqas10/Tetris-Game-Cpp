
// TetrisGameView.cpp : implementation of the CTetrisGameView class
//

#include "pch.h"
#include "framework.h"
#include "Game.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TetrisGame.h"
#endif

#include "TetrisGameDoc.h"
#include "TetrisGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTetrisGameView

IMPLEMENT_DYNCREATE(CTetrisGameView, CView)

BEGIN_MESSAGE_MAP(CTetrisGameView, CView)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CTetrisGameView construction/destruction

CTetrisGameView::CTetrisGameView() noexcept
{
	// TODO: add construction code here

}

CTetrisGameView::~CTetrisGameView()
{
}

BOOL CTetrisGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTetrisGameView drawing



void CTetrisGameView::DrawBoard(CDC* pDC) {
	CTetrisGameDoc* pDoc = GetDocument();
	for (int r = 0; r < pDoc->game.rows; ++r) {
		for (int c = 0; c < pDoc->game.cols; ++c) {
			COLORREF color = pDoc->game.getCellColor(c, r);
			CBrush brush(color);
			pDC->FillRect(CRect(c * BLOCK_WIDTH, r * BLOCK_HEIGHT, (c + 1) * BLOCK_WIDTH, (r + 1) * BLOCK_HEIGHT), &brush);
		}
	}
}


void CTetrisGameView::DrawPiece(CDC* pDC) {
	CTetrisGameDoc* pDoc = GetDocument();
	if (!pDoc || !pDoc->game.piecePtr) return;

	Game& game = pDoc->game;

	for (int i = 0; i < 4; ++i) {
		int x = game.currentCol + game.piecePtr->getFptr()->blockPts[i].x;
		int y = game.currentRow + game.piecePtr->getFptr()->blockPts[i].y;

		COLORREF color = game.piecePtr->getColor();
		CBrush brush(color);
		pDC->FillRect(CRect(x * BLOCK_WIDTH, y * BLOCK_HEIGHT, (x + 1) * BLOCK_WIDTH, (y + 1) * BLOCK_HEIGHT), &brush);
	}
}
void CTetrisGameView::OnDraw(CDC* pDC)
{
	CTetrisGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	DrawBoard(pDC); // Draw the game board
	DrawPiece(pDC); // Draw the current falling piece
	
}


// CTetrisGameView diagnostics

#ifdef _DEBUG
void CTetrisGameView::AssertValid() const
{
	CView::AssertValid();
}

void CTetrisGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTetrisGameDoc* CTetrisGameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisGameDoc)));
	return (CTetrisGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisGameView message handlers

void CTetrisGameView::OnFinalRelease() {
	// Call the base class implementation
	CView::OnFinalRelease();
}

void CTetrisGameView::ResizeWindow()
{
	CTetrisGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size based on the size of the game board
	rcWindow.right = rcWindow.left + (500) + nWidthDiff;
	rcWindow.bottom = rcWindow.top + (600) + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}


void CTetrisGameView::OnInitialUpdate()
{
	ResizeWindow();
	CView::OnInitialUpdate();

	SetTimer(1, 500, NULL);
	
}




void CTetrisGameView::OnTimer(UINT_PTR nIDEvent)
{
	CTetrisGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1) { // Timer for piece movement
	
			Game& game = pDoc->game;
	
			// Move the piece down
			game.currentRow++;
	
			// Check for collisions or bottom of the board
			for (int i = 0; i < 4; ++i) {
				int newRow = game.currentRow + game.piecePtr->getFptr()->blockPts[i].y;
				int newCol = game.currentCol + game.piecePtr->getFptr()->blockPts[i].x;
	
				if (newRow >= game.rows || game.board[newRow][newCol] != 0) {
					// Revert the move and fix the piece in place
					game.currentRow--;
					for (int j = 0; j < 4; ++j) {
						int row = game.currentRow + game.piecePtr->getFptr()->blockPts[j].y;
						int col = game.currentCol + game.piecePtr->getFptr()->blockPts[j].x;
						game.board[row][col] = game.piecePtr->getColorIndex();
					}
	
					// Clear completed rows and generate a new piece
					game.clearCompleteRows();
					game.selectNextPiece();
					break;
				}
			}
			Invalidate();
		}
	CView::OnTimer(nIDEvent);
}




void CTetrisGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default


	CTetrisGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;

	Game& game = pDoc->game;

	if (nChar == VK_SPACE) { // Check if the spacebar was pressed
		game.rotatePiece();  // Rotate the current piece
		Invalidate();        // Redraw the view to show the rotation
	}
	else if (nChar == VK_LEFT) {
		// Move the piece left
		game.movePieceLeft();
		Invalidate();
	}
	else if (nChar == VK_RIGHT) {
		// Move the piece right
		game.movePieceRight();
		Invalidate();
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
