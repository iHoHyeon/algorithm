// https://school.programmers.co.kr/learn/courses/30/lessons/12927

function solution(n, works) {
  if (works.reduce((a, b) => a + b, 0) <= n) return 0;

  works.sort((a, b) => b - a);

  while (n) {
    const max = works[0];

    for (let i = 0; i < works.length && n; i++) works[i] >= max && (works[i]--, n--);
  }

  return works.reduce((a, b) => a + b ** 2, 0);
}
