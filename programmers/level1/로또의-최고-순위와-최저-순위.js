// https://programmers.co.kr/learn/courses/30/lessons/77484

const solution = (_, $) =>
  _.reduce(([i, j], e) => [i + ($.includes(e) || !e ? 0 : 1), j - ($.includes(e) ? 1 : 0)], [1, 7]).map((e) => Math.min(e, 6));
