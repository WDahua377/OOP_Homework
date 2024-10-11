### 中正大學資工系選修課程 Object-Oriented Programming 的六次作業
本課程著重於介紹物件導向設計的概念，並使用 C++ 實作簡易程式。

1. AverageCalculator：讀取輸入並計算平均
   * 熟悉 OOP 語言：C++, java, Python

2. CreditCardValidation：判斷信用卡號合法性、生成合法卡號
   * 模組化程式碼，以較短的`main`函式與多個 function 組成

3. CoinExchange：計算零錢兌換數量
   * 學習建立 class 與 constructor
   * 在 constuctor 中對變數進行基本處理
   * 使用多個 inline 函數提高效能

4. Grid：模擬可進行互動的平面網格
   * 撰寫 header file
   * 將變數設為 private，僅由 public interface 操作
   * 使每個 member function 功能單一簡單

5. Overloads：Cube 含有變數長、寬、高，Time 含有變數`days`、`hours`、`minutes`和`seconds`，程式 overloads 兩種 class 的基本運算子
   * 一次 overloads 的練習

6. Blackjack：模擬撲克牌遊戲 Blackjack（21 點）
   * 分出多種 class 並學習讓 class 之間的資訊互通
   * 學習繼承（Inheritance），`Human`、`Meek`、`Random`和`Dealer`皆是繼承`Player`
   * virtual function 與 overriding：學習 overriding，在 sub class 中定義了各自的`strategy()`
