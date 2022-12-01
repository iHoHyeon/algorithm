// https://school.programmers.co.kr/learn/courses/30/lessons/87390

function solution(n, left, right) {
  const answer = [];
  let row = 0,
    col = 0;
  for (let i = left; i <= right; i++) {
    row = Math.floor(i / n);
    col = i % n;
    answer.push(Math.max(row, col) + 1);
  }
  return answer;
}

/*
    2차원 배열을 생성하면 10^14 -> 메모리 초과

    (row,col)의 값은 row와 col 중 큰 값 + 1 임을 이용해서 풀이

*/
