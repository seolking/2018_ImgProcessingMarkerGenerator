# 2018_ImgProcessingMarkerGenerator
2018 fall image processing class team project - marker generator

Visual Studio 2017 Community
openCV VC15

팀 프로젝트의 마커 생성기<br>
영어 대소문자 + 숫자 + 공백(스페이스) + 느낌표(!)로 구성된 8글자의 문자열을 정해진 규칙을 통해<br>
글자 하나를 빨강, 초록, 주황, 검정 4색 * 3칸으로 표현한다.<br>
출력되는 이미지는 140 * 140 고정이며 한 칸은 20px. 테두리 20px은 마커의 모서리로 사용하며, 가운데 100 * 100이 5 * 5의 마커로 사용된다.<br>
파랑색은 마커의 왼쪽 위를 구분하기 위에 맨 첫 칸은 파랑색으로 고정, 나머지 24칸은 3칸씩 8글자를 나타내게 된다.<br><br>

> markerGenerator.exe (입력) <br>
입력에는 8글자 입력을 받으며 정확한 8글자 입력이 있을 때만 결과값이 나온다.

