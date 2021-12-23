// https://programmers.co.kr/learn/courses/30/lessons/77884

const squareNums = new Set(new Array(33).fill().map((v, i) => i * i));

const solution = (l, r) => {
  let ans = 0;
  for (let i = l; i <= r; i++) {
    ans += squareNums.has(i) ? -i : i;
  }
  return ans;
};
