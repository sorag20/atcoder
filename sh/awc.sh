#! /bin/bash

if [ $# != 1 ]; then
    echo 引数は1つ必要です:
    echo 第一引数:AWCの回
    exit 0
fi

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
BASE_DIR="$(dirname "$SCRIPT_DIR")"
FOLDER="$BASE_DIR/AWC/$1"
TEMPLATE="$BASE_DIR/template.cpp"

mkdir -p $FOLDER
cd $FOLDER

# a.cpp から e.cpp までの5つのファイルを作成
for file in a.cpp b.cpp c.cpp d.cpp e.cpp
do
    cp -n "$TEMPLATE" ./$file
done

code .
