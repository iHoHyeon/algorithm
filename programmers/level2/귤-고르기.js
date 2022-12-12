// https://school.programmers.co.kr/learn/courses/30/lessons/138476

function solution(k, tangerine) {
  const numberMap = new Map();

  tangerine.forEach((t) => {
    if (numberMap.has(t)) numberMap.set(t, numberMap.get(t) + 1);
    else numberMap.set(t, 1);
  });

  const numberList = Array.from(numberMap.values()).sort((a, b) => a - b);

  console.log(numberList);
  let answer = 0;

  while (k > 0) {
    answer++;
    k -= numberList.pop();
  }

  return answer;
}
