#pragma once
#include <string>
#include <vector>
#include <DxLib.h>

enum MainGraphName
{
	LoadPage,		//	���[�h���
	TitlePage,		// �^�C�g�����
	GameBack_1,		// �Q�[���w�i
	GameBack_2,		// �Q�[���w�i2
	Wall_1,			// ��1(��)
	Wall_2,			// ��2(�c)
	NextKey,		// ��
	Knife,			// �i�C�t
	Cross,			// �\����
	LifeGauge,		// �̗̓Q�[�W
	WordFrame_1,	// �����g1(Light)
	WordFrame_2,	// �����g2(Knife)
	WordFrame_3,	// �����g3(Key)
	WordFrame_4,	// �����g4(Cross)
	ItemFrame,		// �����g
	mnmall_num			// ����
};

// �v���C���[
enum PlayerGraph
{
	pgmRight,	// �E
	pgmLeft,	// ��
	pgmBack,	// �w��
	pgmAtack,	// �U��
	pgmWin,	// ����
	pgmDeath,	// �|���
	pgmall_num	// ����
};

// �G
enum EnemyGraph
{
	egmRight,	// �E
	egmLeft,		// ��
	egmAtack,	// �U��
	egmDeath,	// �|���
	egmall_num	// ����
};

// ���ׂĎg��Ȃ����ǈꉞ
enum WordGraph
{
	A,B,C,D,E,
	F,G,H,I,J,
	K,L,M,N,O,
	P,Q,R,S,T,
	U,V,W,X,Y,
	Z,wgmall_num
};

// �摜�N���X
class Graphics
{
public:
	Graphics();
	Graphics(std::string path);
	~Graphics();
	
	// �ǂݍ��ݏ���
	static void LoadMainGraphics();
	static void LoadPlayerGraphics();
	static void LoadEnemyGraphics();
	static void LoadWordGraphics();
	
	// �摜�擾
	static int GetMainGraph(int _num);
	static int GetPlayerGraph(int _num, int _anime);
	static int GetEnemyGraph(int _num, int _anime);
	static int GetWordGraph(int _num);

	// �T�C�Y�擾
	static int GetPGS(int _num);
	static int GetEGS(int _num);

	static bool loadFlag[4];						// �ǂݍ��ݗp�t���O

private:
	static std::vector<int>gr;						// ���C���ł��낢��g���摜�n���h��
	static std::vector<std::vector<int>>chara_gr;	// �v���C���[�p�摜�n���h��(�s��6���)
	static std::vector<std::vector<int>>enemy_gr;	// �G�p�摜�n���h��(�s��4���)
	static std::vector<int>word_gr;					// �����p�摜�n���h��(26���)
};