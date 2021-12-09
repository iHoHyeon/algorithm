// https://programmers.co.kr/learn/courses/30/lessons/12935

const solution = (a) =>
  a
    .splice(a.reduce((c, v, i) => (c[1] > v ? [i, v] : c), [0, Infinity])[0], 1)
    .slice(0, 1)
    .reduce((c) => (c.length ? c : [-1]), a);
