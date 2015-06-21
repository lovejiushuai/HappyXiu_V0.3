// MainFrame.cpp : implementation file
//

#include "stdafx.h"
#include "Detail.h"
#include "MainFrame.h"


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

CMainFrame::CMainFrame()
{

	EnableAutomation();
}

CMainFrame::~CMainFrame()
{
}

void CMainFrame::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CFrameWnd::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_BN_RESTORE,OnRestore)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMainFrame, CFrameWnd)
END_DISPATCH_MAP()

// Note: we add support for IID_IMainFrame to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {BF9D1EE8-C74B-432F-A1EF-D02FBE6D60CE}
static const IID IID_IMainFrame =
{ 0xBF9D1EE8, 0xC74B, 0x432F, { 0xA1, 0xEF, 0xD0, 0x2F, 0xBE, 0x6D, 0x60, 0xCE } };

BEGIN_INTERFACE_MAP(CMainFrame, CFrameWnd)
	INTERFACE_PART(CMainFrame, IID_IMainFrame, Dispatch)
END_INTERFACE_MAP()


// CMainFrame message handlers


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	/////////////这一段代码创建树型控件////////////
	if (!m_wndTree.Create(WS_CHILD|WS_VISIBLE|
		TVS_HASLINES|TVS_HASBUTTONS|TVS_LINESATROOT,
		CRect(0, 0, 0, 0), m_pLeft, 100))  ///注意，这里是将m_pLeft作为m_wndTree的父窗口
	{
		TRACE0("Failed to create instant bar child\n");
		return -1;
	}
	m_wndTree.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	//添加树型控件图标
	CImageList* imageList=new CImageList;
	imageList->Create(16,16,ILC_COLOR24,4,4);
	imageList->Add(AfxGetApp()->LoadIcon(IDI_TREE_CLOSE));
	imageList->Add(AfxGetApp()->LoadIcon(IDI_TREE_ROOT));
	imageList->Add(AfxGetApp()->LoadIcon(IDI_TREE_CHILD));
	imageList->Add(AfxGetApp()->LoadIcon(IDI_TREE_OPEN));
	imageList->Add(AfxGetApp()->LoadIcon(IDI_TREE_CHILD2));

	m_wndTree.SetImageList(imageList,TVSIL_NORMAL);
	//往树型控件添加内容以及图标
	HTREEITEM hti = m_wndTree.InsertItem(_T("兰新高铁网管台帐"),1,1);
	HTREEITEM hti2=m_wndTree.InsertItem(_T("兰新高铁主用主系统"),0,3,hti);
	/*if(theApp.m_status!=_T("普通用户"))
	{
		m_wndTree.InsertItem(_T("模 块  I"),2,4,hti2);
	}*/
	m_wndTree.InsertItem(_T("模 块  I"),2,4,hti2);
	m_wndTree.InsertItem(_T("模 块  II"),2,4,hti2);	
	m_wndTree.InsertItem(_T("模 块  III"),2,4,hti2);

	HTREEITEM hti3=m_wndTree.InsertItem(_T("兰州西"),0,3,hti);
	/*if(theApp.m_status!=_T("普通用户"))
	{
		m_wndTree.InsertItem(_T(""),2,4,hti3);
	}*/
	m_wndTree.InsertItem(_T("模 块  I"),2,4,hti3);

	HTREEITEM hti4=m_wndTree.InsertItem(_T("兰西动车所"),0,3,hti);
	/*if(theApp.m_status!=_T("普通用户"))
	{
		m_wndTree.InsertItem(_T(""),2,4,hti4);
	}*/
	m_wndTree.InsertItem(_T("模 块  I"),2,4,hti4);
	
	HTREEITEM hti5=m_wndTree.InsertItem(_T("陈家湾"),0,3,hti);
	/*if(theApp.m_status!=_T("普通用户"))
	{
		m_wndTree.InsertItem(_T(""),2,4,hti5);
	}*/
	m_wndTree.InsertItem(_T("模 块  I"),2,4,hti5);
	
	HTREEITEM hti6=m_wndTree.InsertItem(_T("民和南"),0,3,hti);
	/*if(theApp.m_status!=_T("普通用户"))
	{
	m_wndTree.InsertItem(_T(""),2,4,hti6);
	}*/
	m_wndTree.InsertItem(_T("模 块  I"),2,4,hti6);	

	HTREEITEM hti7=m_wndTree.InsertItem(_T("兰新高铁备用主系统"),0,3,hti);	
	m_wndTree.InsertItem(_T("模 块  I"),2,4,hti7);
	m_wndTree.InsertItem(_T("模 块  II"),2,4,hti7);	
	m_wndTree.InsertItem(_T("模 块  III"),2,4,hti7);

	HTREEITEM hti8=m_wndTree.InsertItem(_T("其它信息"),0,3, hti);
	if(theApp.m_status!=_T("普通用户"))
	{
		m_wndTree.InsertItem(_T("其它信息管理"),2,4,hti8);
		HTREEITEM hti9=m_wndTree.InsertItem(_T("数据库管理"),0,3,hti8);
		m_wndTree.InsertItem(_T("数据备份"),2,4,hti9);
		m_wndTree.InsertItem(_T("数据还原"),2,4,hti9);
	}
	//展开树型控件的结点
	m_wndTree.Expand(hti,TVE_EXPAND);
	/*m_wndTree.Expand(hti2,TVE_EXPAND);
	m_wndTree.Expand(hti3,TVE_EXPAND);
	m_wndTree.Expand(hti4,TVE_EXPAND);
	m_wndTree.Expand(hti5,TVE_EXPAND);
	m_wndTree.Expand(hti6,TVE_EXPAND);
	m_wndTree.Expand(hti7,TVE_EXPAND);
	m_wndTree.Expand(hti8,TVE_EXPAND);*/

	///将树型控件加入到TabCtrl中
	m_pLeft->AddPage(&m_wndTree,_T("Dialog"),IDI_ICON10); //将树型控件添加到第一页
	
	m_pLeft->UpdateWindow(); //更新TabControl

	return 0;
}


BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle , CWnd* pParentWnd , CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext);
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	//Create splitter window by two views
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
		return -1;

	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CRightView), CSize(100, 100),pContext) ||
		!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CCoolTabCtrl), CSize(100, 100),pContext))
	{
		m_wndSplitter.DestroyWindow();
		return FALSE;
	}
	m_pRight = reinterpret_cast<CRightView*>(m_wndSplitter.GetPane(0,1));
	m_pLeft = reinterpret_cast<CCoolTabCtrl*>(m_wndSplitter.GetPane(0,0));
	m_wndSplitter.SetColumnInfo(0, 200, 100);	

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnRestore()
{
	//the filter

}