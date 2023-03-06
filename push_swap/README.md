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

1-1. 겪은 어려움
    1) a_to_b 에서 pivot 설정시 pivot = (node(i) + node(i+1))/2
    node(i) > pivot = ra
    node(i) <= pb 
    --> 양수끼리는 적용 ok 1 2 -> pivot = 1
    1 -> pb 2 -> ra
    but 음수끼리는 fail -1 -2 -> pivot = -1
    -1 -> pb, -2 -> pb ------ 둘을 나눠야 하는데 실패..

2. push_swap 구현
