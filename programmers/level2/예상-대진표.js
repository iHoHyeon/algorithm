// https://school.programmers.co.kr/learn/courses/30/lessons/12985

function solution(n, a, b) {
  let cnt = 1;

  while (Math.min(a, b) % 2 === 0 || Math.abs(a - b) !== 1) {
    a = Math.floor((a + 1) / 2);
    b = Math.floor((b + 1) / 2);
    cnt++;
  }

  return cnt;
}

/*
  a, b의 번호가 1차이나는 순간까지 라운드를 갱신해준다.

  단, 1이 차이나는 경우 둘 중에 작은 수가 홀수여야 둘의 대진이 성사된 것이므로 
  체크 필요

*/
