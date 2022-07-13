// https://school.programmers.co.kr/learn/courses/30/lessons/42746

function solution(numbers) {
  const res = numbers.map((v) => v.toString()).sort((a, b) => b + a - (a + b));

  const ret = res.join('');

  if (Number(ret) === 0) return '0';

  return ret;
}
