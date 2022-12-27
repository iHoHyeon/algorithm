// https://school.programmers.co.kr/learn/courses/30/lessons/84512

function* wordGenerator(chars) {
  const word = [];

  for (const c1 of chars) {
    word.push(c1);
    yield word.join('');
    for (const c2 of chars) {
      word.push(c2);
      yield word.join('');
      for (const c3 of chars) {
        word.push(c3);
        yield word.join('');
        for (const c4 of chars) {
          word.push(c4);
          yield word.join('');
          for (const c5 of chars) {
            word.push(c5);
            yield word.join('');
            word.pop();
          }
          word.pop();
        }
        word.pop();
      }
      word.pop();
    }
    word.pop();
  }
}

function solution(word) {
  const vowels = ['A', 'E', 'I', 'O', 'U'];

  const wordGen = wordGenerator(vowels);

  let i = 0;

  for (const cur of wordGen) {
    i++;
    if (cur === word) return i;
  }
}

/*
  완전탐색이지만 generator를 활용한 풀이
*/
