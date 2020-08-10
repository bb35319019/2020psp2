# 課題4 レポート

bb35319019 木村祥大

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

l26~39 性別と身長がもともと入っていたファイルから構造体内に格納。
l45~54 IDがもともと入っていたファイルから構造体内に格納。
l55~79 IDを聞きもしデータがあるなら性別と身長を表示しなければNo Dateと表示する。

## 入出力結果

input the filename of sample heights ?:../sample/heights.csv
the filename of sample heigths: ../sample/heights.csv
input the filename of sample ID ?:../sample/IDs.csv
the filename of sample ID: ../sample/IDs.csv
Which ID's date do you want?:45313125
---
ID:45313125
gender:Female
heights:152.40
input the filename of sample heights ?:../sample/heights.csv
the filename of sample heigths: ../sample/heights.csv
input the filename of sample ID ?:../sample/IDs.csv
the filename of sample ID: ../sample/IDs.csv
Which ID's date do you want?:71240081
---
No Date

## 修正履歴

