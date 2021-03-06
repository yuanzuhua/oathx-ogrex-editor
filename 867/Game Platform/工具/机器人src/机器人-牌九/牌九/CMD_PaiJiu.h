#ifndef CMD_BACCARAT_HEAD_FILE
#define CMD_BACCARAT_HEAD_FILE

//////////////////////////////////////////////////////////////////////////
//公共宏定义

#define KIND_ID						PAIJIU_KIND_ID						//游戏 I D
#define GAME_PLAYER					100									//游戏人数
#define GAME_NAME					TEXT("牌九")						//游戏名字
#define GAME_GENRE					(GAME_GENRE_GOLD|GAME_GENRE_MATCH)	//游戏类型

#define BANK_CONDITION_MONEY		1000

//玩家索引

#define ID_SHUN_MEN					0x01	
#define ID_TIAN_MEN					0x02
#define ID_DAO_MEN					0x04
#define ID_ZUO_JIAO					0x08
#define ID_YOU_JIAO					0x10
#define ID_QIAO						0x20
#define ID_QUAN_SHU					0x40									//全输

//记录信息
struct tagServerGameRecord
{
	WORD							wWinner;							//胜利玩家
	__int64							lTieScore;							//买平总注
	__int64							lBankerScore;						//买庄总注
	__int64							lPlayerScore;						//买闲总注
	BYTE							cbPlayerCount;						//闲家点数
	BYTE							cbBankerCount;						//庄家点数
};

//////////////////////////////////////////////////////////////////////////
//服务器命令结构

#define SUB_S_GAME_START			100									//游戏开始
#define SUB_S_PLACE_JETTON			101									//用户下注
#define SUB_S_GAME_END				102									//游戏结束
#define SUB_S_APPLY_BANKER			103									//申请庄家
#define SUB_S_CHANGE_BANKER			104									//切换庄家
#define SUB_S_CHANGE_USER_SCORE		105									//更新积分
#define SUB_S_SEND_RECORD			106									//游戏记录
#define SUB_S_PLACE_JETTON_FAIL		107									//下注失败
#define SUB_S_GAME_SCORE			108									//发送积分

//失败结构
struct CMD_S_PlaceJettonFail
{
	__int64							lJettonArea;						//下注区域
	__int64							lPlaceScore;						//当前下注
	__int64							lMaxLimitScore;						//限制大小
	__int64							lFinishPlaceScore;					//已下注额
};

//更新积分
struct CMD_S_ChangeUserScore
{
	WORD							wChairID;							//椅子号码
	__int64							lScore;								//玩家积分

	//庄家信息
	WORD							wCurrentBankerChairID;				//当前庄家
	BYTE							cbBankerTime;						//庄家局数
	__int64							lCurrentBankerScore;				//庄家分数
};

//申请庄家
struct CMD_S_ApplyBanker
{
	CHAR							szAccount[ 32 ];					//申请玩家
	__int64							lScore;								//玩家金币
	bool							bApplyBanker;						//申请标识
};

//切换庄家
struct CMD_S_ChangeBanker
{
	WORD							wChairID;							//椅子号码
	BYTE							cbBankerTime;						//庄家局数
	__int64							lBankerScore;						//庄家分数
	__int64							lBankerTreasure;					//庄家金币
};

//游戏状态
struct CMD_S_StatusFree
{
	//全局信息
	BYTE							cbTimeLeave;						//剩余时间
	__int64							lCellScore;							//最大单元下注

	//下注信息
	__int64							lTieScore;							//买平总注
	__int64							lBankerScore;						//买庄总注
	__int64							lPlayerScore;						//买闲总注
	__int64							lTieSamePointScore;					//同点平注
	__int64							lPlayerKingScore;					//闲天王注
	__int64							lBankerKingScore;					//庄天王注

	//我的下注
	__int64							lMeMaxScore;						//最大下注
	__int64							lMeTieScore;						//买平总注
	__int64							lMeBankerScore;						//买庄总注
	__int64							lMePlayerScore;						//买闲总注
	__int64							lMeTieKingScore;					//同点平注
	__int64							lMePlayerKingScore;					//闲天王注
	__int64							lMeBankerKingScore;					//庄天王注

	//庄家信息
	WORD							wCurrentBankerChairID;				//当前庄家
	BYTE							cbBankerTime;						//庄家局数
	__int64							lCurrentBankerScore;				//庄家分数
	__int64							lApplyBankerCondition;				//申请条件
	__int64							lBankerTreasure;					//庄家金币
};

