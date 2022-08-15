// https://school.programmers.co.kr/learn/courses/30/lessons/42578

const solution = (clothes) =>
  Object.values(clothes.reduce(($, [_, c]) => ({ ...$, [c]: $[c] ? $[c] + 1 : 1 }), {})).reduce(($, _) => $ * (_ + 1), 1) - 1;
