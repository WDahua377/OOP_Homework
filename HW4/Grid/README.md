## 程式目的
模擬一個具有 mover 的網格，支持移動、放置障礙物、檢查前方和右方是否有障礙、撿起物品、拓展網格等操作，mover 初始化位置隨機。

### 符號說明
* mover：`>` 為面向東方的 mover，而箭頭指向的位置隨 mover 面向方位的不同做更改，如：`<`、`Λ`、`V`。
* obstacle：`#` 表示該格具有障礙物，無法移動至此處。
* item：`0` 表示該格具有可被 mover 撿起的物品。
* `@` 表示 mover 與 item 同時在該網格內。

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
