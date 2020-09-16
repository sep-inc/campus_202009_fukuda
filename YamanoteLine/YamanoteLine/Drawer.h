#ifndef DRAWER_H_
#define DRAWER_H_

class Drawer {
public:
	Drawer();
	~Drawer();

	// �`��֐�
	void Draw();

	// �Z�b�g�֐��Q
	// ���v��莞�ԃZ�b�g�֐�
	inline void SetClockWiseTime(int time) {
		m_clock_wise_time = time;
	}
	// ����������̎��v��莞�ԃZ�b�g�֐�
	inline void SetClockWiseTime2(int time) {
		m_clock_wise_time2 = time;
	}
	// �����v��莞�ԃZ�b�g�֐�
	inline void SetCounterClockWiseTime(int time) {
		m_counter_clock_wise_time = time;
	}
	// ����������̔����v��莞�ԃZ�b�g�֐�
	inline void SetCounterClockWiseTime2(int time) {
		m_counter_clock_wise_time2 = time;
	}


private:
	int m_clock_wise_time;				// ���v���̏o���w���瓞���w�܂ł̎���
	int m_clock_wise_time2;				// ���v��肩����������̎���
	int m_counter_clock_wise_time;		// �����v���̏o���w���瓞���w�܂ł̎���
	int m_counter_clock_wise_time2;		// �����v��肩����������̎���

};

#endif
