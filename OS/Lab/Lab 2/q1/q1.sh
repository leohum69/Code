#!/bin/bash
touch FROM.txt
touch TO.txt
echo My name is Mirza Humayun Masood, And my roll number is i221749 > FROM.txt

cp FROM.txt TO.txt
rm FROM.txt

mv TO.txt FINAL_FILE.txt

grep Humayun FINAL_FILE.txt