# quantumPang
pang type of game using quantum theory concepts
양자이론을 접목한 팡 type의 게임, 퀀텀팡입니다.

### 0.퀀텀팡이란?
![image](https://user-images.githubusercontent.com/58128848/96974153-c9f9eb00-1553-11eb-8861-88ee1d5cf044.png)


양자 이론의 양자 분리, 병합의 컨셉을 게임에 접목한 pang type의 게임으로, 기본적으로는 같은 색깔의 블록을 모아 터뜨려 점수를 얻는 게임입니다.
하지만, 블록이 양자처럼 50%의 확률로 서로 다른 두 위치에 동시에 존재하도록 분리할 수 있으며, 이를 확률적으로 병합시킬 수도 있습니다.
이러한 성질을 이용해 블록을 한꺼번에 터뜨려 높은 점수를 얻는 목적의 게임입니다.
자세한 설명은 아래를 참고하세요.

### 1.컴파일된 배포파일 다운로드 경로
윈도우는 아래 링크에서 게임을 다운받아 압축을 풀고, 바로 실행하여 플레이할 수 있습니다.
https://www.notion.so/f87e13edb6334beeaf1b07f20e063c14

### 2.조작법

메뉴 이동: 위, 아래 방향키

메뉴 선택: 스페이스바 혹은 엔터

옵션 값 조절: 좌, 우 방향키

블록 이동: 상,하,좌,우 방향키

양자 분리: ALT

양자 병합: C

블록 놓기: 스페이스바

게임 종료: Esc

### 3.메인 메뉴
![image](https://user-images.githubusercontent.com/58128848/96973820-5f48af80-1553-11eb-82b1-4ef12ce85c20.png)

메인 메뉴는 위에서부터 게임시작, 게임설정 입니다.

### 4.게임 설정
![image](https://user-images.githubusercontent.com/58128848/96973862-6ec7f880-1553-11eb-8323-e83833824720.png)

메인 메뉴에서 '게임 설정'을 선택하면 위와 같은 옵션 페이지로 넘어옵니다.
옵션 메뉴는 위에서 부터 차례대로 가로 사이즈, 세로 사이즈, 병합 모드, 옵션 저장입니다.
병합 모드에 대한 설명은 아래의 병합 모드를 확인해주세요.

### 5.게임 방법
![image](https://user-images.githubusercontent.com/58128848/96973970-8d2df400-1553-11eb-8d95-b5d0c30b102f.png)

기본적으로 위와 같이 방향키를 움직여서 스페이스바를 이용해 다양한 색깔의 블록을 배치할 수 있습니다.
블록은 8초안에 배치하여야 하며, 시간이 초과되면 감점이 되며 다른 색깔로 랜덤하게 바뀝니다.
블록은 같은 색깔의 블록이 3개 붙어있는 순간 사라지며 점수를 얻게 됩니다.
이때 점수는 한번에 터진 같은 색깔의 블록의 갯수를 n이라고 할 때, 1+2+3+4+...+n의 값만큼 점수를 획득합니다.
따라서 한번에 많은 블록을 터뜨릴 수록 고득점에 유리합니다.
![image](https://user-images.githubusercontent.com/58128848/96976139-6d4bff80-1556-11eb-9c71-be5ad0a40edd.png)

하지만 3개의 블록이 붙자마자 바로 터지기 때문에 위와 같이 파란색 블록을 십자모양으로 배치한 뒤,
마지막에 가운데 파란 블록을 넣는 다면, 총 9개의 블록이 터지면서 45점을 획득할 수 있습니다.
하지만 양자 분리를 이용하면 더욱 고득점을 노려볼 수 있습니다.
![image](https://user-images.githubusercontent.com/58128848/96974021-9cad3d00-1553-11eb-8d6a-11edb0f02e2d.png)

스페이스바를 통해 블록을 배치하지 않고, ALT키를 통해 블록을 배치하면, 위처럼 흐린 색깔의 블록으로 배치됩니다.
또한 ALT키를 누르면 한 개의 블록을 2개의 위치에 배치하여야 합니다.
이렇게 2개의 위치에 배치된 블록은 1개의 블록이지만 50%의 확률로 두 곳 모두에 위치합니다.
따라서 주변에 아무리 많은 블록이 모이더라도 '터지지 않습니다'
![image](https://user-images.githubusercontent.com/58128848/96974153-c9f9eb00-1553-11eb-8861-88ee1d5cf044.png)

그리고 위와 같이 양자 분리된 블록이 있는 상태에서, 양자 병합 'c'키를 누르면 아래와 같이 둘 중 한 곳의 위치로 블록이 확정됩니다.

![image](https://user-images.githubusercontent.com/58128848/96974176-d2522600-1553-11eb-91e0-612d2971d542.png)
이때, 주변에 같은 블록이 3개 이상 모여있다면 터지게 됩니다. 이를 활용해서 9개보다 많은 블록을 한꺼번에 터뜨릴 수 있습니다.
이때, 병합되는 방식은 옵션의 병합 모드에 따라 다릅니다.
병합 모드에 대한 설명은 아래 병합 모드를 확인해 주세요.

### 6. 병합 모드
병합 모드는 0과 1 두가지 모드가 존재합니다. 옵션에서 설정할 수 있습니다.
병합모드가 0인 경우에는 c키를 누르면, 지금까지 양자 분리된 모든 블록이 병합됩니다.
병합모드가 1인 경우에는 c키를 누르면, 현재 배치해야할 블록의 색깔과 같은 블록만 양자 병합됩니다.