//游戏状态
struct CMD_S_StatusPlay
{
	BYTE							cbTimeLeave;						//剩余时间
	__int64							lCellScore;							//最大单元下注
	//下注信息
	__int64							lTieScore;							//买平总注
	__int64							lBankerScore;						//买庄总注
	__int64							lPlayerScore;						//买闲总注
	__int64							lTieSamePointScore;					//同点平注
	__int64							lPlayerKingScore;					//闲天王注
	__int64							lBankerKingScore;					//庄天王注

	//我的下注
	__int64							lMeMaxScore;						//最大下注
	__int64							lMeTieScore;						//买平总注
	__int64							lMeBankerScore;						//买庄总注
	__int64							lMePlayerScore;						//买闲总注
	__int64							lMeTieKingScore;					//同点平注
	__int64							lMePlayerKingScore;					//闲天王注
	__int64							lMeBankerKingScore;					//庄天王注

	//扑克信息
 	BYTE							cbCardCount[2];						//扑克数目
	BYTE							cbTableCardArray[5][2];				//桌面扑克

	//庄家信息
	WORD							wCurrentBankerChairID;				//当前庄家
	BYTE							cbBankerTime;						//庄家局数
	__int64							lCurrentBankerScore;				//庄家分数
	__int64							lApplyBankerCondition;				//申请条件
	__int64							lBankerTreasure;					//庄家金币
};

//游戏开始
struct CMD_S_GameStart
{
	BYTE							cbCardCount[2];						//扑克数目
	BYTE							cbTableCardArray[5][2];				//桌面扑克
	__int64							lApplyBankerCondition;				//申请条件

	//庄家信息
	WORD							wBankerChairID;						//庄家号码
	__int64							lBankerScore;						//庄家积分
	BYTE							cbBankerTime;						//做庄次数
	BYTE							cbTimeLeave;						//剩余时间
};

//用户下注
struct CMD_S_PlaceJetton
{
	WORD							wChairID;							//用户位置
	BYTE							cbJettonArea;						//筹码区域
	__int64							lJettonScore;						//加注数目
};

//游戏结束
struct CMD_S_GameEnd
{
	//下局信息
	__int64							lMeMaxScore;						//最大下注
	BYTE							cbTimeLeave;						//剩余时间
	__int64							lCellScore;							//最大下注

	//成绩记录
	BYTE							cbWinner;							//胜利玩家
	BYTE							cbKingWinner;						//天王胜利
	__int64							lBankerTreasure;					//庄家金币

	__int64							lBankerTotalScore;					//庄家成绩
	__int64							lBankerScore;						//庄家成绩
	INT								nBankerTime;						//做庄次数
};

//游戏得分
struct CMD_S_GameScore
{
	//成绩记录
	BYTE							cbWinner;							//胜利玩家
	BYTE							cbKingWinner;						//天王胜利
	__int64							lMeGameScore;						//我的成绩
	__int64							lMeReturnScore;						//返还注额
	__int64							lBankerScore;						//庄家成绩

	//下注信息
	__int64							lDrawTieScore;						//买平总注
	__int64							lDrawBankerScore;					//买庄总注
	__int64							lDrawPlayerScore;					//买闲总注
	__int64							lDrawTieSamPointScore;				//同点平注
	__int64							lDrawPlayerKingScore;				//闲天王注
	__int64							lDrawBankerKingScore;				//庄天王注

	//我的下注
	__int64							lMeTieScore;						//买平总注
	__int64							lMeBankerScore;						//买庄总注
	__int64							lMePlayerScore;						//买闲总注
	__int64							lMeTieKingScore;					//同点平注
	__int64							lMePlayerKingScore;					//闲天王注
	__int64							lMeBankerKingScore;					//庄天王注
};

//////////////////////////////////////////////////////////////////////////
//客户端命令结构

#define SUB_C_PLACE_JETTON			1									//用户下注
#define SUB_C_APPLY_BANKER			2									//申请庄家

//用户下注
struct CMD_C_PlaceJetton
{
	BYTE							cbJettonArea;						//筹码区域
	__int64							lJettonScore;						//加注数目
};

//申请庄家
struct CMD_C_ApplyBanker
{
	bool							bApplyBanker;						//申请标识
};

//////////////////////////////////////////////////////////////////////////

#endif