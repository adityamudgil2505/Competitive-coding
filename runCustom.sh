#!/bin/bash
compiledFile="./a.out"
timeoutVal=3
cd ./$1

# Deleting previous executable file (if exists)
echo "\033[93mDeleting a.out file if exist \033[0m"
rm -rf $compiledFile

# Compiling starts
echo "\033[36mCompiling... \033[0m"
g++ -std=c++17 solution.cpp

# Checking if successfully compilied or not
[ ! -f "$compiledFile" ] && echo "\033[31mCompiler Error \033[0m" && exit || echo "\033[32mSuccessfully Complied \033[0m"

gtimeout $timeoutVal ./a.out < customInput.txt > customOutput.txt
# Checking if program exceed given time interval or not
if [ $? -eq 124 ]
then
  echo "\033[31mTime out on custom input testcase. This might be runtime error or a slow program\033[0m"
else
  echo "\033[32mSuccessfully run on custom testcase $i \033[0m"
fi