// https://programmers.co.kr/learn/courses/30/lessons/76501

const solution = (a, s) => a.reduce((a, v, i) => a + (s[i] ? v : -v), 0);
