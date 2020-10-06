#ifndef DRAWER_BASE_H_
#define DRAWER_BASE_H_

/**
* @file DrawerBase.h
* @brief DrawerBase�N���X�̃w�b�_
*/


#include <string>

/**
* @class DrawerBase
* Drawer�N���X�̊��N���X
*/
class DrawerBase
{
public:
	DrawerBase();
	virtual ~DrawerBase();

	void Run();

	void Print();

	virtual void ClearBuffer() = 0;

	/*
		���L�֐��͏������z���ƈ����ɖ{������ׂ��`��^�C�v��
		��񂪍��̂܂܂��Ɠ�����Ȃ����߁A��������h����ł��ꂼ����
	*/
	// virtual void SetDrawBuffer() = 0;
	// virtual void SetBlankBuffer() = 0;
	// virtual void SetResult() = 0;

protected:
	std::string m_draw_string;

};

#endif