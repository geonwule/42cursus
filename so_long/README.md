so_long

1. get_next_line을 쓰는 이유
    1) map전체를 1차원 배열에 넣어야 하는데 gnl안에서 buffersize만큼 동적할당 해서 잘 읽어줌 -> 그냥 받으려면 map의 크기를 몰라서 힘듦
    -> read(fd, &c, 1)로 크기 측정한다음 close하고 말록한다음 다시 read하면 안써도됌.

2. 맵의 너비(x)와 높이(y)를 알수있음.
   -> x 는 \n전까지 갯수, y는 \n이 나온 갯수 +1

3. hook쓰는 이유 : 마우스로 x눌렀을때 끄게 해주려고

4. key_hook 쓰는 이유 : keyboard 입력을 받아주려고
