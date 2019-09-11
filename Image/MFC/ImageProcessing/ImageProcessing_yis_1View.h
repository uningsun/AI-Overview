
// ImageProcessing_yis_1View.h: CImageProcessingyis1View 클래스의 인터페이스
//

#pragma once


class CImageProcessingyis1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CImageProcessingyis1View() noexcept;
	DECLARE_DYNCREATE(CImageProcessingyis1View)

// 특성입니다.
public:
	CImageProcessingyis1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageProcessingyis1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
	afx_msg void OnQuantization();
//	void OnSumConstant();
	afx_msg void OnSumConstant();
	afx_msg void OnSubConstant();
	afx_msg void OnMulConstant();
	afx_msg void OnDivConstant();
	afx_msg void OnAndOperate();
	afx_msg void OnOrOperate();
	afx_msg void OnXorOperate();
//	afx_msg void OnNegaTransfrom();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnNegaTransform();
	afx_msg void OnStressTransform();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
	afx_msg void OnHistoStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnEmbossing();
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
	afx_msg void OnSharpening();
	afx_msg void OnHpfSharp();
	afx_msg void OnLpfSharp();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	afx_msg void OnLaplacian();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMedianSub();
	afx_msg void OnMeanSub();
	afx_msg void OnTranslation();
	afx_msg void OnMirrorHor();
	afx_msg void OnMirrorVer();
	afx_msg void OnRotation();
	afx_msg void OnFrameSum();
	afx_msg void OnFrameSub();
	afx_msg void OnFrameMul();
	afx_msg void OnFrameDiv();
	afx_msg void OnFrameAnd();
	afx_msg void OnFrameOr();
	afx_msg void OnFrameComb();
//	afx_msg void OnBitplain();
	afx_msg void OnBitplane();
};

#ifndef _DEBUG  // ImageProcessing_yis_1View.cpp의 디버그 버전
inline CImageProcessingyis1Doc* CImageProcessingyis1View::GetDocument() const
   { return reinterpret_cast<CImageProcessingyis1Doc*>(m_pDocument); }
#endif

