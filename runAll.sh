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

# Checking if the question has test cases or not
[ ! -f ./inp0.txt ] && echo "\033[93mThere is no input files \033[0m" && exit || echo "We have following input test cases file \n$(ls inp*.txt)"

# Grabing all the input test cases and start executing
echo "\033[36mExecuting... \033[0m"
inputFiles=(`ls inp*.txt`)

successfullyPassed=1

# Running program on all test cases
for(( i=0; i<${#inputFiles[@]}; i++ ))
do
  gtimeout $timeoutVal ./a.out < inp$i.txt > yout$i.txt

  # Checking if program exceed given time interval or not
  if [ $? -eq 124 ]
  then
    echo "\033[31mTime out on test case $i. This might be runtime error or a slow program\033[0m"
    successfullyPassed=0
  else
    echo "\033[36mSuccessfully run on testcase $i \033[0m"
  fi
done

if [ $successfullyPassed -eq 1 ]
then
  echo "\033[32mSuccessfully Executed on all test cases \033[0m"
else
  echo "\033[31mFailed to run on all test cases\033[0m"
fi