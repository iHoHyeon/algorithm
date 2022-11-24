// https://school.programmers.co.kr/learn/courses/30/lessons/76502

const MAPPING = {
  '[': ']',
  '{': '}',
  '(': ')',
};

function isCorrect(s) {
  const stack = [];

  for (const w of s) {
    if (MAPPING[stack?.[stack.length - 1]] === w) {
      stack.pop();
    } else {
      stack.push(w);
    }
  }

  return stack.length === 0;
}

function solution(s) {
  const listS = [...s];
  let cnt = 0;
  for (let i = 0; i < s.length; i++) {
    listS.push(listS[i]);
    if (isCorrect(listS.slice(i + 1, listS.length))) {
      cnt++;
    }
  }

  return cnt;
}
