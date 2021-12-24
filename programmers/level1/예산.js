// https://programmers.co.kr/learn/courses/30/lessons/12982

const solution = (d, b, s = 0) =>
  d
    .sort(($, _) => $ - _)
    .reduce((a, v) => {
      s += v;
      return a + (s <= b ? 1 : 0);
    }, 0);
