#pragma once
#include <string>
#include <vector>
#include <DxLib.h>

enum MainGraphName
{
	LoadPage,		//	ロード画面
	TitlePage,		// タイトル画面
	GameBack_1,		// ゲーム背景
	GameBack_2,		// ゲーム背景2
	Wall_1,			// 壁1(横)
	Wall_2,			// 壁2(縦)
	NextKey,		// 鍵
	Knife,			// ナイフ
	Cross,			// 十字架
	LifeGauge,		// 体力ゲージ
	WordFrame_1,	// 文字枠1(Light)
	WordFrame_2,	// 文字枠2(Knife)
	WordFrame_3,	// 文字枠3(Key)
	WordFrame_4,	// 文字枠4(Cross)
	ItemFrame,		// 所持枠
	mnmall_num			// 総数
};

// プレイヤー
enum PlayerGraph
{
	pgmRight,	// 右
	pgmLeft,	// 左
	pgmBack,	// 背中
	pgmAtack,	// 攻撃
	pgmWin,	// 勝利
	pgmDeath,	// 倒れる
	pgmall_num	// 総数
};

// 敵
enum EnemyGraph
{
	egmRight,	// 右
	egmLeft,		// 左
	egmAtack,	// 攻撃
	egmDeath,	// 倒れる
	egmall_num	// 総数
};

// すべて使わないけど一応
enum WordGraph
{
	A,B,C,D,E,
	F,G,H,I,J,
	K,L,M,N,O,
	P,Q,R,S,T,
	U,V,W,X,Y,
	Z,wgmall_num
};

// 画像クラス
class Graphics
{
public:
	Graphics();
	Graphics(std::string path);
	~Graphics();
	
	// 読み込み処理
	static void LoadMainGraphics();
	static void LoadPlayerGraphics();
	static void LoadEnemyGraphics();
	static void LoadWordGraphics();
	
	// 画像取得
	static int GetMainGraph(int _num);
	static int GetPlayerGraph(int _num, int _anime);
	static int GetEnemyGraph(int _num, int _anime);
	static int GetWordGraph(int _num);

	// サイズ取得
	static int GetPGS(int _num);
	static int GetEGS(int _num);

	static bool loadFlag[4];						// 読み込み用フラグ

private:
	static std::vector<int>gr;						// メインでいろいろ使う画像ハンドル
	static std::vector<std::vector<int>>chara_gr;	// プレイヤー用画像ハンドル(行動6種類)
	static std::vector<std::vector<int>>enemy_gr;	// 敵用画像ハンドル(行動4種類)
	static std::vector<int>word_gr;					// 文字用画像ハンドル(26種類)
};