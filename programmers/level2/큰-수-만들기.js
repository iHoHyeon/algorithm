// https://school.programmers.co.kr/learn/courses/30/lessons/42883

function solution(number, k) {
  const n = [...number].map((v) => parseInt(v));
  const len = n.length;

  let now = k;

  const res = [];

  for (let i = 0; i < len; i++) {
    const nowNumber = n[i];

    while (now > 0 && res[res.length - 1] < nowNumber) {
      res.pop();
      now--;
    }
    res.push(nowNumber);
  }

  res.splice(res.length - now, now);

  return res.join('');
}
