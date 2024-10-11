## 程式目的
### Cube
<li>Cube class 中含有三個變數，為立方體的長、寬和高。</li>
<li>Overloads operator <code>/</code> 和 <code>!=</code></li>

1. <code>/</code> 將前者 Cube object 的三個變數總和除以後者 Cube object 的三個變數總和。
2. <code>!=</code> 檢查兩個 Cube object 的體積是否相同。

### Time
<li>Time class 以<code>days</code>、<code>hours</code>、<code>minutes</code>和<code>seconds</code>儲存時間並具有基本計算功能，宣告時與計算的結果都將自動換算為最簡化的格式並且不可為負。</li>
<li>Overloads basic operators，包含 <code>+</code>、<code>-</code>、<code>!=</code>、<code>==</code>、<code>>=</code>、<code><=</code>、<code>></code>、<code><</code>、<code>++</code> 與 <code>--</code> (both pre- and post- forms)，其中 <code>++</code> 與 <code>--</code> 的功能是增加 1 秒。</li>

## 工具準備
<li>安裝 GNU make：</li>

```bash
sudo apt-get install make
```
查看是否已安裝： ```make -v```

<li>安裝 g++：</li>

```bash
sudo apt-get install g++
```
查看是否已安裝：```g++ –version```

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

```bash
./test1.out
./test2.out
```