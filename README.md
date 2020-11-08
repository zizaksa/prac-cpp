# C/C++ Study
C/C++ 연습을 위한 레포지토리 입니다. 연습에 필요한 코드는 마스터 브랜치에 올릴 예정입니다. 그리고 작성한 코드는 여기 저장소의 개인의 **브랜치**에 푸시하여 주시기 바랍니다.

## Assignments
[Go to Link](https://github.com/zizaksa/prac-cpp/wiki/Cpp-%EC%8A%A4%ED%84%B0%EB%94%94)

# Directory Structure
```
+ assignments
+-- ...
+ docs
+-- ...
+ note
+-- ...
```

`assignments` 폴더는 코딩 연습에 필요한 파일들을 제공합니다. 폴더 내부에 과제에 필요한 코드 및 문서가 저장되어 있습니다.

`docs` 폴더는 스터디에 필요한 문서들을 필요할때마다 작성할 예정입니다. 

`note` 폴더는 개인이 필요한 노트를 작성하여 저장되는 위치입니다.

그 외에 필요한 폴더들은 개인 브랜치에 마음껏 올려도 상관 없습니다. 다만 `assignments` 폴더와 `docs` 폴더는 제거하거나 이름을 변경해서는 안됩니다.

# Study Process

스터디에 필요한 코드들은 **master** 브랜치에 업로드 됩니다. 올라온 과제를 이제 개인 브랜치로 가져가서 작성해야 합니다. 과제를 올릴때 과제의 **Commit ID** 제공됩니다. 개인의 브랜치에서 해당 커밋 ID를 **Cherry Pick** 하여 파일들을 가져와야 합니다. Cherry Pick은 다른 브랜치의 있는 일부 커밋을 현재 브랜치로 가져오는 작업을 수행합니다. (자세한 별도로 한번 찾아서 내용을 읽어봐주시기 바랍니다.) Cherry Pic의 명령어는 다음과 같습니다.

```sh
$ git cherry-pick <Commit ID>
```

이때 Commit ID는 모든자리를 입력해도 되지만 보통 앞 8자리만 입력해도 충분히 커밋을 구별할 수 있으니 8자리만 입력해도 무방합니다.

```sh
$ git cherry-pick 46ea6ababf0b844b84ac92172e8396c24c9a75bf

Or

$ git cherry-pick 46ea6aba
```

스터디 자료가 브랜치로 옮겨졌다면 이제 주어진 과제에 맞게 코드를 작성합니다.

# Build & Run

주어진 과제들에는 **Makefile**이 동봉되어 있을겁니다. Makefile은 파일 관련 유틸리티로 좋은 프로그램입니다. 자세한 내용은 각자 찾아보시기 바랍니다. 과제 코드를 다 작성하였으면 컴파일을 해야합니다. 이때 간단히 다음 명령어만 치면 됩니다.

**For Linux**
```sh
$ make
```

**For Windows**
```sh
$ mingw32-make
```

그럼 각 디렉토리에 실행파일이 생기며 과제 문서에 명시되어 있는대로 진행하시면 됩니다.

## VS Code
또는 VS Code에서 빌드환경을 구축하여 진행하셔도 됩니다. 자세한 사항은 추후에 올려드리도록 하겠습니다.

# Push

코드를 다 작성하시면 꼭 **push** 해서 원격브랜치에 올리는 것을 잊이 말아주시기 바랍니다.

# Hello World!

그럼 간단히 실습을 통해 과정을 연습해보겠습니다.

먼저 개인 브랜치로 체크아웃 합니다.

```sh
$ git checkout <Your Github ID>
```

그런 다음 첫번째 과제인 `Hello World!`의 Commit ID를 Cherry Pick 합니다. 해당 과제의 Commit ID는 `33c56cca049331b5965792a14cd302e6e3ca5243` 입니다.

```sh
$ git cherry-pick 33c56cca049331b5965792a14cd302e6e3ca5243
```

그러면 `assignments` 폴더에 새로운 폴더가 생성되고, 그 안에 과제가 담겨져 있을겁니다.

이제 과제내용에 명시된 대로 `./src/program.cpp` 파일을 다음과 같이 수정합니다.

```cpp
#include <stdio.h>

int main() {
    printf("Hello World!");
    return 0;
}
```

이제 잘 동작하는지 확인합니다.

```sh
$ mingw32-make
g++ -Wall -Wno-sign-compare -O2 -g -I./include/ -L./lib/ -lpthread -fopenmp --std=c++11   -c -o src/program.o src/program.cpp
g++ -o practice.exe src/program.o -Wall -Wno-sign-compare -O2 -g -I./include/ -L./lib/ -lpthread -fopenmp --std=c++11

$ ./practice.exe
Hello World!
```

그리고 파일을 커밋합니다. 커밋 메시지는 아무 메시지나 상관 없으나, 추후에 자신이 어떤 작업을 했는지 구분을 할 수 있으면 됩니다.

```sh
$ git add assignments
$ git commit -m "finish first assignment"
```

그런 다음 파일을 원격 저장소에 푸시합니다.

```sh
$ git push
```