#ifndef _____UIFrameSheet_H
#define _____UIFrameSheet_H

#include "UISheet.h"


namespace YouLe
{
	// UI 根窗口
	class UIFrameSheet : public UISheet, public UIProcess
	{
	public:
		// 构造函数
		UIFrameSheet();
		// 析构函数
		virtual ~UIFrameSheet();

		// 创建窗口
		virtual BOOL			Create(INT nID, const RECT& rect, CWnd* pAttach, UIProcess* pProcess, UIWidget* pParent);
		
		// 框架绘制
		virtual BOOL			Draw(CDC* pDC);
		
	public:
		// 按钮按下
		virtual	BOOL			OnClicked(UIWidget* pWidget,
			const CPoint& cPt);

	public:
		// 处理指令
		void					ProcessCommand(int nCommand);
	protected:
		CPngImage				m_PngFrameImage[4];
	};
}

#endif