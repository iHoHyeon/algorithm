// https://school.programmers.co.kr/learn/courses/30/lessons/131701

function solution(elements) {
  const { length: len } = elements;
  const ctsSumSet = new Set();

  const extendedElements = [...elements, ...elements];

  for (let i = 0; i < len; i++) {
    let sum = 0;
    for (let j = 0; j < len; j++) {
      sum += extendedElements[i + j];
      ctsSumSet.add(sum);
    }
  }

  return ctsSumSet.size;
}

/*
    Set을 활용한 브루트포스
 */
