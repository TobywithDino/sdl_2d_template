# 2D遊戲模板
使用SDL庫以及C++進行遊戲開發的模板，旨在為了加快開發速度，將2D專案都會使用的特性以及環境設置作為模板。

## 開發環境
- 作業系統：Windows 64位元
> 注意！雖然使用Windows，但makefile中指令皆使用Bash指令，請在Bash環境中執行make指令。
- 程式語言以及編譯器：C++搭配MinGW64
- 外部庫：SDL2-2.30.3 64位元

## 設置步驟
1. 下載這個模板。
2. 下載MinGW64，設置PATH (例如：D:\mingw64\bin)。
> 為了方便使用make指令，在`mingw64\bin`中，可以把`mingw32-make.exe`改名成`make.exe`。
3. 下載SDL2。
> 使用64位元，所以文件夾名應該是`x86_64-w64-mingw32`，動態編譯後，與執行檔相同的位置應該要有`SDL2.dll`檔案，否則會無法執行，建議可以將SDL2.dll所在的資料夾直接設置PATH (例如：`D:\SDL\x86_64-w64-mingw32\bin`)
4. 更改`makefile`中有關庫文件的位址以及資料夾位址，按照自己的文件所需更該。
> 使用絕對位址是為了讓不同專案可以共用一個SDL檔案，不需要每次都複製道專案中，減少檔案。
5. 若使用`vscode`，可以將`C/C++ Configurations`打開，在`include path`中，加上`${workspaceFolder}/include/**`以及SDL2檔案的include資料夾 (例如：`D:/SDL/i686-w64-mingw32/include/SDL2/**`)
6. 使用makefile時，`make`指令可以進行編譯，SDL庫的部分為動態編譯，且為了除錯方便，沒有將cmd關掉，即編譯成 `控制台應用程式`。
7. `make release`指令同樣可以進行編譯，但是這次SDL庫以及相關文件皆使用靜態編譯，執行檔檔案大小會變大許多，並且編譯成 `Windows GUI 應用程式`。
> 靜態編譯讓所需函數在編譯時都包入執行檔中，動態編譯則在執行時透過dll檔尋找所需函數。靜態編譯不需要其他使用者執行程式時，下載其他所需的dll檔，比較方便。

## 模板說明
#### 資料夾
- /build - `make`指令後產生，編譯後會產生.o檔，暫存至這裡。當重新編譯時，只針對更新過的cpp文件進行編譯，減少編譯時間。
- /include - 遊戲所需header放在這裡，不包含SDL。
- /res - 遊戲所需文件放在這裡，例如圖片、音樂、字體。
- /src - 遊戲所需cpp文件放在這裡。

#### makefile
- 使用makefile指令可以自動執行文件中已寫好的指令
> makefile指令詳解待補

#### cpp文件
- main.cpp
- game.cpp
- object.cpp
- rock.cpp

#### header文件
- game.h
- coord.h
- object.h
- rock.h