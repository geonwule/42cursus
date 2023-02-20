

atexit (leaks); /// 가장 윗부분 
void leaks(void) { system("leaks so_long"); } 
/// 따로 함수 만들어놓기 를 통해서 게임이 종룔된 
//후에 누수를 검사하는것도 알게되었습니다. 고생많으셨습니다!