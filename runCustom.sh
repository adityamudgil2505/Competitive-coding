#!/bin/bash
compiledFile="./a.out"
timeoutVal=3
cp customInput.txt  ./$1/customInput.txt
cd ./$1

# Deleting previous executable file (if exists)
echo "\033[93mDeleting a.out file if exist \033[0m"
rm -rf $compiledFile
rm -rf customOutput.txt

# Compiling starts
echo "\033[36mCompiling... \033[0m"
g++ -std=c++17 solution.cpp

# Checking if successfully compilied or not
[ ! -f "$compiledFile" ] && echo "\033[31mCompiler Error \033[0m" && exit || echo "\033[32mSuccessfully Complied \033[0m"

start=`gdate +%s.%N`
gtimeout $timeoutVal ./a.out < customInput.txt > customOutput.txt
# Checking if program exceed given time interval or not
if [ $? -eq 124 ]
then
  echo "\033[31mTime out on custom input testcase. This might be runtime error or a slow program\033[0m"
else
  end=`gdate +%s.%N`
  runtime=$(echo "$end - $start" | bc)  
  echo "\033[36mSuccessfully\033[0m run on \t\033[33mCustom Testcase \033[0m \t Time taken: $runtime seconds"
fi
cd ../
cp ./$1/customOutput.txt customOutput.txt