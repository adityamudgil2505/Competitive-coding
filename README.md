# Competitive-coding Bot
This bot will help you to easily set up a competitive coding platform for CodeForces. This bot will be helpful for both live contests as well as for practice.

## Features:
- Help to manage the directory as well as a test case for each test case for a contest using only a single command.
- Help to easily work on a custom test cases.
- Compile and run on all the test cases using single command.
- Compare your output with the expected output.

## Limitation
- Language: C++
- Coding Plateform: Codeforces.

## Skills used
- NodeJS
- Shell

## How to setup this bot
1. Install nodejs. [https://nodejs.org/en/download/]
2. Check if nodejs and npm install properly using `node --version` and `npm --version`

3. Now Download the package from the [release](https://github.com/adityamudgil2505/Competitive-coding/releases). 
4. Go open the directory in any text editor (Recommend Sublime Text Editor).
5. Install `npm install`.
6. You can edit template.cpp according to your needs.
7. You have successfully set up the bot.

## How to use
1. Open the directory in Sublime Text Editor.
2. Open 'script.js' file and enter the contest link in variable name contestURL like this
`const contestURL = 'http://codeforces.com/contest/1328';`

3. Open the terminal inside sublime text editor (you need to install Terminus package, this will be helpful).
4. Run the following command in the terminal `node script`. This will create all the directory and download the test cases.
5. Open customInput.txt and customOutput.txt along with solution.cpp of any of these newly created folders ie, A, B, ...
6. Now write your code in solution.cpp
7. Now to run this, we have two options:
- To run code on custom test case `sh run.sh <ProblemName> c` example `sh run.sh A c`
- To run code on all test cases `sh run.sh <ProblemName>` example `sh run.sh A`
8. The difference between your output and expected output will be shown in the terminal. To navigate between files, press `gt` in terminal. Next enter command `:qa` to proceed forward.


## How to reuse this bot
1. Open the directory in Sublime Text Editor.
2. Open the terminal inside sublime text editor (you need to install Terminus package, this will be helpful).
3. Run the following command `rm -rf {A..Z}`
4. Edit contest URL in script.js file `const contestURL = 'http://codeforces.com/contest/1328';`
5. Run the following command `node script`

### Screenshots
Overview
![alt Overview](/screenshots/Overview.png)
Running code on all test cases


![alt Running code on test cases](/screenshots/Execution.png)



Comparing your output with actual output

![alt Comparing output](/screenshots/Comparing.png)
