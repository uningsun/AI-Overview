
// ImageProcessing_yis_1View.cpp: CImageProcessingyis1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing_yis_1.h"
#endif

#include "ImageProcessing_yis_1Doc.h"
#include "ImageProcessing_yis_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessingyis1View

IMPLEMENT_DYNCREATE(CImageProcessingyis1View, CView)

BEGIN_MESSAGE_MAP(CImageProcessingyis1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessingyis1View::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CImageProcessingyis1View::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CImageProcessingyis1View::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessingyis1View::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessingyis1View::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessingyis1View::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessingyis1View::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessingyis1View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessingyis1View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessingyis1View::OnXorOperate)
//	ON_COMMAND(ID_NEGA_TRANSFROM, &CImageProcessingyis1View::OnNegaTransfrom)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessingyis1View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CImageProcessingyis1View::OnBinarization)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessingyis1View::OnNegaTransform)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CImageProcessingyis1View::OnStressTransform)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessingyis1View::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessingyis1View::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessingyis1View::OnHistoSpec)
	ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessingyis1View::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessingyis1View::OnEndInSearch)
	ON_COMMAND(ID_EMBOSSING, &CImageProcessingyis1View::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessingyis1View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessingyis1View::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CImageProcessingyis1View::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CImageProcessingyis1View::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CImageProcessingyis1View::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CImageProcessingyis1View::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CImageProcessingyis1View::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CImageProcessingyis1View::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CImageProcessingyis1View::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CImageProcessingyis1View::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CImageProcessingyis1View::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CImageProcessingyis1View::OnMeanSub)
	ON_COMMAND(ID_TRANSLATION, &CImageProcessingyis1View::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CImageProcessingyis1View::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CImageProcessingyis1View::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CImageProcessingyis1View::OnRotation)
	ON_COMMAND(ID_FRAME_SUM, &CImageProcessingyis1View::OnFrameSum)
	ON_COMMAND(ID_FRAME_SUB, &CImageProcessingyis1View::OnFrameSub)
	ON_COMMAND(ID_FRAME_MUL, &CImageProcessingyis1View::OnFrameMul)
	ON_COMMAND(ID_FRAME_DIV, &CImageProcessingyis1View::OnFrameDiv)
	ON_COMMAND(ID_FRAME_AND, &CImageProcessingyis1View::OnFrameAnd)
	ON_COMMAND(ID_FRAME_OR, &CImageProcessingyis1View::OnFrameOr)
	ON_COMMAND(ID_FRAME_COMB, &CImageProcessingyis1View::OnFrameComb)
//	ON_COMMAND(ID_BITPLAIN, &CImageProcessingyis1View::OnBitplain)
ON_COMMAND(ID_BITPLANE, &CImageProcessingyis1View::OnBitplane)
END_MESSAGE_MAP()

// CImageProcessingyis1View 생성/소멸

CImageProcessingyis1View::CImageProcessingyis1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessingyis1View::~CImageProcessingyis1View()
{
}

BOOL CImageProcessingyis1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessingyis1View 그리기

void CImageProcessingyis1View::OnDraw(CDC* pDC)
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i, j;
	unsigned char R, G, B;
	//입력영상 출력
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i*pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	//축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}


// CImageProcessingyis1View 인쇄

BOOL CImageProcessingyis1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessingyis1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessingyis1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageProcessingyis1View 진단

#ifdef _DEBUG
void CImageProcessingyis1View::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessingyis1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessingyis1Doc* CImageProcessingyis1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessingyis1Doc)));
	return (CImageProcessingyis1Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessingyis1View 메시지 처리기


void CImageProcessingyis1View::OnDownSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // doc클래스 ondownsampling 호출
	Invalidate(TRUE); //화면 갱신
}


void CImageProcessingyis1View::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument(); 
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); 

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization();

	Invalidate(TRUE); //화면 갱신
}


//void CImageProcessingyis1View::OnSumConstant()
//{
//	// TODO: 여기에 구현 코드 추가.
//	CImageProcessingyis1Doc* pDoc = GetDocument();
//
//	ASSERT_VALID(pDoc);
//
//	pDoc->OnSumConstant();
//
//	Invalidate(TRUE);
//}


void CImageProcessingyis1View::OnSumConstant()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	pDoc->OnSumConstant();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnSubConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnMulConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnDivConstant()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnAndOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnAndOperate();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnOrOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnOrOperate();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnXorOperate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnXorOperate();

	Invalidate(TRUE);
}


//void CImageProcessingyis1View::OnNegaTransfrom()
//{
//	CImageProcessingyis1Doc* pDoc = GetDocument();
//
//	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴
//
//	pDoc->OnNegaTransform();
//
//	Invalidate(TRUE);
//}


void CImageProcessingyis1View::OnGammaCorrection()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnBinarization()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnBinarization();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnNegaTransform()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnNegaTransform();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnStressTransform()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnStressTransform();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnHistogram()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnHistogram();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnHistoEqual()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc); //인스턴트 주소를 가져옴

	pDoc->OnHistoEqual();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoSpec();

	Invalidate(TRUE);

}


void CImageProcessingyis1View::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnEndInSearch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndInSearch();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnEmbossing()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossing();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnBlurr()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurr();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnGaussianFilter()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGaussianFilter();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnSharpening()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpening();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnHpfSharp()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfSharp();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnLpfSharp()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfSharp();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnDiffOperatorHor()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDiffOperatorHor();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnHomogenOperator()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHomogenOperator();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnLaplacian()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnNearest()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNearest();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnBilinear()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnMedianSub()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianSub();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnMeanSub()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanSub();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnTranslation()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnTranslation();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnMirrorHor()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorHor();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnMirrorVer()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorVer();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnRotation()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotation();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameSum()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameSum();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameSub()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameSub();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameMul()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameMul();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameDiv()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameDiv();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameAnd()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameAnd();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameOr()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameOr();

	Invalidate(TRUE);
}


void CImageProcessingyis1View::OnFrameComb()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameComb();

	Invalidate(TRUE);
}



void CImageProcessingyis1View::OnBitplane()
{
	CImageProcessingyis1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBitplane();

	Invalidate(TRUE);
}
