#include "Graphics.h"

std::vector<int> Graphics::gr;
std::vector<std::vector<int>>Graphics::chara_gr;
std::vector<std::vector<int>>Graphics::enemy_gr;
std::vector<int>Graphics::word_gr;
bool Graphics::loadFlag[4];

Graphics::Graphics()
{
	loadFlag[0] = 0;
	loadFlag[1] = 0;
	loadFlag[2] = 0;
	loadFlag[3] = 0;
	gr.resize(MainGraphName::mnmall_num);
	chara_gr.resize(PlayerGraph::pgmall_num);
	enemy_gr.resize(EnemyGraph::egmall_num);
	word_gr.resize(WordGraph::wgmall_num);
}

Graphics::Graphics(std::string path)
{
	gr.resize(MainGraphName::mnmall_num);
	int _gr = LoadGraph(path.c_str());
	if (_gr != -1)
	{
		gr[0] = _gr;
	}
	chara_gr.resize(PlayerGraph::pgmall_num);
	enemy_gr.resize(EnemyGraph::egmall_num);
	word_gr.resize(WordGraph::wgmall_num);
	loadFlag[0] = 0;
	loadFlag[1] = 0;
	loadFlag[2] = 0;
	loadFlag[3] = 0;
}

Graphics::~Graphics()
{
	for (int i = 0, n = (unsigned)gr.size(); i < n; i++)
	{
		DeleteGraph(gr[i]);
		gr[i] = 0;
	}
	gr.erase(gr.begin(), gr.end());
	for (int i = 0, n = (unsigned)word_gr.size(); i < n; i++)
	{
		DeleteGraph(word_gr[i]);
		word_gr[i] = 0;
	}
	word_gr.erase(word_gr.begin(), word_gr.end());
	for (int i = 0, n = (unsigned)enemy_gr.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)enemy_gr[i].size(); j < m; j++)
		{
			DeleteGraph(enemy_gr[i][j]);
			enemy_gr[i][j] = 0;
		}
	}
	enemy_gr.erase(enemy_gr.begin(), enemy_gr.end());
	for (int i = 0, n = (unsigned)chara_gr.size(); i < n; i++)
	{
		for (int j = 0, m = (unsigned)chara_gr[i].size(); j < m; j++)
		{
			DeleteGraph(chara_gr[i][j]);
			chara_gr[i][j] = 0;
		}
	}
	chara_gr.erase(chara_gr.begin(), chara_gr.end());
	loadFlag[0] = 0;
	loadFlag[1] = 0;
	loadFlag[2] = 0;
	loadFlag[3] = 0;
}

void Graphics::LoadMainGraphics()
{
	std::string path;
	for (int i = 1, n = (unsigned)gr.size(), _gr = 0; i < n; i++)
	{
		path = "graph/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			gr[i] = _gr;
		}
		else
		{
			gr[i] = 0;
		}
	}

}

void Graphics::LoadPlayerGraphics()
{
	std::string path;
	for (int i = 1, n = (unsigned)gr.size(), _gr = 0; i < n; i++)
	{
		path = "graph/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			gr[i] = _gr;
		}
		else
		{
			gr[i] = 0;
		}
	}
}

void Graphics::LoadEnemyGraphics()
{
	std::string path;
	for (int i = 1, n = (unsigned)gr.size(), _gr = 0; i < n; i++)
	{
		for (int j = 0, m = (unsigned)enemy_gr[i].size(); j < m; j++)
		{
			path = "graph/enemy/" + std::to_string(i) + "/" + std::to_string(i) + ".png";
			_gr = LoadGraph(path.c_str());
			if (_gr != -1)
			{
				gr[i] = _gr;
			}
			else
			{
				gr[i] = 0;
			}
		}
	}
}

void Graphics::LoadWordGraphics()
{
	std::string path;
	for (int i = 1, n = (unsigned)word_gr.size(), _gr = 0; i < n; i++)
	{
		path = "graph/word/" + std::to_string(i) + ".png";
		_gr = LoadGraph(path.c_str());
		if (_gr != -1)
		{
			word_gr[i] = _gr;
		}
		else
		{
			gr[i] = 0;
		}
	}
}

int Graphics::GetMainGraph(int _num)
{
	return gr[_num];
}

int Graphics::GetPlayerGraph(int _num, int _anime)
{
	return chara_gr[_num][_anime];
}

int Graphics::GetEnemyGraph(int _num, int _anime)
{
	return enemy_gr[_num][_anime];
}

int Graphics::GetWordGraph(int _num)
{
	return word_gr[_num];
}

int Graphics::GetPGS(int _num)
{
	return (unsigned)chara_gr[_num].size();
}

int Graphics::GetEGS(int _num)
{
	return (unsigned)enemy_gr[_num].size();
}