const axios = require('axios');
const cheerio = require('cheerio');
const fs = require('fs');
const template = fs.readFileSync(__dirname + '/template.cpp');

const contestURL = 'http://codeforces.com/contest/1331';

questionsList = async (url) => {
  try{
    const html = await axios.get(url).then((response) => response.data);
    const $ = cheerio.load(html);
    let lstOfProblem = [];
    $('tbody tr .id a').each(function(i, elem){
      lstOfProblem.push($(this).attr('href'));
    })
    return lstOfProblem;
  }  
  catch(error){
    console.error(error);
  }
}

createFile = (path, data) => {
  try{
    fs.writeFile(path, data, (error) => {
      if(error) throw error;
    })
  }
  catch(error){  console.error(error);}
}

problemDirectory = async (url) => {
  try{
    const html = await axios.get(url).then((response) => response.data);
    const $ = cheerio.load(html);
    const problemName = url.slice(-1);
    const inputTestCases = $('.sample-test .input');
    const outputTestCases = $('.sample-test .output');    
    fs.mkdir(__dirname+'/'+problemName, (error)=>{
      if(error) throw error;
      inputTestCases.each(function(i, elem){  createFile(__dirname+'/'+problemName + '/inp' + i + '.txt', $(this).find('pre').text())});
      outputTestCases.each(function(i, elem){ createFile(__dirname+'/'+problemName + '/out' + i + '.txt', $(this).find('pre').text())});
      createFile(__dirname+'/'+problemName + '/solution.cpp', template);
    });
    console.log(`Problem: ${problemName} \t Test Cases: ${inputTestCases.length}`);
  }
  catch(error){ console.error(error);
  }
}

solution = async () => {
  const questionsURL = await questionsList(contestURL);  
  questionsURL.forEach(async elem => {
    await problemDirectory('http://codeforces.com' + elem);
  })
}

solution();