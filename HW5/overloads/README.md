## 程式目的
### Cube
* Cube class 中含有三個變數，為立方體的長、寬和高。
* Overloads operator '/' 和 '!='
  1. '/' 將前者 'Cube' object 的三個變數總和除以後者 'Cube' object的三個變數總和。
  2. '!=' 檢查兩個 'Cube' object 的體積是否相同。

### Time
* Time class 以`days`、`hours`、`minutes`和`seconds`儲存時間並具有基本計算功能，宣告時與計算的結果都將自動換算為最簡化的格式並且不可為負。
* Overloads basic operators，包含 '+'、'-'、'!='、'=='、'>='、'<='、'>'、'<'、'++' 與 '--' (both pre- and post- forms)，其中 '++' 與 '--' 的功能是增加 1 秒。
