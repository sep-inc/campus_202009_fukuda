#include "Drawer.h"
#include <iostream>

Drawer* Drawer::p_instance = 0;

Drawer::Drawer():
	m_map_string(""),
	m_result_string("")
{

}

Drawer::~Drawer()
{

}

Drawer* Drawer::Instance()
{
	if (p_instance == 0) {
		p_instance = new Drawer;
	}
	return p_instance;
}

void Drawer::Run()
{
	// �Q�[���}�b�v�̕`��
	DrawMapString();
	// ���U���g���ʂ̕`��
	DrawResultString();
	// �`��p������̃N���A
	ClearStrings();
}

void Drawer::DrawMapString()
{
	std::cout << m_map_string.c_str() << std::flush;
}

void Drawer::DrawResultString()
{
	if (m_result_string != "") {
		std::cout << m_result_string.c_str() << std::endl;
	}
}

void Drawer::ClearStrings()
{
	m_map_string.clear();
	m_result_string.clear();
}

void Drawer::SetDrawMapString(std::string string)
{
	m_map_string = string;
}

void Drawer::SetResultString(std::string string)
{
	m_result_string = string;
}
