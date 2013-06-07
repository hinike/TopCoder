/**
 * TopCoder:RevolvingDoors
 * ��http://community.topcoder.com/stat?c=problem_statement&pm=3064&rd=5869��
 * Author: xuzhezhao
 * E-mail: zhezhaoxu@gmail.com
 * Blog: http://blog.csdn.net/xuzhezhaozhao/
 * Date: 2013/6/7
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

#define MAX 50			/* ��ͼ���������� */
#define DOORS_MAX 10		/* �������� */

class RevolvingDoors
{
public:
	int turns(string map[]);
};

enum Door_State {H, V};		/* �ŵ�״̬��H��ˮƽ V����ֱ */
typedef struct CurrentPos{
	int row;			/* ��ǰ������ */
	int col;			/* ��ǰ������ */
	Door_State door[MAX][MAX];	/* ��״̬���� */
	int door_pos[DOORS_MAX];	/* ��λ����Ϣ */
	int doors_num;			/* ������ */
	int turn_doors;			/* trun�������� */
}CurrentPos;

static int map_rows = 0;	/* ��ͼ���� */
static int map_cols = 0;	/* ��ͼ���� */
static int end_row;		/* �յ��������� */
static int end_col;		/* �յ��������� */
static int visited[MAX][MAX];

void init(string map[], CurrentPos &curpos);
bool isEnd(CurrentPos curpos);
bool isVisited(list <CurrentPos> LV, CurrentPos curpos);

int main()
{
	RevolvingDoors revolvingdoors;
	
	/* ��ͼ���� "" ��β */
	string map[] = 
	{ 
	"#############",
	"#  #|##|#   #",
	"#   O  O    #",
	"# E || || S #",
	"#    O  O   #",
	"#   #|##|#  #",
	"#############", 
	"" };

	cout << revolvingdoors.turns(map) << endl;
	
	return 0;
}

