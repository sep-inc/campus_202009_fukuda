#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <vector>

#define DATA_SIZE 10	// �f�[�^�T�C�Y
#define RAND_MAX 100	// �����̍ő�l

// �f�[�^�\����
struct Data {
	int m_random_num;
	int m_sort_order;
};

// �l����ւ��֐�
void Swap(int* x, int* y) {
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

// �����_���ȃf�[�^���쐬����֐��i�v�f�̏d�������j
void CreateRandomArray(Data data[]) {
	int data_table[RAND_MAX];
	// 1�`100�̒l�����ɑ��
	for (int i = 0; i < RAND_MAX; i++) {
		data_table[i] = i + 1;
	}
	// �f�[�^�e�[�u���̗v�f�������_���ɓ���ւ���
	for (int i = 0; i < RAND_MAX; i++) {
		int rand1 = rand() % 100;
		int rand2 = rand() % 100;
		Swap(&data_table[rand1], &data_table[rand2]);
	}
	// �����_���ȃf�[�^�e�[�u���̐擪����10���f�[�^�z��ɑ��
	for (int i = 0; i < DATA_SIZE; i++) {
		data[i].m_random_num = data_table[i];
	}
}

// �N�C�b�N�\�[�g
void QuickSort(int data[], int left, int right) {
	int pivot, lead_left, lead_right;	// �s�{�b�g�l�A���̐擪�A�E�̐擪
	lead_left = left;
	lead_right = right;
	// �s�{�b�g��z��̈�ԍ��ɐݒ�
	pivot = data[lead_left];

	// �s�{�b�g�����Ƃɔz��̕�������
	while (left < right) {
		// �z��̈�Ԍ�납�猟�����ăs�{�b�g��菬�����l��������܂�
		while ((data[right] >= pivot) && (left < right)) {
			right--;
		}
		// ����������擪�ɂ��̒l�������A��ԍ������炷
		if (left != right) {
			data[left] = data[right];
			left++;
		}
		// �z��̍����猟�����ăs�{�b�g���傫���l��������܂�
		while ((data[left] <= pivot) && (left < right)) {
			left++;
		}
		// �����������قǑ���Ɏg�����v�f�ɂ��̒l����
		if (left != right) {
			data[right] = data[left];
			right--;
		}
	}
	// �f�[�^�̍��Ƀs�{�b�g�̒l����
	data[left] = pivot;
	pivot = left;
	left = lead_left;
	right = lead_right;
	// �����������̔z��ŃN�C�b�N�\�[�g
	if (left < pivot) {
		QuickSort(data, left, pivot - 1);
	}
	// ���������E�̔z��ŃN�C�b�N�\�[�g
	if (right > pivot) {
		QuickSort(data, pivot + 1, right);
	}
}

// �\�[�g���ʂ��f�[�^�z��ɖ߂�
void SetSortResult(Data data[],int sort_data[]) {
	for (int i = 0; i < DATA_SIZE; i++) {
		for (int j = 0; j < DATA_SIZE; j++) {
			if (sort_data[i] == data[j].m_random_num) {
				data[j].m_sort_order = i;
			}
		}
	}
}

int main() {
	srand((unsigned)time(NULL));

	Data data_array[DATA_SIZE];		// ���ƂȂ�f�[�^�z��
	int sort_array[DATA_SIZE];		// �\�[�g�p�z��

	// ����������
	CreateRandomArray(data_array);
	// ���f�[�^�\�� & �\�[�g�z��փf�[�^����
	printf("�����_���f�[�^�\��\n");
	for (int i = 0; i < DATA_SIZE; i++) {
		sort_array[i] = data_array[i].m_random_num;
		printf("%d ", data_array[i].m_random_num);
	}
	printf("\n\n");


	// �N�C�b�N�\�[�g
	QuickSort(sort_array, 0, DATA_SIZE - 1);
	// �\�[�g�f�[�^�����f�[�^�ɃZ�b�g
	SetSortResult(data_array, sort_array);


	// ���ʕ\��
	printf("�\�[�g����\n");
	for (int i = 0; i < DATA_SIZE; i++) {
		printf("���l : %d ���� : %d\n",data_array[i].m_random_num,data_array[i].m_sort_order);
	}

}