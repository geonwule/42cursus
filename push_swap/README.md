42_push_swap / stack a 와 stack b 이용해 오름차순 정렬하기 🎈

0. Introduction


ScreenShot
map

HOW TO USE ?



-1. push_swap 내가 겪은 문제들
 1) quik sort로 구현하고 싶으나
 내가 아는 배열에서의 quiksort를 
 리스트에서 제한된 명령어 sa,sb,pa,pb 등으로 하려니
 막막함..

1. push_swap 구상
main함수 실행 시, argc argv를 통해 sort할 숫자 입력
    ./push_swap "2 3 5 8 0"
 1) 입력되는 숫자의 갯수는 랜덤이므로 linked_list 사용
 2) 입력되는 숫자는 양의정수와 음의정수값으로 나와있으므로 C언어 최대 값 long long 사용 xx
 -> integr 의 범위를 벗어나면 안된다는 프로젝트의 말이 있음
 -> 자료형 int형 안에서 처리한다고 해석 가능
  * https://ko.wikipedia.org/wiki/Int_(C_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D_%EC%96%B8%EC%96%B4)
  * --> 인트형에 대한 위키백과 : 정수형을 처리하기 위한 변수로, 정수형(integer)의 약자이다
/* 
에러처리 할 것들 -- error_check
    1. argument가 적어도 1 이상 (ac >= 2 -> a.out포함)
    2. 하나의 av[i]에는 숫자가 하나는 들어가야함(여러개인 경우 수용)--min_digit_check
    3. 숫자, (+, - 하나까지가능) 이 아닌 입력 -- no_integer
    4. INT형 범위 이내 숫자가 아닌경우 (integer정수가 아닌 경우) -- over_int
    5. 중복되는 숫자 -- is_duplicate
*/

2. 겪은 어려움

2-1
    1) a_to_b 에서 pivot 설정시 pivot = (node(i) + node(i+1))/2
    node(i) > pivot = ra
    node(i) <= pb 
    --> 양수끼리는 적용 ok 1 2 -> pivot = 1
    1 -> pb 2 -> ra
    but 음수끼리는 fail -1 -2 -> pivot = -1
    -1 -> pb, -2 -> pb ------ 둘을 나눠야 하는데 실패..

2-2 
    이미 오름차순 정렬 되어있는것은 건들면 x 명령 필요없음. 
    -> 첫 a_to_b 실행시 솔트되어있는 아이는 한곳에 몰아놓고 나중에 끼워주기..?
    -> 처음부터 끝까지 오름차순 되어있을때만 바로 리턴해주기 -> a_to_b 실행전 확인 함수 하나 만들기.
    * already_sort 함수 만들어서 이미 오름차순이면 메인에서 리턴하게 했음.

2-3
    Makefile만들기 전 크게 main함수만 있었을땐 잘 돌아가던것이 Makefile만들어주고
    srcs, includes폴더에 헤더와 c파일들을 분할 후 링크드 해서 컴파일을 하니 
    EXC_BAD_ACCESS 오류가 발생(av를 참조했을시)(어쩔땐 안발생 어쩔땐 발생) -> 컴파일시 -fsanitize옵션 주면 없어지고, 옵션뺴면 생김.. -> Slack에 찾아본 결과 정수형 말록을 안해줘서 생긴다?는 의견 도출.. malloc으로 메모리값 초기화를 안해주면 어쩔땐되고 어쩔땐 쓰레기가 들어가서 안된다? main함수의 인자였던 av를 정수형 말록을 해줘야 하나 고민중...
    * push_swap 안에 있는 ft_printf와 함수가 이름이 겹쳐서 발생한것..
    push_swap의 error_check함수와 ft_printf의 error_check함수가 겹침
    ft_printf의 라이브러리 .a 파일이 같이 컴파일 되면서 오류가 발생..

3. push_swap 구현
