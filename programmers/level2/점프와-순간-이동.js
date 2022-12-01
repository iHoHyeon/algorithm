// https://school.programmers.co.kr/learn/courses/30/lessons/12980

function solution(n) {
  let ans = 0;
  while (n) {
    n % 2 ? (n--, ans++) : (n /= 2);
  }

  return ans;
}

/*
  n에서 0으로 가는 문제로 치환

  이진수로 변환했을 때 1의 개수를 구하는 문제로도 치환 가능..
*/
