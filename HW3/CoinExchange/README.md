## 程式目的
將輸入的美元值以最大面額為基準，分解成對應的硬幣組合：quarters(25分)、dimes(10分)、nickels(5分)和 pennies(1分)。
輸入為字串時將顯示為0，若為字串 + 數字的組合，則以從左到右讀取到的為準，如：1.22abc將讀取為1.22，3.a24將讀取為3.00

## 錯誤處理
<li>檢查輸入是否為負數，若為負數則輸出錯誤訊息並退出。</li>
<li>檢查小數部分的長度，若超過兩位，即小於最小單位 cent ，將判定輸入不正確，則輸出錯誤訊息並退出。</li>

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
./CoinExchange.out
```