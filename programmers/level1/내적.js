// https://programmers.co.kr/learn/courses/30/lessons/70128

const solution = (a, b) => a.reduce((a, v, i) => a + v * b[i], 0);