int RevolvingDoors::turns(string map[])
{
	list <CurrentPos> LC;		/* LC: �ڲ�BFS״̬ */
	list <CurrentPos> LD;		/* LD: ���BFS��turn ����֮���״̬ */
	list <CurrentPos> LV;		/* LV�����BFS����״̬��־������visited���飬����turn����֮���״̬���Ա����ظ� */
	CurrentPos curpos, nextpos;
	int row, col;

	init(map, curpos);
	LD.push_back(curpos);

	/* ���BFS */
	while (!LD.empty()) {
		curpos = LD.front();
		LD.pop_front();

		/* ��ʼ��visited���� */
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				visited[i][j] = false;
			}
		}

		LC.push_back(curpos);

		/* �ڲ�BFS */
		while (!LC.empty()) {
			curpos = LC.front();
			LC.pop_front();
			row = curpos.row;
			col = curpos.col;
			visited[row][col] = true;

			if (isEnd(curpos)) {
				return curpos.turn_doors;
			}

			/* ���������������ĸ������ƽ�״̬ */

			/* ������ */
			nextpos = curpos;
			if (row - 1 >= 0 && !visited[row-1][col]) {
				nextpos.row = row - 1;

				if (' ' == map[row-1][col]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row-1][col]) {	/* �����ŵ��������� */
					/* �ŵ�λ����������� */
					if (row - 2 >= 0 && 'O' == map[row-2][col] && H == curpos.door[row-2][col] ) {
						LC.push_back(nextpos);
					} else if (col + 1 <= map_cols - 1 && 
						'O' == map[row-1][col+1]) {
						if (V == curpos.door[row-1][col+1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col+1] = V;
							++nextpos.turn_doors;
							visited[row-1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					} else if (col - 1 >= 0 && 'O' == map[row-1][col-1]) {
						if (V == curpos.door[row-1][col-1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row-1][col-1] = V;
							++nextpos.turn_doors;
							visited[row-1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					}
				}
			}

			/* ������ */
			nextpos = curpos;
			if (row + 1 <= map_rows - 1 && !visited[row+1][col]) {
				nextpos.row = row + 1;
				if (' ' == map[row+1][col]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row+1][col]) {
					if (row + 2 <= map_rows - 1 && 'O' == map[row+2][col] &&
						H == curpos.door[row+2][col] ) {
						LC.push_back(nextpos);
					} else if (col + 1 <= map_cols - 1 && 'O' == map[row+1][col+1]) {
						if (V == curpos.door[row+1][col+1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = V;
							++nextpos.turn_doors;
							visited[row+1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					} else if (col - 1 >= 0 &&
						'O' == map[row+1][col-1]) {
						if (V == curpos.door[row+1][col-1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row+1][col-1] = V;
							++nextpos.turn_doors;
							visited[row+1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					}
				}
			}

			/* ������ */
			nextpos = curpos;
			if (col - 1 >= 0 && !visited[row][col-1]) {
				nextpos.col = col - 1;
				if (' ' == map[row][col-1]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row][col-1]) {
					if (col - 2 >= 0 && 'O' == map[row][col-2] &&
						V == curpos.door[row][col-2] ) {
						LC.push_back(nextpos);
					} else if (row - 1 >= 0 && 
						'O' == map[row-1][col-1]) {
						if (H == curpos.door[row-1][col-1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col-1] = H;
							++nextpos.turn_doors;
							visited[row][col-1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					} else if (row + 1 <= map_rows - 1 && 'O' == map[row+1][col-1]) {
						if (H == curpos.door[row+1][col-1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row+1][col-1] = H;
							++nextpos.turn_doors;
							visited[row][col-1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					}
				}
			}

			/* ������ */
			nextpos = curpos;
			if (col + 1 <= map_cols - 1 && !visited[row][col+1]) {
				nextpos.col = col + 1;
				if (' ' == map[row][col+1]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row][col+1]) {
					if (col + 2 <= map_cols - 1 && 'O' == map[row][col+2] &&
						V == curpos.door[row][col+2] ) {
							LC.push_back(nextpos);
					} else if (row + 1 <= map_rows - 1 && 
						'O' == map[row+1][col+1]) {
						if (H == curpos.door[row+1][col+1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = H;
							++nextpos.turn_doors;
							visited[row][col+1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					} else if (row - 1 >= 0 &&
						'O' == map[row-1][col+1]) {
						if (H == curpos.door[row-1][col+1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row-1][col+1] = H;
							++nextpos.turn_doors;
							visited[row][col+1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push_back(nextpos);
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

/**
 * ��ʼ��������õ�ͼ�Ļ�����Ϣ���У��У���״̬�����������ܵ�4������Ϊ '*' �ַ����� S�� E ��Ϊ' '(�ո�)��
 */
void init(string map[], CurrentPos &curpos)
{
	int i, j;
	
	curpos.turn_doors = 0;

	while (map[map_rows] != "") {
		++map_rows;
	}
	if (map_rows > 0) {
		map_cols = map[0].length();
	}

	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('S' == map[i][j]) {
				curpos.row = i;
				curpos.col = j;
				map[i][j] = ' ';
			}
			if ('E' == map[i][j]) {
				end_row = i;
				end_col = j;
				map[i][j] = ' ';
			}
		}
	}
	curpos.doors_num = 0;
	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('O' == map[i][j]) {
				curpos.door_pos[curpos.doors_num] = i * map_cols + j;
				++curpos.doors_num;
				if ('|' == map[i+1][j]) {
					curpos.door[i][j] = V;
				} else {
					curpos.door[i][j] = H;
				}
				map[i+1][j] = map[i-1][j] =
					map [i][j+1] = map[i][j-1] = '*';
			}
		}
	}
}

/**
 * �ж��Ƿ񵽴��յ�
 */
bool isEnd(CurrentPos curpos)
{
	if (curpos.row == end_row && curpos.col == end_col) {
		return true;
	} else {
		return false;
	}
}

/**
 * ���BFS���ʱ�־����LV�к���curpos״̬������true�����򷵻�false
 */
bool isVisited(list <CurrentPos> LV, CurrentPos curpos)
{
	list<CurrentPos>::iterator it;
	int door_row, door_col;
	bool flag;
	if (LV.empty()) {
		return false;
	}
	for (it = LV.begin(); it != LV.end(); it++) {
		if (it->row == curpos.row && it->col == curpos.col) {
			flag = true;
			for (int i = 0; i < curpos.doors_num; i++) {
				door_row = curpos.door_pos[i] / map_cols;
				door_col = curpos.door_pos[i] % map_cols;
				if (it->door[door_row][door_col] != curpos.door[door_row][door_col]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
	}
	return false;
}