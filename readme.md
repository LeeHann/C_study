# 내가 정리하는 github 사용법

(github에 새로 만든 레포지토리가 있다고 가정)

1. git 설치
2. 폴더에 오른쪽 마우스 키에서 bash로 들어가기
    2-1. 혹은 vscode 환경 설정 후 vscode 터미널 중 bash 사용
    2-2. 혹은 다른 CLI 사용
3. git init
4. git add -A
5. git commit -m "commit message"
6. (이름과 이메일 설정 후) 깃허브에서 정보 복사 하고 CLI에 붙여넣기
7. 에러 발생 시
1) fatal: remote origin already exists.
-> git remote rm origin -> 이거로 삭제하고 -> git remote add origin git@github.com:"레포지토리 경로"

2) git@github.com: Permission denied (publickey).
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
-> ssh-keygen -t rsa -C "깃 이메일"
-> public key 위치 복사해서
-> cat "public key 위치"
-> ssh-... 부터 전부 복사하기
-> 깃허브-> settings -> ssh and gpg keys -> new ssh key에서 붙여넣기

-> git push -u origin master -> 엔터 -> 비밀번호 입력(이후 브랜치 등 할때 다시 입력해야 할 수도 있음) -> 끝
8. git add -A
9. git commit -m "commit message"
10. git push origin master