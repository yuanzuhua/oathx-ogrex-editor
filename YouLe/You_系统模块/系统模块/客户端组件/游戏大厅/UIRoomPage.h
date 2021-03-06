#pragma once
#include "UIPngButton.h"

namespace YouLe
{
	/////////////////////////////////////////////////////////
	//房间构造
	////////////////////////////////////////////////////////
	class UIRoomItem : public UIWidget, public UIProcess
	{
	public:
		UIRoomItem(void);

		virtual ~UIRoomItem(void);

		// 创建控件
		virtual	BOOL		Create(INT nID, INT nDestX, INT nDestY, CWnd* pAttach, UIProcess* pProcess, UIWidget* pParent);
		// 绘制控件
		virtual BOOL		Draw(CDC* pDC);
	public:
		// 响应页控件
		virtual	BOOL		OnLeftDown(UIWidget* pWidget, const CPoint& cPt);
	
		// 功能函数
	public:
		//
		bool				OnClickedEnterRoom();

	protected:
		CPngImage			m_PngBill;
		UIPngButton*		m_pJoinBtn; 
		CFont				m_InfoFont;
		CFont				m_RuleFont;
	public:
		CListServer*		m_pListServer;
	};


	/////////////////////////////////////////////////////////
	//房间视图构造
	////////////////////////////////////////////////////////
	class UIRoomPage : public UIWidget, public UIProcess
	{
	public:
		UIRoomPage(void);

		virtual ~UIRoomPage(void);

		// 创建控件
		virtual	BOOL		Create(INT nID, const RECT& rect, CWnd* pAttach, 
			UIProcess* pProcess, UIWidget* pParent);
		
		// 绘制
		virtual BOOL		Draw(CDC* pDC);

	public:
		// 响应页控件
		virtual	BOOL		OnLeftDown(UIWidget* pWidget, const CPoint& cPt);

		// 功能函数
	public:
		// 显示房间列表
		bool				ShowRoomList(CListKind* ListKind);
		// 设置是否正在进入房间
		void				SetEnterRoom(bool bEnter){m_bEnterRoom = bEnter;}
	public:
		// 房间列表指针
		UIRoomItem*			m_pRoomItem[MAX_GICOL*MAX_GIROW];
		// 字体
		CFont				m_DrawFont;
		// 返回按钮
		UIPngButton*		m_pBtBack;
		// 标题
		CPngImage			m_TilteImage;
		// 标题名称（游戏名字）
		TCHAR				m_szKindName[KIND_LEN];
		// 设置进入房间标志
		bool				m_bEnterRoom;
	};


}