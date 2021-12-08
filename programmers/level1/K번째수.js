// https://programmers.co.kr/learn/courses/30/lessons/42748
const solution = (array, commands) => commands.map(([i, j, k]) => array.slice(i - 1, j).sort((a, b) => a - b)[k - 1]);
