libraries for Esenthel Engine
========
### 作ったら載せていくところ
========
#### letter.cpp:任意のテクスチャの内容を指定した位置に表示  
  
* Init()の中で  
  
    letter = new Letter(テクスチャのUID, 表示領域の幅, 表示領域の高さ);  
  
* Render()の中で  
  
    letter.draw(VecI2(0, 1), 文字番号);  
  
    位置は、左上を(0,0)としてVec2Iで指定  
    文字番号は、テクスチャ内のどの位置を表示するかの指定  
    (エラーチェックしてません)  

***
