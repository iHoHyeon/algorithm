// https://school.programmers.co.kr/learn/courses/30/lessons/12909

function solution(s) {
  let stackNum = 0;

  for (const char of s) {
    char === '(' ? stackNum++ : stackNum--;

    if (stackNum < 0) return false;
  }

  return stackNum === 0;
}
