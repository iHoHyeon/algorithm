// https://school.programmers.co.kr/learn/courses/30/lessons/12981

function solution(n, words) {
  const wordSet = new Set();

  let now = [...words[0]][0];

  for (let round = 0; round < words.length / n; round++) {
    for (let person = 0; person < n; person++) {
      const word = words[round * n + person];
      const start = [...word][0];

      if (start !== now) {
        return [person + 1, round + 1];
      }

      if (wordSet.has(word)) {
        return [person + 1, round + 1];
      }

      wordSet.add(word);

      now = [...word].pop();
    }
  }

  return [0, 0];
}
