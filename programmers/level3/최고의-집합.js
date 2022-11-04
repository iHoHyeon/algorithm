// https://school.programmers.co.kr/learn/courses/30/lessons/12938

function solution(n, s) {
  if (n > s) return [-1];

  const avg = Math.round(s / n);

  const avg_list = new Array(n).fill().map(() => avg);
  let answer;

  if (avg * n > s) {
    answer = avg_list.map((v, idx) => (idx < avg * n - s ? v - 1 : v));
  } else {
    answer = avg_list.map((v, idx) => (idx >= n - (s - avg * n) ? v + 1 : v));
  }

  return answer;
}

/*

    평균으로 list를 채운 후, list의 합이 s와 같도록 원소의 크기를 1씩 조정

*/
