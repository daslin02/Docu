#!/bin/bash


# Проверка наличия папки linux-convertor

if [ -d "script/linux-convertor" ]; then
    cp -r script/linux-convertor build/
    echo "dorectorie linux-convertor move в build."
else
    echo "linux-convertor not found."
fi

