#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <vector>

#define DATA_SIZE 10	// データサイズ
#define RAND_MAX 100	// 乱数の最大値

// データ構造体
struct Data {
	int m_random_num;
	int m_sort_order;
};

// 値入れ替え関数
void Swap(int* x, int* y) {
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

// ランダムなデータを作成する関数（要素の重複無し）
void CreateRandomArray(Data data[]) {
	int data_table[RAND_MAX];
	// 1～100の値を順に代入
	for (int i = 0; i < RAND_MAX; i++) {
		data_table[i] = i + 1;
	}
	// データテーブルの要素をランダムに入れ替える
	for (int i = 0; i < RAND_MAX; i++) {
		int rand1 = rand() % 100;
		int rand2 = rand() % 100;
		Swap(&data_table[rand1], &data_table[rand2]);
	}
	// ランダムなデータテーブルの先頭から10個をデータ配列に代入
	for (int i = 0; i < DATA_SIZE; i++) {
		data[i].m_random_num = data_table[i];
	}
}

// クイックソート
void QuickSort(int data[], int left, int right) {
	int pivot, lead_left, lead_right;	// ピボット値、左の先頭、右の先頭
	lead_left = left;
	lead_right = right;
	// ピボットを配列の一番左に設定
	pivot = data[lead_left];

	// ピボットをもとに配列の分割処理
	while (left < right) {
		// 配列の一番後ろから検索してピボットより小さい値が見つかるまで
		while ((data[right] >= pivot) && (left < right)) {
			right--;
		}
		// 見つかったら先頭にその値を代入し、一番左をずらす
		if (left != right) {
			data[left] = data[right];
			left++;
		}
		// 配列の左から検索してピボットより大きい値が見つかるまで
		while ((data[left] <= pivot) && (left < right)) {
			left++;
		}
		// 見つかったら先ほど代入に使った要素にその値を代入
		if (left != right) {
			data[right] = data[left];
			right--;
		}
	}
	// データの左にピボットの値を代入
	data[left] = pivot;
	pivot = left;
	left = lead_left;
	right = lead_right;
	// 分割した左の配列でクイックソート
	if (left < pivot) {
		QuickSort(data, left, pivot - 1);
	}
	// 分割した右の配列でクイックソート
	if (right > pivot) {
		QuickSort(data, pivot + 1, right);
	}
}

// ソート結果をデータ配列に戻す
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

	Data data_array[DATA_SIZE];		// 元となるデータ配列
	int sort_array[DATA_SIZE];		// ソート用配列

	// 初期化処理
	CreateRandomArray(data_array);
	// 元データ表示 & ソート配列へデータを代入
	printf("ランダムデータ表示\n");
	for (int i = 0; i < DATA_SIZE; i++) {
		sort_array[i] = data_array[i].m_random_num;
		printf("%d ", data_array[i].m_random_num);
	}
	printf("\n\n");


	// クイックソート
	QuickSort(sort_array, 0, DATA_SIZE - 1);
	// ソートデータを元データにセット
	SetSortResult(data_array, sort_array);


	// 結果表示
	printf("ソート結果\n");
	for (int i = 0; i < DATA_SIZE; i++) {
		printf("数値 : %d 順番 : %d\n",data_array[i].m_random_num,data_array[i].m_sort_order);
	}

}