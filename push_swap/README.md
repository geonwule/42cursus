42_push_swap / stack a 와 stack b 이용해 오름차순 정렬하기 🎈

0. Introduction


ScreenShot
map

HOW TO USE ?




1. push_swap 구상
main함수 실행 시, argc argv를 통해 sort할 숫자 입력
    ./push_swap "2 3 5 8 0"
 1) 입력되는 숫자의 갯수는 랜덤이므로 linked_list 사용
 2) 입력되는 숫자는 양의정수와 음의정수값으로 나와있으므로 C언어 최대 값 long long 사용
/* 
예외 사항 처리 할 것들
    1. 중복된 숫자
    2. 숫자가 아닌 입력값
*/

2. push_swap 구현
so_long.c
int main(int ac, char **av)
so_long 준비단계
int check_ac_av(int ac, char *av)
void initialize_map_info(t_check_map *info)
so_long 맵 읽기단계
char *read_map(int fd, t_check_map *info)
so_long 맵 체크단계
int check_map_cnt(t_check_map *info)
int check_map_wall(char *map, t_check_map info, int index)
int check_map_dfs(char *map, t_check_map *info)
so_long mlx 단계
void run_mlx(t_check_map *map)
(1) so_long_ready.c (준비단계)
int check_ac_av(int ac, char *av)
ac, av 알맞게 왔는지 체크하는 함수
void initialize_map_info(t_check_map *info)
map_info 구조체 초기화하는 함수
(2) so_long_read.c (지도 읽기단계)
char *read_map(int fd, t_check_map *info)
map을 read해서 1차원 배열로 리턴하는 함수로 저번 과제에서 만든 GNL을 활용
get_next_line.c / get_next_line_utils.c (GNL 코드)
(3) so_long_check.c (지도 체크단계)
int check_map_cnt(t_check_map *info)
'C' 수집품이 1개 이상인지, 'E' 출구가 1개인지, 'P' 출발점이 1개인지 확인하는 함수
int check_map_wall(char *map, t_check_map info, int index)
지도가 '1' 벽으로 둘러싸여 있는지 확인 하는 함수
int check_map_dfs(char *map, t_check_map *info)
['P' 출발 -> 'C' 모든 수집품 -> 'E' 출구] 과정이 이루어질 수 있는지 확인하는 함수
(4) so_long_screen.c / so_long_event.c (mlx 단계)
void run_mlx(t_check_map *map)
mlx를 실행 및 유지 시키는 함수
게임 시작 및 화면 띄우는 코드 : so_long_screen.c 파일에 분류
게임 실행 중, 이벤트 발생 시 처리해야 할 코드 : so_long_event.c 파일에 분류