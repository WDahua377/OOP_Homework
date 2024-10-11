## 程式目的
C++、java、Python 三種程式碼功能相同，會持續讀取使用者輸入的分數，並在使用者輸入 -1 時計算並顯示當前輸入分數的平均值，當輸入非合法分數（只可輸入 0~100 的整數，其餘如：1e2、50.0、13.4、abc皆為非合法輸入）時，程式會輸出錯誤訊息並結束。

## 工具準備
<li>安裝 GNU make：</li>

```bash
sudo apt-get install make
```
查看是否已安裝： ```make -v```

<li>安裝 OpenJDK：</li>

```bash
sudo apt-get install openjdk-11-jdk
```
查看是否已安裝：```java -version```

<li>安裝 g++：</li>

```bash
sudo apt-get install g++
```
查看是否已安裝：```g++ –version```

<li>安裝 Python：

```bash
sudo apt-get install python3.7
```
查看是否已安裝：```python3 --version```

## 編譯
提供`makefile`進行編譯，進入專案目錄並輸入以下指令：
```bash
make
```

## 清理環境
清理建置過程中所生成的檔案
```bash
make clean
```

## 執行
根據不同的程式語言，使用以下指令執行程式：
<li>JAVA</li>

```bash
java -cp . Average
```
<li>C++</li>

```bash
./Average.out
```
<li>Python</li>

```bash
python3 Average.py
```