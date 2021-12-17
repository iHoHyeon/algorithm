// https://programmers.co.kr/learn/courses/30/lessons/12973

const solution = (s, stack = []) => {
  [...s].forEach((v) => (v === stack[stack.length - 1] ? stack.pop() : stack.push(v)));
  return stack.length ? 0 : 1;
};

/*
  stack 문제
  string을 하나씩 순회하면서 짝이 이루어지면 pop, 아니면 push하고를 반복,

  결과적으로 stack이 비어있으면 가능, 아니라면 불가능

  ## 자바스크립트의 String은 iterable을 가지고 있다. => for of 로 순회가능

*/
