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
[ ! -f ./inp0.txt ] && echo "\033[93mThere is no input files \033[0m" && exit 

# Grabing all the input test cases and start executing
echo "\033[36mExecuting... \033[0m"
inputFiles=(`ls inp*.txt`)

successfullyPassed=1

# Running program on all test cases
for(( i=0; i<${#inputFiles[@]}; i++ ))
do
  start=`gdate +%s.%N`
  gtimeout $timeoutVal ./a.out < inp$i.txt > yout$i.txt

  # Checking if program exceed given time interval or not
  if [ $? -eq 124 ]
  then
    echo "\033[31mTime out on test case $i. This might be runtime error or a slow program\033[0m"
    successfullyPassed=0
  else
    end=`gdate +%s.%N`
    runtime=$(echo "$end - $start" | bc)  
    echo "\033[36mSuccessfully\033[0m run on \t\033[33mTestcase: $i \033[0m \t Time taken: $runtime seconds"
  fi
done

if [ $successfullyPassed -eq 1 ]
then
  echo "\033[32mSuccessfully Executed on all test cases \033[0m"
else
  echo "\033[31mFailed to run on all test cases\033[0m"
fi
echo "\n\033[93mComparing your answer with the testcases\033[0m"
cd ..
./diff.sh $1
cd ..
