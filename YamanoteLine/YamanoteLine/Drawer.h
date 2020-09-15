#ifndef DRAWER_H_
#define DRAWER_H_

class Drawer {
public:
	Drawer();
	~Drawer();

	// �`��֐�
	void Draw();

	// ���v��莞�ԃZ�b�g�֐�
	inline void SetClockWiseTime(int time) {
		m_clock_wise_time = time;
	}
	// �����v��莞�ԃZ�b�g�֐�
	void SetCounterClockWiseTime(int time) {
		m_counter_clock_wise_time = time;
	}


private:
	int m_clock_wise_time;				// ���v���̏o���w���瓞���w�܂ł̎���
	int m_counter_clock_wise_time;		// �����v���̏o���w���瓞���w�܂ł̎���

};

#endif
