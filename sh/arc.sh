#! /bin/bash

cd ~/AtCoder/
if [ $# != 2 ]; then
    echo 引数は２つ必要です: 
    echo 第一引数:ABCの回
    echo 第二引数:ファイル名
    exit 0
fi
FOLDER="/Users/sorag/dev/AtCoder/ARC/$1"
FILE=${2%.*}.cpp
mkdir -p $FOLDER
cd $FOLDER
cp -n ../../template.cpp ./$FILE
code $FILE